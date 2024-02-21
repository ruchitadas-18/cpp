#include <future>
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int main() {
    // Create a package task that wraps the add function
    std::packaged_task<int(int, int)> task(add);

    // Create a future object that can be used to retrieve the result of the task
    std::future<int> result = task.get_future();

    // Invoke the task asynchronously
    std::thread(std::move(task), 10, 20).detach();

    // Retrieve the result of the task
    int sum = result.get();

    std::cout << "Sum: " << sum << std::endl;

    return 0;
}

// void extractDelay(){
//     for(int i=0; i<80000; i++){
//         for(int ii =0; ii<80000; ii++){
            
//         }
//     }
// }
// int main(){
// //we use std::package_task, which can be used to wrap any target that can called as async calls
//     std::packaged_task<int()> task([](){
//         std::this_thread::sleep_for(std::chrono::seconds(3));
//         return 12345;
//     });

//     std::future<int> result = task.get_future();
//     std::thread(std::move(task)).detach();
//     result.wait();
//     std::cout<<"DOne!"<<std::endl<< result.get()<<std::endl;
// }
