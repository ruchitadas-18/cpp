//it is working
#include<iostream>
using namespace std;
 
template<float fuel>
 
float pump(float additionalOil) requires( fuel >= 10 )
{
    // constexpr
    float minFuel = 10.0f ;
    if( fuel + additionalOil < minFuel ){
        throw std::runtime_error("Car would stop any min!!");
    }
    return fuel + additionalOil;
}
 
int main(){
    try{
        //19 is value for template and 20 is the value for pump
        cout<<"Pump : "<<pump<12.00f>(20.00f)<<endl;
    }catch(const std::runtime_error(& e)){
        cout<<"Exception : "<<e.what()<<endl;
    }
    cout<<"End of the code "<<endl;
    return 0;
}