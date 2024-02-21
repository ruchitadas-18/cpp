#include <iostream>

using namespace std;

class iotSensors{
    public:
    int checkWheel[6];
    int wheel_airPressure = 10;
    int observationWheel;
    iotSensors():observationWheel(1){}
    virtual void dataWheel(int obs) =0;
};

class wheel: public iotSensors{
    public:
    void dataWheel(int obs) override{
        if(wheel1(obs) && obs<6){
            checkWheel[++observationWheel] = obs;
            cout<<"Wheel status: "<<checkWheel[observationWheel]<<endl;
        }

    }
    bool wheel1(int numWheel){
        if(numWheel<4){
            return true;
        }else if(numWheel>4){
            return false;
        }else{
            return true;
        }
    }
};


int main(){
    //Inheritance
    wheel sensors;
    sensors.dataWheel(2);
    sensors.dataWheel(1);
    sensors.dataWheel(3);
    sensors.dataWheel(9);
    sensors.dataWheel(4);
    sensors.dataWheel(4);
    sensors.dataWheel(4);

    return 0;
}