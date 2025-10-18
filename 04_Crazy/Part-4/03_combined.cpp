/*
We’ll build:
- A few parameter variables (like rate, depth, etc.)
- Functions that return the parameter names
- Arrays to hold pointers to those variables and function pointers
- A loop that initializes everything — just like your plugin code.
*/

#include <iostream>
#include <string>
#include <array>

// pretend these are your plugin parameters
float* rate = nullptr;
float* depth = nullptr;
float* feedback = nullptr;

// these "functions" represent getPhaserRateName(), etc.
std::string getRateName()     { return "Rate"; }
std::string getDepthName()    { return "Depth"; }
std::string getFeedbackName() { return "Feedback"; }

// pretend we have a "parameter map" like the apvts
float getParameterFromSystem(const std::string& name)
{
    if (name == "Rate") return 0.5f;
    if (name == "Depth") return 0.8f;
    if (name == "Feedback") return -0.3f;
    return 0.0f;
}

int main()
{
    // array of pointers to your member variables
    auto paramPointers = std::array{ &rate, &depth, &feedback };

    // array of function pointers that return names
    auto nameFuncs = std::array{
        &getRateName,
        &getDepthName,
        &getFeedbackName
    };

    // initialize each variable using the loop
    for (size_t i = 0; i < paramPointers.size(); ++i)
    {
        auto ptrToParamPtr = paramPointers[i];   // float** (pointer to pointer)
        std::string name = nameFuncs[i]();       // call function to get name

        // allocate memory and assign value
        *ptrToParamPtr = new float(getParameterFromSystem(name));
    }

    // print the results
    std::cout << "Rate: " << *rate << "\n";
    std::cout << "Depth: " << *depth << "\n";
    std::cout << "Feedback: " << *feedback << "\n";

    // cleanup
    delete rate;
    delete depth;
    delete feedback;

    return 0;
}
