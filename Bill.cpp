#include<bits/stdc++.h>
using namespace std;

class Electricity{
    //private data members
    int sanctionLoad,electricityslab;
    long presentReading, previousReading, Consumption;
    
    public: Electricity(){} //default constructor;

    //setter method;
    void setSanctionLoad(int sanctionLoad){
        this->sanctionLoad = sanctionLoad;
    }
    void setElectricityslab(int electricityslab){
        this->electricityslab= electricityslab;
    }
    void setPreviousReading(long previousReading){
        this->previousReading = previousReading;
    }
    void setPresentReading(long presentReading){
        this->presentReading = presentReading;
    }
    void setConsumption(int Consumption){
        this->Consumption = Consumption;
    }

    //getter method
    int getSanctionLoad(){
        return sanctionLoad;
    }
    int getElectricityslab(){
        return electricityslab;
    }
    long getPreviousReading(){
        return previousReading;
    }
    long getPresentReading(){
        return presentReading;
    }
    long getConsumption(){
        return Consumption;
    }
    
    //functions to calculate Electricity Bill
    int calculateElectricityBill(int sanctionLoad, int electricityslab, long presentReading, long previousReading, long Consumption){
        //condition on reading
        if(presentReading>previousReading){
            return 0;
        }else{
            //calculate the electric bill
            return (sanctionLoad*electricityslab)+(Consumption*electricityslab/100);
        }
    }

    // function to take input from the user
    void accept(){
        cout<<"SanctionLoad: "<<endl;
        cin>>sanctionLoad;

        cout<<"Electricityslab: "<<endl;
        cin>>electricityslab;

        cout<<"PresentReading: "<<endl;
        cin>>presentReading;

        cout<<"Previous Reading: "<<endl;
        cin>>previousReading;

        cout<<"Consumption: "<<endl;
        cin>>Consumption;
    }

    //function to display the details
    void display(){
        cout<<"SanctionLoad: "<<sanctionLoad<<endl;
        cout<<"Electricityslab: "<<electricityslab<<endl;
        cout<<"PresentReading: "<<presentReading<<endl;
        cout<<"Previous Reading: "<<previousReading<<endl;
        cout<<"Consumption: "<<Consumption<<endl;
        // Calling the Electric Bill
        cout<<"Electric Bill Amount: "<<calculateElectricityBill(sanctionLoad, electricityslab,presentReading, previousReading, Consumption)<<endl;
    }
};
int main(){
    //creating object of the class
    Electricity e;
    //calling the functions
    e.accept();
    e.display();

    //terminating the program
    return 0;
}