#include <iostream>

const double P11 = 3.123456789012;
constexpr double P12 = 3.123456789012;
//constexpr double P14 = P11; error
constexpr double P13 = P12; // const expression but const cannot be written

//since array need a constant value for its size
//so we can write as
//int i = 10; int array[i]; error...

const int a = 11; // constexpr int a = 11 is also correct
int arr[a];

/*
const int func(int x, int y){ it will show error
    return x+y+10.3f; since it carry different values as well as const
}
constexpr auto func(int x, int y){
    return x+y+13.5f;
}


constexpr auto func(int x, int y){
    return x+y;
}

const int func_const(int x, int y){
    return x+y;
}

int array[func(10,20)]; // since the expression is constant
//int array[func_const(10,20)]; error -> it is not taking the value as constant 
//even thou it is function has constant 
// int array[func(10,rand())] // it become dynamic
*/

class Test3{
    public: 
    int value;

    //functions are always dynamic in nature -> constexpr
    //when we need to fix the values  -> const
    constexpr int getValue()const{
        return value;
    }
    // constexpr constructor
    constexpr Test3(int value): value(value){}
    // if it is const type it will not able to assign values

};

constexpr Test3 test(100);//object is also constexpr type
int array[test.getValue()]; // since it is constexpr function

// template <bool useFlag>
// auto getValue(){
//     if constexpr(useFlag){ // constexpr to remove the confusion for auto deduction
//         return 2.34;
//     }else{
//         return 3;
//     }
// }

/*
Templates: 
template<typename T>  correct    template<auto T> error
auto add(Tx, Ty) / T add(Tx, ty) correct

T result = add(20,30) -> error
auto result = add(20,30) -> correct

*/
int main(){
    
    // int val = getValue<true>();
    // std::cout<<"True"<<val<<std::endl;

    // double dVal = getValue<true>();
    // std::cout<<"True"<<dVal<<std::endl;

    return 0;
}