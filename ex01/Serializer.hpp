#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <stdint.h>
#include "Data.hpp"

class Serializer {
private:
    // Private constructor to prevent instantiation
    Serializer();
    ~Serializer();
    Serializer(const Serializer&);
    Serializer& operator=(const Serializer&);

public:
    // Convert pointer to integer
    static uintptr_t serialize(Data* ptr);

    // Convert integer back to pointer
    static Data* deserialize(uintptr_t raw);
};

#endif
