#include <iostream>
using namespace std;

class singleton{
    singleton(){
        cout<<"Called singleton getInstance"<<endl;
    }
    static singleton* instance; //instance of the point
    static int refCount; 
    public:
    static singleton getInstance(){
        cout<<"Called singleton getInstance"<<endl;

        if(!instance){
            instance = new singleton;
            refCount++;
            cout<<"Holding the reference: "<<refCount<<endl;
        }
        refCount++;
        cout<<"Holding the reference: "<<refCount<<endl;
        return *instance;
    }

};

singleton* singleton::instance = nullptr;
int singleton::refCount = 0;

int main(int args, const char* argv[]){
    //singleton* s= new singleton(); private constructor
    //singleton::getInstance(); if void
    singleton singleton1 = singleton::getInstance();
    return 0;
}