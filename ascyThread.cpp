#include<iostream>
#include <future>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std::chrono;

typedef long ull;


ull findEven(ull start, ull end){
    std::cout<<"Find Even Async Thread Id: "<<std::this_thread::get_id()<<std::endl;
    return end;
}

ull findOdd(ull start, ull end){
    std::cout<<"Find Even Async Thread Id: "<<std::this_thread::get_id()<<std::endl;
    return end;
}

int main(){
    ull start =0;
    ull end = 1900000000; 

    auto startTime = high_resolution_clock::now();
    std::cout<<"Main Async Thread Id: "<<std::this_thread::get_id()<<std::endl;

    //future with async
    std::future <ull> evenSum = std::async(std::launch::async, findEven, start, end);
    std::future <ull> oddSum = std::async(std::launch::async, findOdd, start, end);

    // //future with deferred
    // std::future <ull> evenSum = std::deferred(std::launch::async, findEven, start, end);
    // std::future <ull> oddSum = std::deferred(std::launch::async, findOdd, start, end);

    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);

    std::cout<<"sec: "<<duration.count()/1000000 <<std::endl;
    
}