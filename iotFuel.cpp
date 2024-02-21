//
//  main.cpp
//  Signal
//
//  Created by Sathya Babu on 15/02/24.
//

#include <iostream>
#include <unistd.h> // for alarm function
#include <csignal>

volatile sig_atomic_t flag = 0 ;

void handle_alarm( int ){
    flag = 1 ;
}

void somefunction() {
    while( !flag ){
        // do dome work
        std::cout << "some fun called \n";
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    std::signal(SIGALRM, handle_alarm);
    alarm( 2 );
    somefunction();
    if( flag ){
        std::cout << "terminated due to time out!\n";
    }else{
        std::cout << "fun completed with in time limit!\n";
    }
    return 0;
}