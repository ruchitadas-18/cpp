#include <iostream>
#include <thread>
#include <future>
#include <functional>

enum class ThreadState{
    RUNNING, COMPLETE, ERROR
};

void run_with_callback(const std::function<void(ThreadState)>& callback){
    std::thread t([callback](){
        try{
            std::this_thread::sleep_for(std::chrono::seconds(2));
            callback(ThreadState::COMPLETE);
        }catch(...){
            callback(ThreadState::ERROR);
        }
    });

    callback(ThreadState::RUNNING);
    t.join();

}

int main(){
    std::vector<std::future<ThreadState>> futures;

    auto callBack = [](ThreadState state){
        switch(state){
            case ThreadState::RUNNING:
                std::cout<<"State is running"<<std::endl;
                break;
            
            case ThreadState::COMPLETE:
                std::cout<<"State is completed"<<std::endl;
                break;

            case ThreadState::ERROR:
                std::cout<<"Error occured"<<std::endl;
                break;
            
        }
    };

    for (int i=0; i<6; ++i){
        decltype(auto) f = std::async(std::launch::async,run_with_callback, callBack);
    }

    for(auto& f : futures){
        auto state = f.get();
        callBack(state);
    }
}
