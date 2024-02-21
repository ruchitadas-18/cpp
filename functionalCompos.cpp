//lvalue
#include <iostream>
#include <type_traits>
#include <functional>

using namespace std::placeholders;

const std::string messages = "Ruchita is good";

const std::string& foo(){ // taking the refrence value
    return messages;
} 

auto& increment(int& s){ // auto only can take refrence values
    s++;
    return s;
}


//auto limitation fulfil by decltype
struct A{
    double x;
};

const A* a;

decltype(a->x) y; //trailing datatype
decltype(a-> x) z = y; //explicit type casting to struct datatype

constexpr auto f( const float x) -> decltype(x+23.12){ // telling the compilar earlier that 
//it is going to return this type of data type
    return x+23.12;
}

auto detData() -> int (&)[2]{ // here also it is taking the reference of the array
    int arr[] ={10,20};
    return arr;
}

/*
Out dated--------- no use
act as a mediator between the function and user
function pointer -> call back or placeholder -> symbolysis (*)();
(*name_of_pointer)(arguments) = add; // providing the add address
*/
// caling the functional pointer dirtectly in the function
constexpr auto resultOfFunction(int(*Op)(int, int), int x, int y)-> decltype((*Op)(x,y)){
    return (*Op)(x,y);
}


template<typename... Args>
auto add2(Args... args) -> int {
    return (args +...);
}

template<typename FN, typename... Args>
constexpr auto resultOfFunction2(
                                const FN& Op,
                                Args... args
) -> decltype(Op(args...)){
    return Op(args...);
}

//template<typename T> // template for the struct
//struct is_variable: std::is_object<T> {}; //identify weather it is type or value
// constexpr auto resultOfFunction1(
//                                 const fn& op,
//                                 const T1 x,
//                                 const T2 y
// ) -> std::enable_if_t//identify which type of data 
// <std:: __is_invocable<fn, T1, T2>::value  //invocking the values
// // it is use to check the condition  for the given statement
// && is_variable<i>::value &&
// is_variable<j> :: value,
// decltype(op(x,y))>
// {
//     return op(x,y);
// }

template<typename T> 
struct is_variable: std::is_object<T> {};
template<typename FN, typename T1, typename T2> // template to set the type of argument 
// the function is going to take
constexpr auto resofOP2 (const FN& f, const T1 a,const T2 b) -> std::enable_if_t <
                                                                        std::__is_invocable<FN,T1,T2>::value &&
                                                                        is_variable<T1>::value &&
                                                                        is_variable<T2>::value,
                                                                        decltype(f(a,b)) >
{
    return f(a,b);
}

constexpr auto add(const int x, const int y) -> int{
    return x+y;
}

int (*MyFuncPo)(int x, int y) = add;
int main(){
    int a = 100;
    int& y = increment(a);
    std::cout<<a<<" "<<y<<std::endl;

    const auto f1 = foo();
    decltype(foo()) f2 = foo();// it will act like a inline function and get its datatype
    decltype( auto ) f3 = foo(); 
    std:: cout<<MyFuncPo(23,45)<<std::endl;
    std::cout<<resultOfFunction(add,12,34)<<std::endl;
    std::cout<<resofOP2(add,12,34)<<std::endl;
    std::cout<<resultOfFunction2(add2<int, int,int,int>,100,200,300,400)<<std::endl;
//functional compostion

    //new way to write function pointers
    std::function< int(int)> std_fun = std::bind(&add,123, _1); 
    //_1 take the value from the user and place into its place
    int sum = std_fun(111);
    std::cout<<sum;
    return 0;
}



