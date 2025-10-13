/*
What is enum class in C++?
enum class provides a type-safe, strongly scoped enumeration type. The enumerator names are scoped to the enum type, not to the containing scope, and they are not implicitly convertible to integers or other enums.

Key Differences from Basic enum:-
- The enumerator names are only accessible with the enum class name as a qualifier (e.g., Color::Red).
- No implicit conversion to int.
- Prevents accidental misuse and name conflicts.

Advantages:-
- Type safety: Comparisons between different enums, or enums and integers, are disallowed.
- Scoped names: Reduces chances of naming collisions in large systems.
- Explicitness: Code is clearer and harder to misuse.
*/

#include <iostream>

enum Color { Red, Green, Blue };             // Traditional enum
enum Flower {Rose, Jasmine, Sunflower};
enum class TrafficLight { Red, Yellow, Green }; // Scoped enum

int main() {
    Color c = Green;                          // OK
    // int n = TrafficLight::Green;           // error: no implicit conversion

    TrafficLight t = TrafficLight::Red;       // Must use scope resolution
    if (t == TrafficLight::Red) {
        std::cout << "Red light\n";
    }

    // if (c == t) {} // error: cannot compare different enum types

    // Explicity case each enum member to a common underlying type if you want to compare
    if (static_cast<int>(Color::Red) == static_cast<int>(TrafficLight::Red)) {
    // Comparison logic
    std::cout << "Huh";
    }

    return 0;
}
