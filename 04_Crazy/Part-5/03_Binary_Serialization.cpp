/*
Goal: Serialize a list of DSP options (enums) into binary data and then deserialize it back.

🧠 Step-by-step Goal
- Define an enum class DSP_Option.
- Define a type alias DSP_Order (array or vector of DSP_Option).
- Implement a generic Converter template.
- Specialize it for DSP_Order:
    - toBinary() → converts enum list to bytes.
    - fromBinary() → converts bytes back to enum list.
- Demonstrate round-trip conversion.

Concepts and their Description:
1) Enum Serialization: Stored enum values as integers in binary (4 bytes each). 
2) Template Specialization: Converter<DSP_Order> provides custom behavior only for that type.
3) Binary Encoding/Decoding: Manual byte-level read/write, mimicking JUCE’s MemoryInputStream and MemoryOutputStream.
4) Static Functions: Used so no object needs to be created to call the converter.
*/

#include <iostream>
#include <vector>
#include <cstdint>
#include <sstream>
#include <iomanip>

// ================================================
// 1. Custom Enum representing DSP Options
// ================================================
enum class DSP_Option : int
{
    Phaser = 0,
    Chorus,
    Delay,
    Filter,
    END_OF_LIST
};

// ================================================
// 2. Define DSP_Order as a sequence of DSP_Option
// ================================================
using DSP_Order = std::vector<DSP_Option>;

// Helper for printing
std::ostream& operator<<(std::ostream& os, DSP_Option opt)
{
    switch (opt)
    {
        case DSP_Option::Phaser: os << "Phaser"; break;
        case DSP_Option::Chorus: os << "Chorus"; break;
        case DSP_Option::Delay: os << "Delay"; break;
        case DSP_Option::Filter: os << "Filter"; break;
        default: os << "End"; break;
    }
    return os;
}

// ================================================
// 3. Generic Template (default version)
// ================================================
template <typename T>
struct Converter
{
    static std::vector<uint8_t> toBinary(const T&)
    {
        std::cout << "Generic Converter: no implementation.\n";
        return {};
    }

    static T fromBinary(const std::vector<uint8_t>&)
    {
        std::cout << "Generic Converter: no implementation.\n";
        return {};
    }
};

// ================================================
// 4. Template Specialization for DSP_Order
// ================================================
template <>
struct Converter<DSP_Order>
{
    // Convert DSP_Order -> bytes
    static std::vector<uint8_t> toBinary(const DSP_Order& order)
    {
        std::vector<uint8_t> bytes;
        for (auto opt : order)
        {
            int val = static_cast<int>(opt);
            // store int as 4 bytes (little-endian)
            for (int i = 0; i < 4; ++i)
                bytes.push_back((val >> (i * 8)) & 0xFF);
        }
        return bytes;
    }

    // Convert bytes -> DSP_Order
    static DSP_Order fromBinary(const std::vector<uint8_t>& bytes)
    {
        DSP_Order order;
        for (size_t i = 0; i + 3 < bytes.size(); i += 4)
        {
            int val = bytes[i] | (bytes[i + 1] << 8) |
                      (bytes[i + 2] << 16) | (bytes[i + 3] << 24);
            order.push_back(static_cast<DSP_Option>(val));
        }
        return order;
    }
};

// ================================================
// 5. Demo
// ================================================
int main()
{
    DSP_Order original = { DSP_Option::Phaser, DSP_Option::Chorus, DSP_Option::Filter };

    // Serialize to bytes
    auto bytes = Converter<DSP_Order>::toBinary(original);

    std::cout << "Serialized bytes: ";
    for (auto b : bytes)
        std::cout << std::setw(2) << std::setfill('0') << std::hex << (int)b << " ";
    std::cout << std::dec << "\n";

    // Deserialize back
    DSP_Order restored = Converter<DSP_Order>::fromBinary(bytes);

    std::cout << "Restored DSP Order: ";
    for (auto opt : restored)
        std::cout << opt << " ";
    std::cout << "\n";
}
