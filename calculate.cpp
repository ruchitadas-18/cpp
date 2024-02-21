#include <iostream>

class aCalculator{
    public:
    virtual int add(int x, int y)=0;
    virtual int sub(int x,int y)=0;
    virtual int mul(int x, int y)=0;
    virtual int div(int x, int y)=0;
};

class BasicCalcutor: public aCalculator{
    public:
    int add(int x, int y) override{
        return x+y;
    }

    int sub(int x, int y) override{
        return x-y;
    }

    int mul(int x, int y) override{
        return x*y;
    }

    int div(int x, int y) override{
        return x/y;
    }
};

class aUser{
    public:
    virtual int req_add(aCalculator* c,int x, int y)= 0;
    virtual int req_sub(aCalculator* c,int x, int y)= 0;
    virtual int req_mul(aCalculator* c,int x, int y)= 0;
    virtual int req_div(aCalculator* c,int x, int y)= 0;
};

class Tom: public aUser{
    public:
    int req_add(aCalculator* c, int x, int y){
        return c->add(x,y);
    }

    int req_sub(aCalculator* c, int x, int y){
        return c->sub(x,y);
    }

    int req_div(aCalculator* c, int x, int y){
        return c->div(x,y);
    }

    int req_mul(aCalculator* c, int x, int y){
        return c->mul(x,y);
    }
};

int main(int args, const char* argv[]){

    aCalculator* calc = new BasicCalcutor();
    aUser* u = new Tom();
    std::cout<<u->req_add(calc, 12,34)<<std::endl;
    return 0;
}

//State in place of if else---> ask ma