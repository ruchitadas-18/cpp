#include <iostream>
#include <mutex>

class Singleton{
    Singleton(){}
    static std::once_flag flag; //thread by itself
    static Singleton* instance_; //
    public:
    static Singleton& getInstance(){  //
        std::call_once(flag, [](){std::cout<<"Hii i am in Singleton"<<std::endl;instance_ = new Singleton;}); //unique 
        return *instance_;
    }
   
};

Singleton* Singleton::instance_ = nullptr;
std::once_flag Singleton::flag;

int main(){
    std::cout<<"Singleton once_flag!!"<<std::endl;

    Singleton& s1 = s1.getInstance();
    Singleton& s2 = s2.getInstance();

    if(&s1 == &s2){
        std::cout<<"Singleton works"<<std::endl;
    }
}