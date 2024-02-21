#include<bits/stdc++.h>
#include<string_view>
#include<functional>
#include<array>
#include<iostream>

struct Car{
    std::string make{};
    std::string model{};
};

int main(){

    std::array<Car,3> cars{{{"Volks","Golf"},
                        {"Honda","Amaze"},
                        {"Toyota","Coro"}}};

    int comparision{0};
    std::sort(cars.begin(),cars.end(),
                [&comparision](const auto& a, const auto& b){
                    ++comparision;
                    return a.make < b.make;
            });

    
    for(const auto& car: cars){
        std::cout<<car.make<<" "<<car.model<<std::endl;
    }
                    
    return 0;
}
 