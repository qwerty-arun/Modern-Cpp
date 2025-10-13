/*
Type alias:
In C++, a type alias is a name that serves as a synonym for an existing type. It lets you give more readable or convenient names to types, especially long or complex ones, without creating new types.

using NewName = ExistingType;
This is equivalent to the older typedef but clearer and more versatile, especially with templates.

Benefits
- Simplifies code readability when types are complex (e.g., function pointers, template instantiations).
- Allows easy changing of type across the codebase by updating the alias.
- Works better with templates compared to typedef.
*/

#include <iostream>

int main(){
    using Integer = int;
    using FloatPtr = float*;

    Integer a = 10;
    FloatPtr p = nullptr;

    std::cout<< a << std::endl;
    std::cout<< p << std::endl;

    // Alias Template
    template<typename T>
    using Ptr = T*;
    Ptr<int> p = nullptr;  // same as int* p = nullptr

    return 0;
}