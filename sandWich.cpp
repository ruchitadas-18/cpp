#include <bits/stdc++.h>
class Ingredient{
    public:
    virtual std::string name() =0;
    virtual int calories() = 0;
    virtual int cost() =0;
};

class Bread: public Ingredient{
    public:
    virtual std::string name() =0;
    virtual int calories() =0;
    virtual int cost() =0;
};

class Bagel : public Bread {
    public :
    std::string name() override {
        return "Bagel";
    }
    int calories() override {
        return 250 ;
    }
    int cost() override {
        return 20 ;
    }
};

auto Bagel1 = [&](Bread& b){
    std::string name = "Bagel";
    int calories = 250;
    int cost = 20;
};

class Bun : public Bread {
    public :
    std::string name() override {
        return "Bun";
    }
    int calories() override {
        return 150 ;
    }
    int cost() override {
        return 10 ;
    }
};

class Filling : public Ingredient{
    public :
    virtual std::string name() = 0 ;
    virtual int calories() = 0;
    virtual int cost() = 0 ;
};

class CreamCheese : public Filling {
    public :
    std::string name() override {
        return "CreamCheese";
    }
    int calories() override {
        return 350 ;
    }
    int cost() override {
        return 70 ;
    }
};

class SmokedSalmon : public Filling {
    public :
    std::string name() override {
        return "Smoked Salmon";
    }
    int calories() override {
        return 450 ;
    }
    int cost() override {
        return 170 ;
    }
};

class Sandwich{
    private :
    std::vector< Ingredient* > ingredients ;
    public :
        // void addIngredients( Ingredient* ingredient){
        //     ingredients.emplace_back( ingredient);
        // }

        std::function<void(Ingredient* ingredient)> addIngredients = [=](Ingredient* ingredient){
             ingredients.emplace_back( ingredient);

        };

        void getCost(){
            for(Ingredient* i : ingredients){
            std::cout << " cost " << i->cost()<<std::endl ;
            }
        }

        void getName(){
            for(Ingredient* i : ingredients){
            std::cout << " Name: " << i->name()<<std::endl ;
            }
        }

        void getCalories1(){
            for(Ingredient* i : ingredients){
            std::cout << " calories: " << i->calories()<<std::endl ;
            }
        }

        void getCalories() {
            int totalCalories = 0 ;
            for(Ingredient* i : ingredients){
            totalCalories += i->calories();
            }
            std::cout << "Total calories " << totalCalories <<std::endl ;
        }
};

class SandwichBuilder{
    public :
    static Sandwich readyMade() {
    Sandwich sandwich;
    sandwich.addIngredients( new Bagel );
    sandwich.addIngredients( new SmokedSalmon() );
    sandwich.addIngredients( new CreamCheese() );
    return sandwich ;
    }
    static Sandwich build( Sandwich& s , Ingredient* ingredient){
        s.addIngredients( ingredient);
        return s ;
    }
};
//-------------Visitor-----------------
class Auditor{
    public:
    void operator()(Sandwich sand){  //it is not composing --> it is visitor
        //use proxy wrapper to sandwich to avoid giving access to unrequired member function
        //and private functions
        sand.getCost();
        sand.getName();
    }
};

//-------------------------Visitable--------------------

int main(int argc, const char * argv[]) {
// insert code here...
    std::cout << "Sandwich builder!\n";
    Sandwich custom ;
    SandwichBuilder::build( custom ,new Bun() );
    SandwichBuilder::build( custom ,new CreamCheese() );
    std::cout << " Customised sandwich " << std::endl ;
    // custom.getSandwich();
    // custom.getCalories();
    Sandwich offTheShelf = SandwichBuilder::readyMade();
    std::cout << " Ready made sandwich " << std::endl ;
    // offTheShelf.getSandwich() ;
    // offTheShelf.getCalories();


    //SOILD --> clean coding
    //S : Single object 
    //O : open for extension and close for modification
    //I : interface segration principle
    //L : Liscow sky principle -> fly and not fly
    //D: Dependency inversion principle

    using SandwichType = std::variant<Sandwich>;
    std::vector< SandwichType> mySandwich = {custom, offTheShelf};

    Auditor audiVisit;

    auto visitSandwich = [&](const auto& sandwichSeq){
        std::visit(audiVisit,sandwichSeq);
    };

    for(const auto& sandwich:mySandwich){
        visitSandwich(sandwich);
    }


    return 0;

}