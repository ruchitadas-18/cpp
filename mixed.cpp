#include <iostream>
#include <memory>
#include <vector>
#include <chrono>
#include <thread>
#include <mutex>
#include <random>
#include <future>
#include <functional>
 
enum class ThreadState {
    Processing,
    Completed,
    Errored
};

bool state = true;
class Sensor {
public:
    virtual ~Sensor() = default;
    virtual void readData(const std::function<void(ThreadState)>& callback) = 0;
};
 
class RPM_Sensor : public Sensor {
    int rpm =0;
public:
    void readData(const std::function<void(ThreadState)>& callback) override {
        rpm+=10;
        std::cout << "Engine RPM: " << rpm << " RPM" << std::endl;
        if(rpm == 100){
            callback(ThreadState::Completed);
            state = false;
        }else {
            callback(ThreadState::Processing);
        }
    }
};

 
class SensorManager {
private:
    std::vector<std::shared_ptr<Sensor>> sensors;
    std::mutex mutex;
 
public:
    // add as a composite.. Engine with child as oil, petrol, coolant ...
    void addSensor(std::shared_ptr<Sensor> sensor) {
        sensors.emplace_back(sensor);
    }
 
    void readSensorData(const std::function<void(ThreadState)>& callback) {
        try {
           while (state == true) {
            std::this_thread::sleep_for(std::chrono::seconds(1));
            std::lock_guard<std::mutex> lock(mutex);
 
            for (const auto& sensor : sensors) {
                sensor->readData(callback);
            }
        }
        }
        catch(...) {
            callback(ThreadState::Errored);
        }
    }
};
 
int main() {
    SensorManager manager;
 
    manager.addSensor(std::make_shared<RPM_Sensor>());
 
    std::future<void> sensorFuture = std::async(std::launch::async, [&manager] {
        manager.readSensorData([](ThreadState state) {
            switch (state) {
                case ThreadState::Processing:
                    std::cout << "Sensor Thread is processing"<< std::endl;
                    break;
                case ThreadState::Completed:
                    std::cout << "Sensor Thread completed successfully" << std::endl;
                    break;
                case ThreadState::Errored:
                    std::cout << "Error encountered in Sensor Thread" << std::endl;
                    break;
            }
        });
    });
 
    sensorFuture.wait();
 
    return 0;
}