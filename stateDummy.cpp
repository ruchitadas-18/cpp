#include <iostream>
#include <variant>
#include <functional>

using namespace std;

//modern cpp coding
class Machine{
    public:
    void on(){cout<<"Machine is on. "<<endl;}
    void off(){cout<<"Machine is off. "<<endl;}
};

int main(){
    using MachineFSM = variant<std::function<void(Machine& )>,
                        std::function<void()>
                        >;
    
    MachineFSM machinePTR [] = {
        [](Machine& m){m.off();},
        [](Machine& m){m.on();}
    };

    Machine fsm; //final state machine
    int yourOption;
    cout<<"0/1"<<endl;
    cin>>yourOption;

    std::visit(
        [yourOption, &fsm](auto& func){
            if constexpr(std::is_invocable_v <decltype(func), Machine&>){
                if(yourOption == 0 || yourOption == 1)
                    func(fsm); //[](Machine& m) fsm = m
                else{
                    cout<<"Invalid option"<<endl;
                }
            }else{
                cout<<"Invalid2 option"<<endl;
            }
        }, machinePTR[yourOption]
    );

    return 0;
}

//legacy cpp coding
// class Machine{
//     public:
//     void on(){cout<<"Machine is on. "<<endl;}
//     void off(){cout<<"Machine is off. "<<endl;}
// };

// int main(){
//     void (Machine:: *machinePTR[])()={
//         &Machine::off, &Machine::on
//     };

//     Machine fsm; //final state machine
//     int yourOption;
//     cout<<"0/1"<<endl;
//     cin>>yourOption;
//     (fsm.*machinePTR[yourOption])();
//     return 0;
// }