#include <iostream>

int global = 10;
auto testSpeed = [](int speed) -> std::string{
    if(speed>100)
        return "Super Fast";
    else
        return "Composed Driver";
};

int main(){
    std::cout<< global <<std::endl;

    auto foo = [=]() mutable noexcept{++global;};
    foo();
    std::cout<<global<<std::endl;

    const auto increaseGlobal = []()noexcept{++global;};
    increaseGlobal();
    std::cout<<global<<std::endl;

    //Phase 2
    std::cout<<testSpeed(12)<<std::endl;

    return 0;
}