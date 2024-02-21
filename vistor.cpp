#include <bits/stdc++.h>

class House;
class StudentLoan;

class Vistor{  //Auditor
    public:
    virtual double visit(House& ) = 0; 
    virtual double visit(StudentLoan& ) = 0;
};

class Visitable{ //Me to get the tax
    public:
    virtual double accept(Vistor& ) = 0;
};

//My properties
class House: public Visitable{
    double value;
    public:
    House(double v): value(v){}
    double accept(Vistor& v) override{
        return v.visit(*this); //act like a key for the house
    }

    double getValue(){
        return value;
    }
};

class StudentLoan: public Visitable{
    double value;
    public:
    StudentLoan(double v): value(v){}
    double accept(Vistor& v) override{
        return v.visit(*this); //act like a key for the house
    }

    double getAmount(){
        return value;
    }
};

class TaxVisitor: public Vistor{
    public:
    double visit(House& house) override{
        std::cout<<"Housing Loan"<<std::endl;
        return house.getValue()*9.80;
    }

    double visit(StudentLoan& studentLoan) override{
        std::cout<<"Student Loan"<<std::endl;
        return studentLoan.getAmount()*7.60;
    }
};

int main(){
    std::cout<<"Vistor and Visitable Code"<<std::endl;
    std::vector<Visitable*> visita;
    visita.emplace_back(new House(8000));
    visita.emplace_back(new StudentLoan(88000));

    TaxVisitor taxVisitor;
    double totalTax = 0;

    for(auto assert: visita){
        totalTax += assert -> accept(taxVisitor);
    }
    std::cout<<totalTax<<std::endl;

    //to apply the concept of varient and visit
    std::vector< std::variant <House,StudentLoan>> loan = {
        House(5000),
        StudentLoan(100)
    };

    for(auto& loan: loan){
        double tax = std::visit([&taxVisitor](auto&& s){
            return s.accept(taxVisitor);
        },loan);
        std::cout<<"Variant visit Tax: "<<tax<<std::endl;

    }

}