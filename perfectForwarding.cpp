#include <iostream>
using namespace std;

void funda(int&& avg){
    cout<<"R value"<<avg<<endl;
}

void funda(int& avg){
    cout<<"L value"<<avg<<endl;
}


//removing the wraping
template<typename T>
T my_forwarding(typename std::remove_reference<T>::type& param){
    return static_cast<T>(param);
}

template<typename T>
void call_funda(T&& parg){
    funda(my_forwarding<T>(parg));
    funda(std::forward<T>(parg));
}

int main(){
    int myVar = 5;
    call_funda(myVar);
    call_funda(4);
    return 0;
}
