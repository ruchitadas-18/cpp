#include <iostream>
#include <variant>
#include <vector>
#include <typeinfo>

using namespace std;

int main(){

    std::vector<std::variant<char, long, int, float, double, long long>>
        vecVarient = {'5',2,5.4,1001l,2011l, 5.5f, 2017};

    for(auto& v: vecVarient){
        //std::visit(lamdba, v);
        //           place, visitor

        std::visit([](auto arg){cout<< arg;}, v);
        std::visit([](auto arg){cout<< typeid(arg).name()<< endl;}, v);
    }
    return 0;
}

