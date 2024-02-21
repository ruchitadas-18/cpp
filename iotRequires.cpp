//in progress
#include <iostream>
#include <vector>
#include <concepts>

using namespace std;

class iotSensors {
public:
    vector<int> checkWheel;
    int wheel_airPressure =10;
    int numWheel;
    int observationWheel;

    iotSensors() : observationWheel(0), checkWheel(10, 0) {
        numWheel = 4;
        wheel_airPressure = 5; 
    }

    int getWheel(){
        return wheel_airPressure;
    }

};

template<int pressure>
int presure(int pressure) requires (pressure >= 10) {
    return pressure;
}

template<typename T>
concept pressureLevel = requires(T t) {
    //requires t.numWheel == 4;
    if constexpr( t.wheel_airPressure >10 ){
        {t.wheel_airPressure}; // accela// break..
    }
    // { presure<>(t.wheel_airPressure) };
};

class wheel {
public:
    template<pressureLevel T>
    int dataWheel(T& t) {
        // cout<<"Air Pressure: "<<t.wheel_airPressure <<endl;
        // cout << "Wheel status: " << t.numWheel << endl;
        return t.wheel_airPressure;
    }
};

int main() {
    iotSensors s;
    wheel sensors;
    sensors.dataWheel(s);

    return 0;
}