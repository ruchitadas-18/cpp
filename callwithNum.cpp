#include <bits/stdc++.h>

std::function<void(int)> fun;
/*
void callwithNum(fun){
    bar(10);
}

not the write way to write it
*/
void callwithNum(void(*bar)(int)){
    bar(10);
}


int main(){
    struct{
        using f_ptr = void(*)(int);
        void operator()(int s) const {
            return call(s);
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
        }
        operator f_ptr() const {
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
            return& call;} //function pointer overloading

        private:
        static void call(int s){
            std::cout<<__PRETTY_FUNCTION__<<std::endl;
            std::cout<<s<<std::endl;
        }
    }baz;//function object structure

    callwithNum(baz); 
    
    //callwithNum([](int x){std::cout<<x<<std::endl;}); //comeback
}