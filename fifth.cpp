#include <iostream>
#include <vector>
#include <variant>

using namespace std;

using var_t = std::variant<int,const char*>;

template<class... Ts>
struct print : Ts...{
    using Ts::operator()... ;
};
 
template <class... Ts>
auto makePrint(Ts... ts){
    return print<Ts...>{ts...};
} 
 
int main(){
    std::cout<< "Lambda overload!\n";
    std::vector<var_t> vars = { 1,2,"Hello world"};

 
    for ( auto& v : vars)
    {
        std::visit(
            makePrint(
                    [](int i ){ cout << i << endl;},
                    [](const char* str){ cout << str << endl;}
                ),v );
    }
    return 0;
}