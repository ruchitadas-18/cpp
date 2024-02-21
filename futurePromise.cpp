#include<iostream>
#include <future>
#include <thread>
#include <chrono>
#include <mutex>
#include <vector>

using namespace std;

//void threadFun(promise<int>& prom){
void threadFun(promise<int>&& prom){
    this_thread::sleep_for(chrono::seconds(3));
    prom.set_value(396);
}

int main(){
    std::cout<<"Future Promise! "<<std::endl;
    std::promise<int> myPromise;
    std::future<int> handleToFuture = myPromise.get_future();
    cout<<"Fire the thread"<<endl;
    //std::thread t1{threadFun, std::ref(myPromise)};
    std::thread t1{threadFun, std::move(myPromise)};
    cout<<"In the main"<<handleToFuture.get()<<endl;
    t1.join();
    cout<<"End of the code"<<endl;

    return 0;

}