#include <iostream>

struct singleton_t{
    static
    singleton_t &instance(){
        static singleton_t instance;
        return instance;
    }

    singleton_t(const singleton_t&) = delete;
    singleton_t & operator = (const singleton_t &) = delete; //overright with move constructor

    private:
    singleton_t(){}
    ~singleton_t(){}

    public:
    void out(){
        printf("out\n");
    };
};

int main(){
    singleton_t::instance().out();
}