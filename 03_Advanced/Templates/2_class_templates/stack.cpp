/* Stack Implementation
Write a class template Stack<T> with push, pop, top, and size methods.
*/

#include <iostream>
#include <vector>
#include <stdexcept>

template<typename T>
class Stack {
    std::vector<T> data; // Using vector for dynamic resizing and storage

public:
    // Pushes an element onto the stack
    void push(const T& value) { data.push_back(value); }

    // Removes the top element from the stack
    void pop() {
        if (data.empty())
            throw std::out_of_range("Stack<>::pop(): empty stack");
        data.pop_back();
    }

    // Returns a reference to the top element
    const T& top() const {
        if (data.empty())
            throw std::out_of_range("Stack<>::top(): empty stack");
        return data.back();
    }

    // Returns the number of elements in the stack
    std::size_t size() const { return data.size(); }

    // Checks if the stack is empty
    bool empty() const { return data.empty(); }

    void display()
    {
        std::cout<<"Elements in the stack: "<<std::endl;
        for(auto element: data)
            std::cout<<element<<" ";
        std::cout<<std::endl;
    }
};

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();

    std::cout << "Top: " << s.top() << "\n";   // 30
    std::cout << "Size: " << s.size() << "\n"; // 3

    s.pop();
    std::cout << "Top after pop: " << s.top() << "\n"; // 20
    std::cout << "Size after pop: " << s.size() << "\n"; // 2

    return 0;
}