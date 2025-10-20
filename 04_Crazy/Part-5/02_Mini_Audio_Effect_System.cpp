/*
The following concepts are used:
✅ Encapsulation
✅ Composition
✅ Pointers and -> operator
✅ Static casting
✅ Templates
✅ Atomic (thread-safety)
✅ Member access & method calls

This structure mimics what JUCE’s AudioProcessor + DSP modules do:
- Each DSP object (Phaser, Filter, etc.) is encapsulated.
- The main processor composes multiple DSP units.
- Parameters are atomic (thread-safe).
- Values are pushed into DSP objects via pointers and method calls.
- Type conversions (enum selection) are done with static_cast.
*/
#include <iostream>
#include <atomic>
#include <string>

// ======================
// 1. Enum and Static Cast
// ======================
enum class FilterMode
{
    LowPass,
    HighPass,
    BandPass
};

// Helper to print enum (for display)
std::string toString(FilterMode mode)
{
    switch (mode)
    {
        case FilterMode::LowPass:  return "LowPass";
        case FilterMode::HighPass: return "HighPass";
        case FilterMode::BandPass: return "BandPass";
    }
    return "Unknown";
}

// ======================
// 2. Simple DSP “Processors”
// ======================
struct Phaser
{
    void setRate(float newRate) { rate = newRate; }
    void setDepth(float newDepth) { depth = newDepth; }
    void print() const {
        std::cout << "Phaser [rate=" << rate << ", depth=" << depth << "]\n";
    }
private:
    float rate = 0.0f;
    float depth = 0.0f;
};

struct Filter
{
    void setCutoff(float newCutoff) { cutoff = newCutoff; }
    void setMode(FilterMode newMode) { mode = newMode; }
    void print() const {
        std::cout << "Filter [cutoff=" << cutoff << ", mode=" << toString(mode) << "]\n";
    }
private:
    float cutoff = 0.0f;
    FilterMode mode = FilterMode::LowPass;
};

// ======================
// 3. Template DSP Wrapper (Composition)
// ======================
template <typename DSPType>
struct Effect
{
    DSPType dsp;     // Composition: this struct "has a" DSPType
    bool isActive = true;
};

// ======================
// 4. Main Audio Processor (Encapsulation)
// ======================
struct AudioProcessor
{
    // Composition: processor contains different effects
    Effect<Phaser> phaser;
    Effect<Filter> filter;

    // Thread-safe parameters (simulate GUI knobs)
    std::atomic<float> phaserRateHz{ 1.0f };
    std::atomic<float> phaserDepthPercent{ 50.0f };
    std::atomic<float> filterCutoffHz{ 800.0f };
    std::atomic<int> filterModeIndex{ 0 }; // 0 = LowPass, 1 = HighPass, 2 = BandPass

    void updateParameters()
    {
        // Pointers and arrow operator
        std::atomic<float>* ratePtr = &phaserRateHz;
        std::atomic<float>* depthPtr = &phaserDepthPercent;

        // Member access through pointers
        phaser.dsp.setRate(ratePtr->load());
        phaser.dsp.setDepth(depthPtr->load());

        // Static cast to convert int → enum
        FilterMode mode = static_cast<FilterMode>(filterModeIndex.load());
        filter.dsp.setMode(mode);
        filter.dsp.setCutoff(filterCutoffHz.load());
    }

    void printStatus()
    {
        phaser.dsp.print();
        filter.dsp.print();
    }
};

// ======================
// 5. Main Function
// ======================
int main()
{
    AudioProcessor processor;

    // Simulate user changing GUI parameters
    processor.phaserRateHz.store(2.5f);
    processor.phaserDepthPercent.store(80.0f);
    processor.filterCutoffHz.store(2000.0f);
    processor.filterModeIndex.store(1); // HighPass

    // Sync parameters with DSP objects
    processor.updateParameters();

    // Print current DSP settings
    processor.printStatus();

    return 0;
}
