//
//  main.cpp
//  StrategyWalkDrive
//
//  Created by Sathya Babu on 21/01/24.
//

#include <iostream>

// Strategy interface
class Strategy {
public:
    virtual void Travel() = 0;
    virtual ~Strategy() {}
};

// TemplateDrive class
class TemplateDrive : public Strategy {
public:
    void Travel() override {
        startDriving();

        while (true) {
            if (distanceTraveled()) break;
        }

        stopDriving();
    }

protected:
    virtual void startDriving() = 0;
    virtual bool distanceTraveled() = 0;
    virtual void stopDriving() = 0;
};

// Drive class
class Drive : public TemplateDrive {
private:
    int KM = 1;

protected:
    void startDriving() override {
        std::cout << "\n Started Driving.......  . ";
    }

    bool distanceTraveled() override {
        if (KM == 5)
            return true;
        else {
            std::cout << "\n Covered " << KM++ << " Km. ";
        }
        return false;
    }

    void stopDriving() override {
        std::cout << "\n  Reached Dest Km = " << KM << ".  Stopped Driving.......  . ";
    }
};

// TemplateWalk class
class TemplateWalk : public Strategy {
public:
    void Travel() override {
        startWalking();

        while (nextMileStone() && !isDestination())
            ;

        stopWalking();
    }

protected:
    virtual void startWalking() = 0;
    virtual bool nextMileStone() = 0;
    virtual bool isDestination() = 0;
    virtual void stopWalking() = 0;
};

// Walk class
class Walk : public TemplateWalk {
private:
    int KM = 1;

protected:
    void startWalking() override {
        std::cout << " Started Walking.....  ....  ..  . ";
    }

    bool nextMileStone() override {
        std::cout << " \n Mile Stone : " << KM++;
        return true;
    }

    bool isDestination() override {
        std::cout << "\n is this our Destination!!-" << (KM == 5);
        return (KM == 5);
    }

    void stopWalking() override {
        std::cout << " Reached Destination Km = " << KM << ".  Stopped Walking.....  ....  ..  . ";
    }
};

void LetclientDecide(Strategy* strat) {
    strat->Travel();
}

// Main function
int main() {
    Strategy* algorithms[] = {new Walk(), new Drive()};

    for (int start = 0; start < sizeof(algorithms) / sizeof(algorithms[0]); start++) {
        LetclientDecide(algorithms[start]);
    }

    // Clean up allocated memory
    for (int i = 0; i < sizeof(algorithms) / sizeof(algorithms[0]); i++) {
        delete algorithms[i];
    }

    return 0;
}

