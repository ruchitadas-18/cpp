#include <iostream>

template<float fuel>
float pump(float additionalOil) requires( fuel >= 10.0f )
{
    // constexpr
    float minFuel = 10.0f ;
    if( fuel + additionalOil < minFuel ){
        throw std::runtime_error("Car would stop any min!!");
    }
    return fuel + additionalOil;
}

// Rules to check if the engine will work or not
template <typename T>
concept MandatewhileDriving = requires(T t) {
    { t.accelerator() };
    { t.applyBreak() };
    { t.fuel };

    {pump<11.0f>(t.fuel)};
};

class Engine {
public:
    void accelerator() {
        std::cout << "Accelerate the car" << std::endl;
    }

    void applyBreak() {
        std::cout << "Brakes are applied" << std::endl;
    }

    void notRelated() {
        std::cout << "For fun" << std::endl;
    }

    float fuel = 40.0f;
};

class Car {
public:
    template <typename T>
    requires MandatewhileDriving<T>
    void drive(T arg) {
        arg.accelerator();
        arg.applyBreak();
    }
};

int main(int argc, char* argv[]) {
    Engine e;
    Car c;

    c.drive(e);

    return 0;
}
