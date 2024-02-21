#include<bits/stdc++.h>
using namespace std;

// auto make_me_a_dev(const std:: string& name){
//     int age = 43;
//     return [](){
//         cout<<"I'm a dev, my name is "<<name<<endl; // to access name, use & inside the capture list

//     };
// }

auto make_me_a_dev(const std:: string& name){
    int age = 43;
    //& == refrence only for higher order
    //= global 
    return [=](){
        cout<<"I'm a dev, my name is "<<name<<" "<<age<<endl; // to access name, use & inside the capture list

    };
}
int main(){
    std::cout<<"Hello, world!\n";\

    auto sayName {make_me_a_dev("Ruchita")};
    sayName();

    int ammo{12};
    auto shoot{
       // cout<<__PRETTY_FUNCTION__<<endl;
        [ammo]()mutable{
            cout<<__PRETTY_FUNCTION__<<endl;
            --ammo;
            cout<<"Pew!"<<ammo<<endl;
        }
    };

    shoot();
}