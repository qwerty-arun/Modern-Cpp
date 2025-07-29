// Write a template function that calculates the sum of elements in an array of any type

#include <iostream>
using namespace std;

template <typename T>
T sum(T a[], int length) {
    T ret = a[0];
    for (int i = 1; i < length; i++)
        ret += a[i];
    return ret;
}

int main() {
    int int_data[5] = {1, 2, 3, 4, 5};
    float float_data[5] = {1.3f, 2.3f, 3.5f, 4.3f, 2.1f};

    cout << "Sum of integers: " << sum(int_data, sizeof(int_data) / sizeof(int_data[0])) << endl;   // Outputs 15
    cout << "Sum of floats: " << sum(float_data, sizeof(float_data) / sizeof(float_data[0])) << endl;   // Outputs 13.5
    return 0;
}