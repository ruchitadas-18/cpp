/*
lamba is varient of function object(operator overloading) 
[({})] --> lamba
capture list []
function (values) --> nameless lamba
trailing datatype ->

in lambsa id a const
mutable --> u can change thr values (default const lamba)
throw() -- to throw the exception
{
    int sum = x+y
}
*/

#include <iostream>
using namespace std;

class Annoymous{
    public:
    template<typename T1, typename T2>
    constexpr auto operator()(const T1 a, const T2 b){
        return a+b;
    }
};

constexpr auto sum = [](const auto& a, const auto& b){
    return a+b;
};

//vardadic 
void print(){}

template<typename First, typename ...Rest>
void print(const First& first, const Rest... args){
    cout<<first<<endl;
    print(args...);
}

//lamda
template<typename ...T>
auto doSomething(T...t){
    return(t+...);
}

constexpr auto add = [] <class... T>(T...args){
    return (args+...);
};

int main(){
    Annoymous a;
    cout<<a(10,20)<<endl;
    cout<<sum(10,20)<<endl;

    std::cout<<"Lamba"<<endl;
    //std::function<void<Args...>> vardic_lamba = [](auto... param){ print(args..);};

    auto vardic_lamba = [] (auto... param){
        print(param...);
    };
    vardic_lamba(1,"LOL",2,"KPIT");

    print(1,"LOL",2,"KPIT");

    cout<<doSomething(1,2,3,4,5,6,8,9)<<endl;
    cout<<add(1,2,3,4,5,6,8,9)<<endl;
    return 0;
    
}