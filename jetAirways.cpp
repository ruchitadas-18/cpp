#include <iostream>
#include <vector>
#include <algorithm>

class iFlight {
public:
    virtual void flightOnTime() = 0;
    virtual void flightDelayed() = 0;
};

class User : public iFlight {
public:
    std::string Name;
    int accountNum;

    User& setName(std::string name) {
        this->Name = name;
        return *this;
    }

    User& setAccountNum(int accountNum) {
        this->accountNum = accountNum;
        return *this;
    }

    void flightOnTime() override {
        std::cout << "Flight on time for user: " << Name << std::endl;
    }

    void flightDelayed() override {
        std::cout << "Flight delayed for user: " << Name << std::endl;
    }
};

class jetAirways {
public:
    std::vector<iFlight*> users;

    int getUserCount() {
        return users.size();
    }

    void passRegister(iFlight* f) {
        users.push_back(f);
    }

    void passUnRegister(iFlight* f) {
        auto it = std::find(users.begin(), users.end(), f);
        if (it != users.end()) {
            users.erase(it);
        }
    }

    void setState(bool state) {
        notify(state);
    }

    void notify(bool state) {
        if (state) {
            for (auto& cUser : users) {
                cUser->flightOnTime();
            }
        } else {
            for (auto& cUser : users) {
                cUser->flightDelayed();
            }
        }
    }
};

int main(int args, const char* argv[]) {
    std::cout << "JetAirways" << std::endl;
    jetAirways jet;

    User user1, user2;
    user1
        .setAccountNum(12345677)
        .setName("Suresh");
    user2
        .setAccountNum(12677)
        .setName("Ramesh");

    jet.passRegister(&user1);
    jet.passRegister(&user2);

    jet.setState(true);

    return 0;
}
