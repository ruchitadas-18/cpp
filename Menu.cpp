#include <bits/stdc++.h>
using namespace std;

//interface --> Parent Class
class interfaceComponent{
    public:
    //member function --> parent
        string getName(){
            return name;
        }
        virtual void ls()= 0;
 
    protected:
        string name;
        //static keyword == constant memory location
        static int indent;
};
 
int interfaceComponent::indent = 0;
 
 //component --> child class
class Leaf : public interfaceComponent{
    public:
        Leaf(string n){
            name = n;
        }
        // print all the directories
        void ls(){
            for(int16_t int16_t_i=0; int16_t_i<indent; int16_t_i++){ // according to misra guidelines
                cout<<' ';
            }
            cout<<name<<endl;
        }
};
 
//compontent 
class Composite : public interfaceComponent{
    protected:
        vector<interfaceComponent*> files;
    public:
        Composite(string n){
            name = n;
        }
 
        void ls(){
            for(int i=0; i<indent; i++){
                cout<<" ";
            }
            //cout<<files.size()<<" Composite found under ( "<<name<<" )"<<endl;
            cout<<name<<" : "<<endl;
            indent += 5;
 
            for(int i=0; i<files.size(); i++){
                //cout<<"Getting the file name: "<<endl;
                files[i]->ls();
            }
            indent -= 5;
        }
 
        void display(){
            cout<<name<<" All Child: "<<endl;
            for(int i=0; i<files.size(); i++){
                for(int j=0; j<3; j++){
                    cout<<" ";
                    cout<<files[i]->getName()<<endl;
                }
            }
        }
};

//concrete class
class Menu : public Composite{
    public:
        Menu(string s) : Composite(s){}
 
        void add(interfaceComponent* f){
            files.emplace_back(f);
        }
 
        void addComp(string s){
            add(new Composite(s));
        }
 
        void addLeaf(string s){
            add(new Leaf(s));
        }
 
        Menu* getHandle(string str){
            for(int i=0; i<files.size(); i++){
                if(str == files[i]->getName()){
                    return (Menu*)files[i]; //typecasting 
                }
            }
            cout<<"Directory "<<str<<" not found"<<name<<endl;
            // return exit(1);
            return nullptr;
        }
 
        void remove(string str){
            vector<interfaceComponent*>::iterator p = files.begin();
            //getting the iterater from the vector class
            //file begin work as a range is
            for(int i=0; i<files.size(); i++,p++){
                if(str == files[i]->getName()){
                    files.erase(p);
                }
            }
        }
};
 
//Driver Class
int main(){
    cout<<"Composing Menu\n"<<endl;
 
    Menu m("Menu");
    m.addComp("File");
    m.addLeaf("Edit");
    m.addLeaf("Search");
 
    m.getHandle("File")->addLeaf("New");
    m.getHandle("File")->addLeaf("Open");
 
    m.getHandle("File")->addComp("Run");
    m.getHandle("File")->getHandle("Run")->addLeaf("Compile");m.getHandle("File");
    m.getHandle("File")->getHandle("Run")->addLeaf("Build");
    m.getHandle("File")->remove("Open");
 
    Composite* mgetHandle = m.getHandle("File");
    Composite* mgetHandle1 = m.getHandle("Edit");
    mgetHandle->ls();
    mgetHandle1 -> ls();
 
 
    return 0;
}