#include<bits/stdc++.h>
using namespace std;

class Patient{
    //data members
    public:
        int patientNumber;
        char *patientName;

        float temp[3];

        int len;

    public:
        // default constructors of Patient class
        Patient(){
            patientNumber = 0;
            len = 0;
            for(int i=0; i<3; i++){
                temp[i] = 0.0;
            }
            patientName = new char[100];
        }

        // Paramaterized constructor to set values
        Patient(int num, char* name){
            this->patientNumber = num;
            strcpy(this->patientName, name);

        }

        // Copy constructor to copy the obj data
        Patient(Patient &p){

            patientName = p.patientName;

            patientNumber = p.patientNumber;

        }

        // Destructor to free the memory

        ~Patient(){

        }

        // Set values to data members

        void setValues(){

            cout<<"Enter patient number: ";

            cin>>patientNumber;

            cout<<"Enter patient name: ";

            cin>>patientName;

            cout<<"Enter the three tempratures of patient: ";

            for(int i=0; i<3; i++){

                cin>>temp[i];

            }

            len = strlen(patientName);

        }

        // Display function to show data

        void display(){

            cout<<"Patient Number: "<<patientNumber<<endl;

            cout<<"Patient Name: "<<patientName<<endl;

            cout<<"Tempratures: ";

            for(int i=0; i<3; i++){

                cout<<temp[i]<<" ";

            }

            cout<<endl;

        }

        // Overloading == operator to check -names are equal or not

        bool operator==(Patient &obj){

            if(obj.len != len){

                return false;

            }

            for(int i=0; i<len && i<obj.len; i++){

                if(patientName[i] != obj.patientName[i]){

                    return false;

                }

            }

            return true;

        }

        // Overloading [] operator to fetch character at given index

        char operator[](int i){

            return patientName[i];

        }

        // Overloading < operator to compare average

        bool operator<(Patient &obj1){

            float avg1 = 0, avg2=0;

            for(int i=0; i<3; i++){

                avg1 += obj1.temp[i];

                avg2 += temp[i];

            }

            if(avg2/3 < avg1/3){

                return true;

            }

            return false;

        }

        // Overloading << operator to display details

        void operator<<(Patient &obj){

            cout<<"Patient Number: "<<obj.patientNumber<<endl;

            cout<<"Patient Name: "<<obj.patientName<<endl;

            cout<<"Tempratures: ";

            for(int i=0; i<3; i++){

                cout<<obj.temp[i]<<" ";

            }

            cout<<endl;

        }

};

int main(){

    Patient p1;

    p1.setValues();

    Patient p2;

    p2.setValues();

    // display the details

    cout<<"Details of Patient 1"<<endl;

    p1<<p1;

    cout<<endl;

    cout<<"Details of Patient 2"<<endl;

    p2<<p2;

    cout<<endl;

    // comparing temprature values

    if(p1 < p2){

        cout<<"Average of Patient 2 is greater"<<endl;

    }

    else{

        cout<<"Average of Patient 1 is greater"<<endl;

    }

    cout<<endl;

    // comparing patient names

    if(p1 == p2){

        cout<<"Name of patients are equal"<<endl;

    }

    else{

        cout<<"Name of patients are not equal"<<endl;

    }

    cout<<endl;

    // getting value at index

    int ind;

    cout<<"Enter index: ";
    cin>>ind;

    if(ind < p1.len){

        cout<<"Character present at "<<ind<<" index is: "<<p1.patientName[ind]<<endl;

    }

    else{

        cout<<"ERROR: Index out of bounds"<<endl;

    }

    // setting the value at index in P1;

    cout<<endl;

    char ch;

    cout<<"Enter character: ";

    cin>>ch;

    int in;

    cout<<"Enter index: ";

    cin>>in;

    if(in<0 || in>=p1.len){

        cout<<"Entered index in out of bound"<<endl;

    }

    else{

        p1.patientName[in] = ch;

        cout<<endl;

        cout<<"Updated details of patient 1"<<endl;

        p1<<p1;

    }

    return 0;

}