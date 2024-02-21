#include<iostream>
using namespace std;

template<typename Func1,typename Arg1,typename Arg2>
void call(Func1 first,Arg1 arg1,Arg2 arg2){
    first(arg1,arg2);
}
 
template<typename Func1,typename Arg1,typename Arg2,typename ... FuncRest>
void call(Func1 first,Arg1 arg1,Arg2 arg2 ,FuncRest...rest){
    first(arg1,arg2);
    call (rest...);
}

auto add(int a,int b){cout<<"Adding "<<a+b<<endl;}
auto sub(int a,int b){cout<<"Subtract "<<a-b<<endl;}
auto mul(int a,int b){cout<<"Multiply "<<a*b<<endl;}
auto divv(int a,int b){cout<<"Divide "<<a/b<<endl;}
 
 
int main(){
    call(add,12,23,sub,52,33,mul,22,53,divv,14,7);
    return 0;
}