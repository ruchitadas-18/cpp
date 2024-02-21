#include <iostream>
#include <vector>

// interface
class Ingreditents {
public:
    virtual std::string name() = 0;
    virtual int calories() = 0;
    virtual int cost() = 0;
};

enum class ingreditType {
    Bread, filling
};

// components
class Bread : public Ingreditents {
public:
    virtual std::string name() override = 0;
    virtual int calories() override = 0;
    virtual int cost() override = 0;
};

class bagel : public Bread {
public:
    std::string name() override {
        return "bagel";
    }
    int calories() override {
        return 20;
    }
    int cost() override {
        return 230;
    }
};

class Bun : public Bread {
public:
    std::string name() override {
        return "Bun";
    }

    int calories() override {
        return 20;
    }
    int cost() override {
        return 230;
    }
};

// component 2
class filling : public Ingreditents {
public:
    virtual std::string name() override = 0;
    virtual int calories() override = 0;
    virtual int cost() override = 0;
};

class cheese : public filling {
public:
    std::string name() override {
        return "Cheese";
    }
    int calories() override {
        return 23;
    }

    int cost() override {
        return 457;
    }
};

class cheeseM : public filling {
public:

    std::string name() override {
        return "CheeseM";
    }
    int calories() override {
        return 23;
    }

    int cost() override {
        return 457;
    }
};

class patty : public filling {
public:
    std::string name() override {
        return "patty";
    }
    int calories() override {
        return 23;
    }

    int cost() override {
        return 500;
    }
};

// interface
class Sandwich {
    std::vector<Ingreditents*> it;

public:
    void addIngreditents(Ingreditents* ingreditent) {
        it.emplace_back(ingreditent);
    }

    void getSandwich() {
        for (Ingreditents* i : it) {
            std::cout << i->name() << std::endl;
        }
    }

    void getCallories() {
        int totalCalories = 0;
        for (Ingreditents* i : it) {
            totalCalories += i->calories();
        }
        std::cout << "Total Calories: " << totalCalories << std::endl;
    }
};

class SandwichProvider {
public:
    Ingreditents* ingredit(ingreditType ingreditFood) {
        Ingreditents* ingredit = nullptr;
        if (ingreditFood == ingreditType::Bread) {
            ingredit = new Bun;
        } else if (ingreditFood == ingreditType::filling) {
            ingredit = new cheeseM;
        }
        return ingredit;
    }
};

int main(int args, const char* argv[]) {
    std::cout << "Sandwich Service Provider !!" << std::endl;
    SandwichProvider* sandProvide = new SandwichProvider;
    Ingreditents* indent = sandProvide->ingredit(ingreditType::Bread);

    std::cout << "Bun Name: " << indent -> name() << std::endl;
    std::cout << "Bun Calories: " << indent -> calories() << std::endl;
    std::cout << "Bun Cost: " << indent -> cost() << std::endl;


    return 0;
}
