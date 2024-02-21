#include <iostream>
#include <memory>
 
std::weak_ptr<int> gw; // weak pointer
 
void observe()
{
    std::cout << "gw.use_count() == " << gw.use_count() << "; ";
    // we have to make a copy of shared pointer before usage and getting the refrence count
    //refrence count = 1;
    if (std::shared_ptr<int> spt = gw.lock())
    // = is used because gw.lock is giving some value which is checking the value.
    //the weak pointer is locked because it is in unname class 
    // to have it value it have to be locked
        std::cout << "*spt == " << *spt << '\n';
    else
        std::cout << "gw is expired\n";
}
 
int main()
{
    //unnamed space
    {
        auto sp = std::make_shared<int>(42);
        //making a copy of shared pointer 
        gw = sp;
 
        observe();
    }
 
    observe();
    //when observe is called outside of the unname space 
    //as soon as it come out of the space it will die.
}