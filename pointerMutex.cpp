// #include <iostream>
// #include <vector>

// int main(){
//     int a = 10;
//     int b = 20;
//     int c = 30;
//     int d = 40;

//     std::vector<std::reference_wrapper<int>> vectPtr{a,b,c};

//     for(auto ptr: vectPtr){
//         ptr.get() += 5;
//         std::cout<<ptr.get()<<std::endl;
//     }

//     return 0;
// }

#include<iostream>
#include <future>
#include <thread>
#include <chrono>
#include <mutex>

int myCash = 0;
std::mutex m;

void addMoney(){
    m.lock();
        ++myCash;
    m.unlock();
}

int main(){
    std::thread t1(addMoney);
    std::thread t2(addMoney);

    t1.join();
    t2.join();
}