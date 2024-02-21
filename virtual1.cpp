#include <iostream>
using namespace std;
class Brew{
    public:
    void BoilWater(){
        cout<<"BOil Water"<<std::endl;
    }

    void BoilMilk(){
        cout<<"Boil Milk"<<std::endl;
    }

    void pourItMug(){
        cout<<"Pour the milk"<<std::endl;
    }

    virtual void add1() = 0;
    virtual void add2() = 0;
    virtual void add3() = 0;

    void executed(){
        BoilWater();
        BoilMilk();
        add1();
        add2();
        add3();
        pourItMug();
    }
};


class Tea: public Brew{
    public:
    virtual void add1(){  //overide to known weather it is overide from vitual function
        cout<<"Steep the tea bag"<<endl;
    }

    virtual void add2(){  //overide to known weather it is overide from vitual function
        cout<<"Add lime"<<endl;
    }
    virtual void add3(){  //overide to known weather it is overide from vitual function
        cout<<"Add Sugar"<<endl;
    }
};

class Coffee: public Brew{
    public:
    virtual void add1(){  //overide to known weather it is overide from vitual function
        cout<<"Steep the coffee powder"<<endl;
    }

    virtual void add2(){  //overide to known weather it is overide from vitual function
        cout<<"Strong or light"<<endl;
    }
    virtual void add3(){  //overide to known weather it is overide from vitual function
        cout<<"Add Sugar"<<endl;
    }
};

int main(int args, const char* arg[]){
    cout<<"Virtual Function"<<endl;

    // Brew* brew = new Tea();
    // brew -> executed();

    // Brew* brew1 = new Coffee();
    // brew1 -> executed();

    Brew* array[]{ new Tea(), new Coffee()};
    
    for(int i=0; i<2; i++){
        array[i] -> executed();
    }

    return 0;

}

