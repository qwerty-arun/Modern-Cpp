#include <iostream>
#include <array>
#include <memory>
#include <vector>

/*
This example covers:
✅ enum class
✅ using type alias
✅ std::array
✅ template<typename T>
✅ inheritance and method overriding
✅ creating and using objects dynamically (polymorphism)

🧠 Final Goal:
- We’ll build a tiny “Effect Chain” simulation, like this:
- Each effect (Phase, Chorus, Overdrive, Filter) just prints what it’s doing.
- We’ll have a templated wrapper (EffectChoice<T>) similar to your DSP_Choice.
- Then we’ll make a vector of effects and call them in order — just like a DSP chain.
*/

// =============================================================
// 1️⃣  Enum class - list of effects
// =============================================================
enum class EffectType
{
    Phase,
    Chorus,
    Overdrive,
    Filter,
    END_OF_LIST
};

// =============================================================
// 2️⃣  Type alias for array of all effects
// =============================================================
using EffectOrder = std::array<EffectType, static_cast<size_t>(EffectType::END_OF_LIST)>;

// =============================================================
// 3️⃣  Base class (like juce::dsp::ProcessorBase)
// =============================================================
struct EffectBase
{
    virtual void prepare() = 0;
    virtual void process() = 0;
    virtual void reset() = 0;
    virtual ~EffectBase() = default;
};

// =============================================================
// 4️⃣  Example DSPs (simple effects)
// =============================================================
struct PhaseEffect
{
    void prepare() { std::cout << "PhaseEffect: prepare()\n"; }
    void process() { std::cout << "PhaseEffect: processing audio\n"; }
    void reset()   { std::cout << "PhaseEffect: reset()\n"; }
};

struct ChorusEffect
{
    void prepare() { std::cout << "ChorusEffect: prepare()\n"; }
    void process() { std::cout << "ChorusEffect: processing audio\n"; }
    void reset()   { std::cout << "ChorusEffect: reset()\n"; }
};

// =============================================================
// 5️⃣  Template wrapper (like DSP_Choice<DSP>)
// =============================================================
template<typename Effect>
struct EffectChoice : EffectBase
{
    void prepare() override { effect.prepare(); }
    void process() override { effect.process(); }
    void reset()   override { effect.reset(); }

    Effect effect;  // the actual effect instance
};

// =============================================================
// 6️⃣  Main program
// =============================================================
int main()
{
    //  Create some effect objects dynamically (polymorphism)
    std::vector<std::unique_ptr<EffectBase>> effectChain;

    effectChain.push_back(std::make_unique<EffectChoice<PhaseEffect>>());
    effectChain.push_back(std::make_unique<EffectChoice<ChorusEffect>>());

    //  Simulate the DSP lifecycle
    std::cout << "=== Preparing effects ===\n";
    for (auto& fx : effectChain) fx->prepare();

    std::cout << "\n=== Processing audio ===\n";
    for (auto& fx : effectChain) fx->process();

    std::cout << "\n=== Resetting effects ===\n";
    for (auto& fx : effectChain) fx->reset();

    return 0;
}
