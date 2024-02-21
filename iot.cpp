#include <iostream>

using namespace std;

class iotSensors {
public:
    int checkFuel[6];
    int observationFuel;
    int fuel_tank;
    iotSensors() : observationFuel(0), fuel_tank(100) {};
    void dataFuel(int obs);
};

class Fuel {
public:
    iotSensors sensors;
    Fuel(iotSensors IotS) : sensors(IotS) {}

    void dataFuel(int obs) {
        if (fuel(obs) && sensors.observationFuel < 6) {
            sensors.checkFuel[++sensors.observationFuel] = obs;
            cout << "Fuel status: " << sensors.checkFuel[sensors.observationFuel] << endl;
        }
    }

    bool fuel(int obs) {
        if (obs >= 0 && obs <= sensors.fuel_tank) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    // Composition
    iotSensors sensors;
    Fuel fuelsensor(sensors);
    fuelsensor.dataFuel(10);
    fuelsensor.dataFuel(20);
    fuelsensor.dataFuel(30);
    fuelsensor.dataFuel(40);
    fuelsensor.dataFuel(50);

    return 0;
}
