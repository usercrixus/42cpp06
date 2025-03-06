#include <iostream>
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data data;
    data.number = 42;
    data.text = "Hello, Serialization!";

    // Serialize the pointer
    uintptr_t raw = Serializer::serialize(&data);

    // Deserialize it back
    Data* deserializedPtr = Serializer::deserialize(raw);

    // Verify the conversion
    std::cout << "Original Data Address: " << &data << std::endl;
    std::cout << "Serialized Value: " << raw << std::endl;
    std::cout << "Deserialized Data Address: " << deserializedPtr << std::endl;

    // Ensure data is intact
    std::cout << "Deserialized Data -> number: " << deserializedPtr->number << std::endl;
    std::cout << "Deserialized Data -> text: " << deserializedPtr->text << std::endl;

    // Check if the deserialized pointer matches the original
    if (deserializedPtr == &data) {
        std::cout << "✅ Serialization and Deserialization SUCCESS!" << std::endl;
    } else {
        std::cout << "❌ Serialization and Deserialization FAILED!" << std::endl;
    }

    return 0;
}
