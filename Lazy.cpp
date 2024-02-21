#include <iostream>
#include <functional>
#include <string>
#include <memory>

template<typename F, typename... Args>
class Lazy{
    public:

        template<typename F, typename...Args>
        Lazy(F&& f, Args&&... args):
            m_func(std::bind(std::forward<F>(f),std::forward<Args>(args)...)){}

        //const auto& get()
        const auto& get(){
            std::cout<<"At get return single data "<<std::endl;

            std::call_once(m_flag,[this](){m_data = std::make_unique<T>(m_func());})
            return *data;
        }

    private:
    std::unique_ptr <T> data;
    std::functional <T()> m_func;
    std::once_flag m_flag;
};

int main(){
    std::string str("Hello ");
    auto lazy_str = Lazy<std::string>([str](){return str;});
    std::cout<<lazy_str.get()<<std::endl;
}