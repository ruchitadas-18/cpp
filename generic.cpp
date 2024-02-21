#include <iostream>

enum class CarType{Mercedes, Ferrari};
class Engine{
    public:
    // Engine() = default;  // Engine() : don't write use default
    Engine(){
        std:: cout << "Base Engine Created..." << std::endl;
    }
    void virtual start()=0;
};

class AmgEngine: public Engine{
    public:
    void start() override{
        std::cout << "AMGengine started "<< std::endl;
    }
};

class FerrariEngine: public Engine{
    public:
    void start() override{
        std::cout << "Ferrai Engine started "<< std::endl;
    }
};

class ServiceProviderFactory{
    Engine* engine;
    public:
    Engine* getEngine( CarType carType){
        if(carType == CarType::Mercedes)
            engine = new AmgEngine;
        else if(carType == CarType::Ferrari)
            engine = new FerrariEngine;
        else{
            std::cout << "Requested engine not found ! " << std::endl;
            return nullptr;     // dont return NULL
        }
        return engine; // passing derived class which is called.
    }
};

class Car{
    private:
    public:
    Car(){
        std::cout << "Base car created..." << std::endl;
    }
    Engine* engine;
    virtual void start(Engine* e) = 0;
};

class BenzCar: public Car{
    public:
    void start(Engine* engine){
        std::cout << "Benz car started " << std::endl;
        this->engine = engine;
        engine->start();
    }
};

class FerrariCar: public Car{
    public:
    void start(Engine* engine){
        std::cout << "Ferrai car started " << std::endl;
        this->engine = engine;
        engine->start();
    }
};

int main(int argc, const char* argv[]){
    std::cout << "Engine provider! \n" << std::endl;
    std::cout << std::endl;
    ServiceProviderFactory* serviceProviderFactory = new ServiceProviderFactory; //
    Engine* engine = serviceProviderFactory->getEngine(CarType::Ferrari); //Engine object pointer

    FerrariCar car;
    car.start(engine);

    return 0;
}

// class SandwichBuild{
//     public:
//     static Sandwich readymade(){
//         Sandwich sandwich;
//         //not accepted since it is hardcoded
//         sandwich.addIngreditents(new patty());
//         sandwich.addIngreditents(new cheese());

//         return sandwich;
//     }

//     static Sandwich build(Sandwich& s, Ingreditents* i){
//         s.addIngreditents(i);
//     }

// };