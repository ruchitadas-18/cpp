#include<iostream>
using namespace std;
 
class Animal{
    public:
        virtual void fun() = 0;
};
 
class Dog:public Animal{
    int a = 23;
    public:
        void fun() override{
 
            cout<<"This is Dog fun"<<endl;
        }

        Dog getptr(){
            return *this;
        }
};
 
int main(){
    
    Dog obj;
    obj.getptr();
 
    return 0;
}