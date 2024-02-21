#include <functional>
#include <vector>

template <typename T>
class LiveData {
public:
    LiveData() = default;

    LiveData(const T& value)
        : mValue(value)
    {
    }

    LiveData(T&& value)
        : mValue( std::move(value) )
    {
    }

    template <typename U>
    LiveData& operator=(U&& value)
    {
        setValue( std::forward<U>(value) );
        return *this;
    }

    template <typename Observer>
    void observe(Observer&& observer)
    {
        mObservers.emplace_back( std::forward< Observer >( observer) );
        observer( mValue );
    }

    template <typename U>
    void setValue(U&& value)
    {
        if (value != mValue) {
            mValue = std::forward<U>(value);
            notifyObservers();
        }
    }

private:
    void notifyObservers()
    {
        for (auto& observer : mObservers) {
            observer(mValue);
        }
    }

private:
    T mValue;
    std::vector<std::function<void(const T&)>> mObservers;
};

#include <iostream>

int main()
{
    LiveData<int> data{42}; // data : T type is copy-constructible.

    data.observe(  [](const auto& value) {
        std::cout << "Observer 1: " << value << std::endl;
    });

    data.observe([](const auto& value) {
        std::cout << "Observer 2: " << value << std::endl;
    });

    data.setValue(43);
    data.setValue(44);

    return 0;
}