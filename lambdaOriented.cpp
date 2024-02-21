#include <iostream>
using namespace std;

int main(){
    const auto print = [](const char* str, int x, int y){
        cout<<str<<" "<<x<<" "<<y<<endl;
    };

    int x=1, y=1;

    print("In main...",x,y); //official api

    auto foo=[x,y,&print]()mutable{
        ++x;
        ++y;
        print("In foo()", x,y);
    };
    foo;
    print("In foo()",x,y);
}