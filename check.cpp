#include <iostream>
#include <vector>
#include <memory>

int main() {
    // Using auto keyword for type inference
    std::vector<int> numbers = {1, 2, 3, 4, 5};

    // Range-based for loop
    std::cout << "Numbers in the vector: ";
    for (const auto& number : numbers) {
        std::cout << number << " ";
    }
    std::cout << std::endl;

    // Lambda function
    auto square = [](int x) { return x * x; };

    // Using standard algorithms
    std::cout << "Squared numbers: ";
    for (const auto& number : numbers) {
        std::cout << square(number) << " ";
    }
    std::cout << std::endl;

    // C++11 smart pointer
    auto sharedPtr = std::make_shared<int>(42);

    // nullptr instead of NULL
    if (sharedPtr != nullptr) {
        std::cout << "Shared pointer value: " << *sharedPtr << std::endl;
    }

    // Automatic type deduction with decltype
    decltype(numbers) otherVector = {6, 7, 8, 9, 10};

    std::cout << "Other vector size: " << otherVector.size() << std::endl;

    return 0;
}
