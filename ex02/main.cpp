#include "Functions.hpp"

int main() {
    Base* obj = generate(); // Randomly create A, B, or C

    std::cout << "Identify with pointer: ";
    identify(obj); // Identify using pointer

    std::cout << "Identify with reference: ";
    identify(*obj); // Identify using reference

    delete obj; // Clean up memory
    return 0;
}
