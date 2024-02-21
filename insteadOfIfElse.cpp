//functional composition  used in sort
//gps

#include<bits/stdc++.h>
using namespace std;
 
void ForEach( const std:: vector<int> &values, void(*funPtr)(int)){
    //A service or a thread
    for(int value: values){
        cout<<"about to call lambda {}"<<endl;
        funPtr(value); //its a call back{}
    }
}
 
int main(){
    std::cout<<"Vector\n";
    std::vector<int> values = {1,2,3,4,5};
    ForEach(values, [](int value){
    cout<<"Value: "<<value<<endl;});

    if(int x = 5; x == 15){
        std::cout<<"x: "<<x<<std::endl;
    }else{
        std::cout<<"Not x: "<<x<<std::endl;
    }
 
    return 0;
}
 