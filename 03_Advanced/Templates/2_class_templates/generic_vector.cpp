/*
Generic Vector
Build a simple Vector<T> class with dynamic memory (mimic std::vector behavior).
*/

#include <iostream>
#include <stdexcept>

template<typename T>
class Vector {
    T* data;
    size_t sz;
    size_t cap;

    void resize(size_t new_cap) {
        T* new_data = new T[new_cap];
        for (size_t i = 0; i < sz; ++i)
            new_data[i] = data[i];
        delete[] data;
        data = new_data;
        cap = new_cap;
    }

public:
    // Constructor
    Vector() : data(new T[1]), sz(0), cap(1) {}

    // Destructor
    ~Vector() { delete[] data; }

    // Add element at the end
    void push_back(const T& value) {
        if (sz == cap)
            resize(2 * cap);
        data[sz++] = value;
    }

    // Remove element at the end
    void pop_back() {
        if (sz > 0) --sz;
        // Optional: shrink capacity
    }

    // Element access
    T& operator[](size_t index) {
        if (index >= sz) throw std::out_of_range("index out of range");
        return data[index];
    }

    const T& operator[](size_t index) const {
        if (index >= sz) throw std::out_of_range("index out of range");
        return data[index];
    }

    // Return current size
    size_t size() const { return sz; }

    // Return current capacity
    size_t capacity() const { return cap; }
};

int main() {
    Vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;

    v.pop_back();
    std::cout << "Size after pop: " << v.size() << std::endl;

    return 0;
}