#include <iostream>
#include <vector>
using namespace std;

class Widget{
    public:
    void doWork1() & {
        cout<<"Work on 1value "<<endl;
    }

    void doWork2() && {
        cout<<"Work on rvalue"<<endl;
    }
};

 
class Widget1 {
    public:
    using DataType = std::vector<double>;
    Widget1(){
        values = {1.10,2.20,3.30,4.40,5.50};
    }

    DataType& data()&{ //taking the refrence
        return values;
    }

    DataType data()&& {
        return std::move(values);
    }
    int&& a =9;
    private:
    DataType values;
};

void setValue(int val){} //regular function
void setValue(const int& val){} //not rvalue or lvalue
void setValue(int& val){} //lvalue
void setValue(int&& val){} //rvalue

int main(){
    // calling the lvalue and rvalue
    //Phase 1
    Widget w1;
    w1.doWork1(); //return lvalue

    Widget().doWork2(); //return rvalue

    const std::vector v= {11,12,14,15,28};
    //vector use to reference to change the value
    //vector is constant by nature

    //lvalue and rvalue function
    Widget1 w2;
    for(auto& value: w2.data()){  //lvalue 
        value +=5;
        cout<<value<<" "<<endl;
    }

    for(const auto& value: Widget1().data()){
        cout<<value<<" "<<endl;
    }
} 

