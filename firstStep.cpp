#include <iostream>
#include <vector>
#include <variant>

using namespace std;

using var_t = std::variant<int,const char*>;

struct print{
    void operator()(int i){
        cout<< i<<endl;
    }
    void operator()(const char* str){
        cout<< str<<endl;
    }
};


int main(){
    cout<<"Lambda Overloading!!!"<<endl;
    vector<var_t> vars = {1,3,4,"rucnek","rtgnhces"};

    for (auto& a: vars){
        std::visit(print{},a); //aggreate 
    }

    return 0;
}