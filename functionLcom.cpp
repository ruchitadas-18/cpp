// function compositon can take lambda, class, int it
 
#include<bits/stdc++.h>
#include<string_view>
#include<functional>
#include<algorithm>
#include<array>
#include<iostream>
 
using namespace std;
 
int main(){
    std::array<int,10> s = {5,7,4,2,8,6,1,9,0,3};
    auto print = [&s](std::string_view const rem){
        //&s is used to get reference to s array
        for(auto a : s){
            cout<<a<<" ";
        }
        cout<< " : " << rem<<endl;
    };
 
    std::sort(s.begin(), s.end());
    print("Sorted with default operator < ");
 
    std::sort(s.begin(), s.end(), std::greater<int>());
    print("Sorted with greater ");

    struct {
        bool operator()(int a, int b)const{ return a>b;}
    }customLess;

    std::sort(s.begin(), s.end(),customLess);
    print("Sorted with struct");

    std::sort(s.begin(), s.end(),[](int a, int b){
        return a<b;
    });
    print("Sorted with lambda");
 
    
    return 0;
 
}