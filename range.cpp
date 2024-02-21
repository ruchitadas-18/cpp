#include <iostream>
#include <ranges>
#include <vector>

auto range(int start, int end){
    return std::views::iota(start,end);
}

struct MyRange{
    int data [5] = {10,11,12,13,14};
    auto begin() const {return std::begin(data);}
    auto end() const -> decltype( std::end(data)) {return std::end(data);}
};

template<class T>
concept Range = requires(T& t){
    std::ranges::begin(t);
    std::ranges::end(t);
};

template<Range R>
void printRange(const R& r){
    for (const auto& value: r){
        std::cout<<"R"<<value<<" ";
    }
}

int main(){

    std::vector<int> number = {1,2,3,4,5,6};

    for(int i: std::views::iota(1,10)){
        std::cout<<i<<" ";
    }

    std::cout<<" "<<std::endl;
    for(int i: std::ranges::iota_view(1,10)){ //lazy range
        std::cout<<i<<" ";
    }

    for(int n: {1,2,3,4,5}){
        std::cout<<n<<" ";
    }

    for(int n : range(1,10)){
        std::cout<<n<<" ";
    }

    MyRange myrange;
    printRange(myrange.data);

    for(int n: myrange.data){
        std::cout<<n<<" ";
    }
    return 0;
}