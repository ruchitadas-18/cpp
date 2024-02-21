#include <iostream>
//1c2f memory address
class Animal{ // Since it is a parent class it get function 
//are executed thou child is called

    private:
    std::string type;

    public:
    //const function --> intial the value in the type
    Animal():type("Animal"){}

    //Phase 1
    // std::string getType(){
    //     return type;
    // }

    //Phase 2
    // virtual std::string getType(){
    //     return type;
    // }

    //Phase 3
    virtual std::string getType() =0;
    //virtual destructor will automatically destroy the derived class
    //when the base class is deleted in the main class
    virtual ~Animal(){
        std::cout<<"Animal Distructor"<<std::endl;
    }

};
//ff00         1c2f                 address in the memmory
class Dog: public Animal{
    private:
    std::string type; //library variable not a user variable

    public:
    Dog(): type("I am a Puppy"){}

    std::string getType(){
        return type;
    }

    ~Dog(){
        std::cout<<"Dog Destructor"<<std::endl;
    }
};

//ffee
class Cat: public Animal{
    private:
    std::string type; //library variable not a user variable

    public:
    Cat(): type("I am a Kitten"){}

    std::string getType(){
        return type;
    }

    ~Cat(){
        std::cout<<"Cat Destructor"<<std::endl;
    }
};

void printAnimal(Animal* a){
    std::cout<<a->getType()<<std::endl;
}

int main(int arg, char* argv[]){
    std::cout<<"Virtual Function"<<std::endl;

    //Phase 1

    //Animal* animal = new Animal();  Error because of abstract class in Phase 3
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    // std::cout<<dog->getType()<<std::endl;
    // std::cout<<cat->getType()<<std::endl;

    //standalone function
    printAnimal(dog);
    printAnimal(cat);

    
    return 0;
}