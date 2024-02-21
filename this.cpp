//lambda and concept requries
//forward 
#include <iostream>
#include <memory>
using namespace std;

//Phase I
class MyClass2{
    public:
    void printFromMyClass2(){
        std::cout<<"Hello I am in MyClass 2!!"<< std::endl;
    }
};

class MyClass : public std::enable_shared_from_this<MyClass>{
    int var;
    public: 
    MyClass2 myclass;
    std::shared_ptr<MyClass> getShared(){
        return shared_from_this();
    }

    void print(){

        std::cout << " Hello I am in Myclass!! "<<std::endl;
    }

    int setVar(int v){
        var = v;
        return var;
    }
};

int main(){

    std::cout<<"Enable shared pointer..."<<std::endl;

    std::shared_ptr<MyClass> obj = std::make_shared<MyClass>();
    std::shared_ptr<MyClass> sharedObject = obj -> getShared();
    sharedObject->print();
    std:cout<<sharedObject -> setVar(45);
    sharedObject -> myclass.printFromMyClass2();
}