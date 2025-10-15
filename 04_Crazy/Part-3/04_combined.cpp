#include <iostream>
#include <string>
#include <vector>

class Settings
{
public:
    Settings(std::string name, std::vector<std::string> params)
        : name(name), parameters(std::move(params))
    {
        std::cout << "Settings created for: " << name << std::endl;
    }

    void print() const
    {
        std::cout << "Parameters: ";
        for (const auto& p : parameters)
            std::cout << p << " ";
        std::cout << "\n";
    }

private:
    std::string name;
    std::vector<std::string> parameters;
};

class MyProcessor
{
public:
    // 🔹 1. Static factory function
    static std::vector<std::string> createParameterLayout()
    {
        // Imagine these are your plugin parameters
        return { "Gain", "Cutoff", "Resonance" };
    }

    // 🔹 2. Member initialization using static factory
    MyProcessor()
        : settings("MyProcessor", createParameterLayout()) // calls static fn here
    {
        std::cout << "Processor constructed.\n";
    }

    void printSettings() const
    {
        settings.print();
    }

private:
    Settings settings; // member variable
};

int main()
{
    MyProcessor processor;
    processor.printSettings();
}
