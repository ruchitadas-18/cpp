#include <iostream>
#include <functional>

void foo(int x, int y){
    std::cout<<"Foo"<<x<<","<<y<<std::endl;
}

class Bar{
    public:
    void bar(int x, int y){
        std::cout<<"Foo"<<x<<","<<y<<std::endl;
    }
};

int main(){
    std::invoke(foo,5,6);//calls foo(5,6)

    Bar b1;
    std::invoke(&Bar::bar, &b1, 7,8); //calls b2.bar(7,8)

    auto f1 = std::bind(foo, 1, std::placeholders::_1);

    Bar b;
    
}