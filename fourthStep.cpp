#include <iostream>
#include <vector>
#include <variant>

using namespace std;

using var_t = std::variant<int,const char*>;

template<class... Ts>
struct Print : Ts...{
    using Ts::operator()... ;
};
 
 
int main(){
    std::cout<< "Lambda overload!\n";
    std::vector<var_t> vars = { 1,2,"Hello world"};
 
    auto PrintInt = [](int i ){ cout << i << endl;};
    auto PrintString = [](const char* str){ cout << str << endl;};
 
    for ( auto& v : vars)
    {
        std::visit(
                    Print<decltype( PrintString), decltype(PrintInt)>
                             { PrintString, PrintInt },
                    v );
    }
    return 0;
}