#include "Functions.hpp"
#include <cstdlib>  // For rand()
#include <ctime>    // For time()

// Generates a random instance of A, B, or C
Base* generate(void) {
    std::srand(std::time(0)); // Seed the random generator
    int random = std::rand() % 3;

    if (random == 0) return new A();
    if (random == 1) return new B();
    return new C();
}

// Identifies the type using a pointer
void identify(Base* p) {
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown Type" << std::endl;
    }
}

// Identifies the type using a reference (Fixed version without exceptions)
void identify(Base& p) {
    if (dynamic_cast<A*>(&p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(&p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(&p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown Type" << std::endl;
    }
}
