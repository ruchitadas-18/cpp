#include <iostream>
#include <string>

using namespace std;

class Bill{
    
    std::string product;
    std::string brand;
    double cost;
    double tax;

    public:

    Bill& productN(const std::string& productName){
        this->product = productName;
        return *this;
    }

    Bill& brandN(const std::string& brandName){
        this -> brand = brandName;
        return *this;
    }

    Bill& costT(double costAmt){
        this -> cost = costAmt;
        return *this;
    }

    Bill& taxT(double taxAmt){
        this -> tax = taxAmt;
        return *this;
    }

    void display(){
        cout<<"Product: "<<product<<endl;
        cout<<"Brand: "<<brand<<endl;
        cout<<"Cost: "<<cost<<endl;
        cout<<"Tax: "<<tax<<endl;
    }

};

//Builder code to call the function
void simpleCode(){
    Bill b;
    b.productN("Dress")
     .brandN("Allen Solly")
     .costT(90)
     .taxT(30);
    b.display();
}


int main(int argc, const char* argv[]){
    //call the 
    simpleCode();
    return 0;
}