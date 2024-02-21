#include <iostream>
#include <functional>
#include <vector>
#include <string>

template <typename T>
class JetAirways {
private:
    void notifyObservers()
    {
        for (auto& observer : mObservers) {
            observer(mValue);
        }
    }

    T mValue;
    std::vector<std::function<void(const T&)>> mObservers;
public:
    JetAirways() = default;

    JetAirways(const T& value)
        : mValue(value){}

    JetAirways(T&& value)
        : mValue( std::move(value) ){}

    JetAirways& operator=(const T& value)
    {
        registerDetails(value);
        return *this;
    }

    JetAirways& operator=(T&& value)
    {
        registerDetails( std::move(value) ); 
        return *this;
    }

    template <typename Manger>
    void observe(Manger&& observer)
    {
        mObservers.emplace_back( std::forward< Manger >( observer) );
        observer( mValue );
    }

    void registerDetails(const T& value)
    {
        if (value != mValue) {
            mValue = value;
            notifyObservers();
        }
    }

    void registerDetails(T&& value)
    {
        if (value != mValue) {
            mValue = std::move(value);
            notifyObservers();
        }
    }

    void unregisterDetails(const std::function<void(const T&)>& observer)
    {
        mObservers.erase(mObservers.begin(), mObservers.end(), observer);
    }

    void setState(const bool state ){
        if (state) {
            std::cout<<"Flight is on Time: "<<mValue<<std::endl;
        } else {
            std::cout<<"Flight is not on Time: "<<mValue<<std::endl;
        }
    }
};

int main()
{
    JetAirways<std::string> data{" "}; 
    JetAirways<std::string> data1{""};
    data1.registerDetails("Koustubha");
    data.registerDetails("Mandira");
    data.setState(false);
    data1.setState(true);

    return 0;
}