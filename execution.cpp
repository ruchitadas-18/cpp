#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <execution>
int numElems = 1000;
 
int main() {
    std::vector<int> nums = {5, 2, 4, 1, 3};
    for (int i = 0; i < numElems; ++i) {
        nums.emplace_back( i * 10);
    }
 
    std::cout << "Parallel Execution!\n";
 
     //start the timer
    auto startTime = std::chrono::high_resolution_clock::now();
 
    //parallel execution
    // std::for_each(std::execution::par, nums.begin(), nums.end(), [](int& num){num+=2;});
 
    //sequential execution
    std::for_each(std::execution::seq, nums.begin(), nums.end(), [](int& num){num+=2;});
 
     //stop the timer
    auto endTime = std::chrono::high_resolution_clock::now();
   
 
    //calculate the elapsed time
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime-startTime);
 
    //print the modified vector
    std::cout<<"Modified vector: "<<std::endl;
    for(int num:nums){
        std::cout<<num<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"Execution time:"<<duration.count()<<" microsec. "<<std::endl;
    return 0;
}
