#include <iostream>
#include <memory>

class A; class B;

class A{
    public:
    std::shared_ptr<B> pointer;

    A(){
        std::cout<<"you are in A constructor"<<std::endl;
    }
    ~A(){
        std::cout<<"you are in A destructor"<<std::endl;
    }
};

class B{
    public:
    std::shared_ptr<A> pointer;

    B(){
        std::cout<<"you are in B constructor"<<std::endl;
    }
    ~B(){
        std::cout<<"you are in B destructor"<<std::endl;
    }
};

int main(){
    std::shared_ptr<A> a = std::make_shared< A >();
    std::shared_ptr<B> b = std::make_shared< B >();

    a->pointer = b;
   // b->pointer = a;  //deadlock condition

}