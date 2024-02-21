#include <bits/stdc++.h>
using namespace std;

class Patient{
    public: 
    //pubic data members
    int patientNumber;
    char *patientName;
    float array[3];
    int l;

    //default constructor
    Patient(){ patientName = new char[100];}

    //Paramaterized constructor
    Patient(int n, char* r): patientNumber(n), patientName(r){};

    //Copy constructor
    Patient(Patient &p){
        this -> patientName = p.patientName;
        this -> patientNumber = p.patientNumber;
    }

    //Taking Input from the user
    void Feedinfo(){
        cout<<"Patient Number: ";
        cin>>patientNumber;

        cout<<"Patient Name: ";
        cin>>patientName;

        for(int i=0; i<3; i++){
            cout<<"Temperature "<<i;
            cin>>array[i];
        }
        //calculating the length of name of the patient
        l = strlen(patientName);
    }

    //Show the details
    void display(){
        cout<<"Patient Number: "<<patientNumber<<endl;
        cout<<"Patient Name: "<<patientName<<endl;
        cout<<"Tempratures: ";
        for(int i=0; i<3; i++){
            cout<<array[i]<<" ";
        }
    }

    //Operator overloading []
    char operator[](int i){
        return patientName[i];
    }

    //Operator overloading ==
    bool operator==(Patient &p){
        if(p.l != l){
            return false;
        }
        for(int i=0; i<l && i<p.l; i++){
            if(patientName[i] != p.patientName[i])
                return false;
        }
        return true;
    }

    //function to calculate average
    int calculateAvgTotal(float a){
        return a/3;
    }

    //Operator overloading <
    bool operator<(Patient &p){
        float a1 =0, a2 =0;
        for(int i=0; i<3; i++){
            a1 += p.array[i];
            a2 += array[i];
        }

        if(calculateAvgTotal(a1)< calculateAvgTotal(a2)){
            return true;
        }
        return false;
    }

    //Operator overloading <<
    void operator<<(Patient &p){
        display();
    }

    //Destructor
    ~Patient(){}
};

int main(){
    //Creating the object from the class
    Patient f;
    Patient g;

    //calling the function to add information
    f.Feedinfo();
    g.Feedinfo();

    //Detail of object1
    cout<<"Detail --> Patient 1"<<endl;
    f<<f; // calling the overloading <<

    //Detail of object2
    cout<<"Detail --> Patient 2"<<endl;
    g<<g; // calling the overloading <<

    //Calling the [] operator overloading
    int i;
    cout<<"Index: ";
    cin>>i;

    if(i<f.l){
        cout<<"Character index: "<<i<<endl;
    }else{
        cout<<"ERROR: Index not found"<<endl;
    }

    //Taking the character to replace
    char ch;
    cout<<"Character: ";
    cin>>ch;

    if(i<0 || i>=f.l){
        cout<<"ERROR: Index not found"<<endl;
    }else{
        f.patientName[i]=ch;
        cout<<"Updated !!"<<endl;
        f<<f;
    }

    //Calling the == operator overloading
    if(f==g){
        cout<<"Same Name"<<endl;
    }
    else{
        cout<<"Not Same Name"<<endl;
    }

    //Calling the < operator overloading
    if(f<g)
        cout<<"Second patient has higher temperature"<<endl;
    else
        cout<<"First patient has higher temperature"<<endl;

    return 0;

}