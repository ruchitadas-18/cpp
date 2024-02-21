#include <iostream>
#include <string>

class iCurrencyConvertor{
    public:
    virtual std::string getCurrency() const = 0;

    iCurrencyConvertor() = default; // user define default constructor
    //iCurrencyConvertor() = delete; // delete constructor

    //virtual destructor  complusory for default 
    virtual ~iCurrencyConvertor() = default;
};

class CurrencyString : public iCurrencyConvertor{
    std::string curr;
    public:
    CurrencyString(std::string s){
        curr = s;
    }
    std::string getCurrency() const override{
        return curr;
    }
};

class CurrencyFormatter{
    const iCurrencyConvertor* convertable; //access the public function
    public:
    CurrencyFormatter(const iCurrencyConvertor* convertable): convertable(convertable){}
    
    std::string getCurrency(){
        std::string cur= convertable->getCurrency();
        return cur;
    }
};

class CurrencyDisplay{
    std::string curr;
    const iCurrencyConvertor* convertable;
    public:
    CurrencyDisplay(const iCurrencyConvertor* convertable): convertable(convertable){
        curr = convertable->getCurrency();
    }
    void display() const{
        std::cout<<"Formatter ";
        
        if(curr == "RS"){
            std::cout<<"Rs. = \u20b9"<<std::endl;
        }
        else if(curr == "Dollar"){
            std::cout<<"Dollar = $"<<std::endl;
        }
        else if(curr == "Yen"){
            std::cout<<"Yen = \u00A5"<<std::endl;
        }
        else if(curr == "Arab"){
            std::cout<<"Arab = \u6041"<<std::endl;
        }
        else{
            std::cout<<"Unknown Currency..."<<std::endl;
        }
    }
};

//const -> compilar friendly -> rock memory -> static memory
//seperates the runtime with compile time
int rec =0;
void understandConst(const int val){
    std::cout<<"Constant"<<std::endl;

    for(int i=0; i<=val; i++){
        rec = i;
        std::cout<<rec;
    }
}

int main(int args, const char *arg[]){
    understandConst(6);
    CurrencyString s("Dollar");
    CurrencyFormatter d(&s);
    CurrencyDisplay f(&s);
    f.display();
    return 0;
}