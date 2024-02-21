#include <iostream>
#include <mutex>
#include <chrono>
#include <thread>

std::mutex g_mutex;
bool g_ready = false;
int g_data = 0;

int produceData(){
    int randNum = rand() %1000;
    std::cout<<"Data: "<<randNum<<std::endl;
    return randNum;
}

void consumerData(int data){
    std::cout<<"Recieve Data: "<<data<<std::endl;
}

void consumer(){
    while(true){
        std::cout<<"I am consumer function"<<std::endl;
        while(!g_ready){
            //waiting for the producer 
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
        std::unique_lock<std::mutex> ul (g_mutex);
        consumerData(g_data);
        g_ready = false;
        ul.unlock();
    }
}
void producer(){
    while(true){
        std::cout<<"I am the producer"<<std::endl;
        std::unique_lock<std::mutex> ul(g_mutex);
        g_data = produceData();
        g_ready = true;
        ul.unlock();
        while(g_ready){
            //waiting for the consumer to take the data
            std::this_thread::sleep_for(std::chrono::seconds(3));
        }
    }
}

void consumerThread(){
    consumer();
}

void producerThread(){
    producer();
}

int main(){
    std::thread t1(consumerThread);
    std::thread t2(producerThread);
    t1.join();
    t2.join();

    return 0;
}


