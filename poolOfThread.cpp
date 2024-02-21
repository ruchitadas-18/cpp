#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>
#include <queue>
#include <functional>
#include <future> 

class ThreadPool{
    private:
    std::vector<std::thread> workerThreads;
    std::queue<std::function<void()>> queuedTasks;
    std::mutex queueMutex;
    std::condition_variable condition;

    bool stop;
    public:

    ThreadPool(size_t numThread): stop(false){
        for(size_t num = 0; num<numThread; num++){
            std::cout<<"----------"<<num<<" Thread Created "<<std::endl;
            workerThreads.emplace_back(
                [this]{
                    while(true){
                        std::function<void()> pullAsyncTaskFromQueueToExecute;
                        {
                            //gets fired when we are notify from the queue
                            std::unique_lock<std::mutex> lock(queueMutex);
                            condition.wait(lock,[this]{ return stop || !queuedTasks.empty();});
                            if(stop && queuedTasks.empty()) return;
                            pullAsyncTaskFromQueueToExecute = std::move(
                                queuedTasks.front()
                            ); queuedTasks.pop();
                        }
                        std::cout<<"State : Lambda is ready to execution "<<std::endl;
                        pullAsyncTaskFromQueueToExecute();
                    }
                }
            );
        }
    }

    template<typename Func, typename ...Args>
    auto enqueue (Func&& f, Args... args) -> std::future< typename 
                                            std::invoke_result<Func, Args...>::type>
    {
        using returnType = typename std::invoke_result_t<Func, Args...>;
        std::cout<<"State: Lambda invoked "<<std::endl;
        auto prepareAsyncTask = std::make_shared<std::packaged_task<returnType()>> (
            std::bind(std::forward<Func>(f), std::forward<Args>(args)...)
        );

        std::future<returnType> result = prepareAsyncTask -> get_future();
        {
            std::cout<<"State: Lambda is prepared for execution "<<std::endl;
            std::unique_lock<std::mutex> lock(queueMutex);
            if(stop)
                throw std::runtime_error("Enqueue on stoped thread pool");
            
            queuedTasks.emplace([prepareAsyncTask]{(*prepareAsyncTask)();});
            condition.notify_all();
            return result;
        }
    }
    ~ThreadPool(){
        std::unique_lock<std::mutex> lock(queueMutex);
        stop = true;

        condition.notify_all();
        for(std::thread& worker: workerThreads){
            worker.join();
        }
    }
};

int main(){
    ThreadPool pool (4);
    auto task1 = pool.enqueue([](){
        std::cout<<"Task 1 created...."<<std::endl;
    });
    auto task2 = pool.enqueue([](){
        std::cout<<"Task 2 created...."<<std::endl;
    });

    auto task3 = pool.enqueue([](int a, int b){
        std::cout<<"Task 3 executed..."<<a+b<<std::endl;},10,20);


}