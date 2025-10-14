/*
Default Sentinel Pattern
Used to safely update state from a lock-free FIFO

💡 Why use this trick?

This pattern is simple, thread-safe, and allocation-free — perfect for audio threads where you can’t lock or allocate memory.

Typical goals:
- Non-blocking communication between threads (GUI thread pushes new settings → audio thread polls FIFO).
- Avoid explicit flags like bool newDataAvailable, which can introduce race conditions.
- Avoid std::optional to stay allocation-free.

Purpose: Keep pulling from a FIFO until empty → if any new value was received (i.e., not default), update the DSP parameter/state.

⚙️ Why This Matters

This simple trick:
- avoids extra flags (bool newDataAvailable)
- prevents stale updates
- uses default construction as a “no value” sentinel
- and works perfectly in audio threads (if the FIFO is lock-free).
*/

#include <iostream>
#include <queue>
#include <mutex>
#include <optional>

// A simple struct that represents some DSP order or command
struct DSP_Order {
    int orderID = 0; // default 0 = "no command"

    // comparison operator to allow ==, !=
    bool operator==(const DSP_Order& other) const {
        return orderID == other.orderID;
    }
    bool operator!=(const DSP_Order& other) const {
        return !(*this == other);
    }
};

// A very simple thread-safe FIFO (not lock-free, just conceptual)
class DSP_Fifo {
public:
    bool push(const DSP_Order& order) {
        std::lock_guard<std::mutex> lock(mutex_);
        queue_.push(order);
        return true;
    }

    bool pull(DSP_Order& out) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (queue_.empty())
            return false;
        out = queue_.front();
        queue_.pop();
        return true;
    }

private:
    std::queue<DSP_Order> queue_;
    std::mutex mutex_;
};

//-----------------------------------
// main illustrating the trick
//-----------------------------------
int main() {
    DSP_Fifo dspOrderFifo;
    DSP_Order dspOrder; // current active order

    // Simulate other thread pushing some commands
    dspOrderFifo.push({1});
    dspOrderFifo.push({2});
    dspOrderFifo.push({3});

    // Now, simulate the audio thread trying to fetch latest
    auto newDSPOrder = DSP_Order(); // default constructed (orderID = 0)

    while (dspOrderFifo.pull(newDSPOrder)) {
        // keep pulling to get the *latest* one
    }

    // If we pulled anything, it won't equal the default DSP_Order()
    if (newDSPOrder != DSP_Order()) {
        dspOrder = newDSPOrder;
    }

    std::cout << "Latest DSP order is: " << dspOrder.orderID << "\n";
}
