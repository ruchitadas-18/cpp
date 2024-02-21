#include<bits/stdc++.h>
using namespace std;

class Flight{
    // private data members
    string flightNumber, flightType;
    double distance;
    double fuelquantity=0.0;
    double fare=0.0;

    public:
    // default constructor
    Flight(){}
    //Paramaterized constructor
    Flight(string a, string b, double c):flightNumber(a),flightType(b),distance(c){}

    //setter methods
    void setFlightNumber(double flightNumber){
        this->flightNumber=flightNumber;
    }
    void setFlightType(double flightType){
        this -> flightType=flightType;
    }
    void setDistance(double distance){
        this -> distance = distance;
    }

    //getter method
    string getFlightNumber(){
        return flightNumber;
    }
    string getFlightType(){
        return flightType;
    }
    double getDistance(){
        return distance;
    }

    //Taking Input from the user
    void Feedinfo(){
        cout<<"FlightNumber: ";
        cin>>flightNumber;

        cout<<"FlightType: ";
        cin>>flightType;

        cout<<"Distance: ";
        cin>>distance;
    }

    //Calculating the Fare for the following distance
    double calculateFare(double distance){
        if(distance<=1000){
            fare+=5000.0;
        }else if(distance>1000 && distance<=1500){
            fare+=11000;
        }else if(distance>1500 && distance<=2000){
            fare+=22000;
        }else{
            fare+=30000;
        }
        return fare;
    }

    //Calculating the Fuel for the following distance
    double calculateFuel(double distance){
        if(distance<=1000){
            fuelquantity+=4000;
        }else if(distance>1000 && distance<=1500){
            fuelquantity+=6000;
        }else if(distance>1500 && distance<=2000){
            fuelquantity+=7500;
        }else{
            fuelquantity+=10000;
        }
        return fuelquantity;
    }

    //Showing the details by calling the functions
    void Showinfo(){
        cout<<"FlightNumber: "<<getFlightNumber()<<endl;
        cout<<"Distance: "<<getDistance()<<endl;
        cout<<"FlightType: "<<getFlightType()<<endl;
        cout<<"Fuelquantity: "<<calculateFuel(distance)<<endl;
        cout<<"Fare: "<<calculateFare(distance)<<endl;
    }


};

int main(){
    //Declaring the Max price of the Flight
    int max = 10000;

    //Creating an array from the variables in flight class
    vector<Flight>f1;
    Flight f;

    //Getting the details of flight
    for(int i=0;i<3;i++){
        cout<<"Details of Flight: "<<i+1<<endl;
        f.Feedinfo();//call the Feedinfo to enter the details of the flight
        f1.push_back(f);//adding to the array
    }
    //Iterating the array to show the details
    for(auto &it:f1){
        it.Showinfo();
    }

    //intializing the string to store the value
    string search;
    //Getting the Flight Number for searching...
    cout<<"Flight Number: ";
    cin>>search;

    int d =0;
    //searching the flight
    for(int i=0;i<3;i++){
        if(search==f1[i].getFlightNumber()){
            f1[i].Showinfo();
            d =1;
        }
    }
    //if d is not changed then printing the flight is not avaliable
    if(d==0){
        cout<<"Sorry Not Available"<<endl;
        cout<<"Maximun fare"<<max<<endl;
    }
    //terminating the program
    return 0;
}