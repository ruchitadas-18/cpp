#include <iostream>
#include <vector>
#include <variant>

using namespace std;

using var_t = std::variant<int,const char*>;

struct printInt{
    void operator()(int i){
        cout<< i<<endl;
    }
};

struct printChar{
    void operator()(const char* str){
        cout<< str<<endl;
    }
};

struct print: printChar, printInt{
    using printInt::operator();
    using printChar::operator();
};

int main(){
    cout<<"Lambda Overloading!!!"<<endl;
    vector<var_t> vars = {1,3,4,"rucnek","rtgnhces"};

    for (auto& a: vars){
        std::visit(print{},a); //aggreate 
    }

    return 0;
}