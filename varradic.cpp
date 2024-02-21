//string streamer and string tokenizer
#include <iostream>
 
template <typename T>
void print(const T& t){
    std::cout<<"in me: "<<t<<std::endl;
}
 
template <typename first, typename... rest>
void print(const first& f, const rest&...r){
    // for debugging
    std::cout<<__PRETTY_FUNCTION__<<std::endl;
 
    std::cout<<f<<" "; // printing first part
    print(r...); // recursion for rest part
}

//fold expression
template<typename... T>
auto AddRecur( T ...t){
    return ( t +...);
}

int main(){
    //first template
    print(123);
 
    // second template
    print(1,"One", 2, "Two", 3, "Three");

    std::cout << " Sum from Fold expression "<<AddRecur(1,2,3,4,5.55,6,7,8,9,10);
    return 0;
}