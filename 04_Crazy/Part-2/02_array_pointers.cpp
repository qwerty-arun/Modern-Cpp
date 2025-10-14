// Make all DSP types derive from a common DSPModule interface. Then store an array of DSPModule*.

/*
Benefits:
- Type-safe (pointers share common base type).
- Allows virtual dispatch (process()).
- nullptr is a clear sentinel for "empty slot".
*/

// This example demonstrates the pattern end-to-end with assertions, lifetime safety and nullptr sentinel:

#include <array>
#include <cassert>
#include <iostream>
#include <algorithm>

// type-safe enumeration (scoped)
enum class DSP_Option
{
    Phase,
    Chorus,
    OverDrive,
    LadderFilter,
    END_OF_LIST
};

// base class
struct DSPModule
{
    virtual ~DSPModule() = default;
    //pure virtual function
    virtual void process() = 0;
};

struct Phaser : DSPModule
{
    //dynamic dispatch
    void process() override
    {
        std::cout << "Phaser\n";
    }
};

struct Chorus : DSPModule
{
    void process() override { 
        std::cout << "Chorus\n"; 
    }
};
struct OverDrive : DSPModule
{
    void process() override { 
        std::cout << "OverDrive\n"; 
    }
};
struct LadderFilter : DSPModule
{
    void process() override { 
        std::cout << "LadderFilter\n"; 
    }
};

// template aliasing

// DSP_Order is shorthand for an std::array that holds exactly 4 DSP_Option values.
using DSP_Order = std::array<DSP_Option, 4>;
// array of base class pointers
using DSP_Pointers = std::array<DSPModule *, 4>;

int main()
{
    Phaser phaser;
    Chorus chorus;
    OverDrive overdrive;
    LadderFilter ladderFilter;

    DSP_Order dspOrder = {DSP_Option::Phase, DSP_Option::Chorus, DSP_Option::OverDrive, DSP_Option::LadderFilter};
    DSP_Pointers dspPointers;
    dspPointers.fill(nullptr);

    auto n = std::min(dspPointers.size(), dspOrder.size());
    for (size_t i = 0; i < n; ++i)
    {
        switch (dspOrder[i])
        {
        case DSP_Option::Phase:
            dspPointers[i] = &phaser;
            break;
        case DSP_Option::Chorus:
            dspPointers[i] = &chorus;
            break;
        case DSP_Option::OverDrive:
            dspPointers[i] = &overdrive;
            break;
        case DSP_Option::LadderFilter:
            dspPointers[i] = &ladderFilter;
            break;
        case DSP_Option::END_OF_LIST:
            dspPointers[i] = nullptr;
            break;
        }
    }

    // Use the pointers safely
    for (auto *p : dspPointers)
    {
        if (p)
            p->process();
    }
}
