#include <iostream>

void printsubString(std::string_view str){
    std::cout<<"Sub String: "<<str<<std::endl;
}

void printString(std::string str){
    str+= "change";
    std::cout<<"Sub string "<<str<<std::endl;
}
/*
view -> const and took the reference
void printString(std::string_view srt){
    srt+= "change";
    std::cout<<"Sub string "<<srt<<std::endl;
}
*/
int main(){
    std::cout<<"string view"<<std::endl;
    std::string str = "Hello Everyone";
    str[7] = 'X';
    std::cout<<str<<std::endl;

    //Phase 2

    const char* srt = "Hello World";
    std::string_view view(srt,5); // string will only help you to access and works with 
    //references only... it show only first 5 character.

    //view[0] ='X'; it constant and will not allow any changes

    std::cout<<"std::string_view"<<view<<std::endl;

    //Phase 3
    std::string_view subString(str.c_str()+7,5);
    printsubString (subString);
    return 0;

}