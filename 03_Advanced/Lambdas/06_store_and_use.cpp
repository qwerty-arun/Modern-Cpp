// You can pass lambdas to functions that take std::function
#include <iostream>
#include <functional>

void callTwice(std::function<void()> func)
{
    func();
    func();
}

int main()
{
    int counter = 0;
    callTwice([&]()
              {
        counter++;
        std::cout << "Counter: " << counter << std::endl; });
}
