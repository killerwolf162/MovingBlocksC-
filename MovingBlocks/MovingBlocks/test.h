#pragma once
// C++ program to illustrate the use of user-defined move
// assignment operator
#include <iostream>
#include <memory>
#include <utility>

using namespace std;

// dynamic array class
class DynamicArray {
private:
    size_t size_;
    int* data_;

public:
    // Constructor to create an array of a given size
    DynamicArray(size_t size)
        : size_(size)
        , data_(new int[size])
    {
        for (size_t i = 0; i < size; ++i) {
            data_[i] = 0; // Initialize all elements to 0
        }
    }

    // Move assignment operator
    DynamicArray& operator=(DynamicArray&& other) noexcept
    {
        // Make sure we're not assigning to ourselves
        if (this != &other) {
            // Release our current resources
            delete[] data_;

            // Take resources from 'other' and make them our
            // own
            size_ = other.size_;
            data_ = other.data_;

            // Reset 'other' to a valid but unspecified
            // state
            other.size_ = 0;
            other.data_ = nullptr;
        }
        return *this;
    }

    // Destructor to clean up resources
    ~DynamicArray() { delete[] data_; }

    // Function to print the array
    void print() const
    {
        for (size_t i = 0; i < size_; ++i) {
            cout << data_[i] << " ";
        }
        cout << endl;
    }
};

// driver code
int main()
{
    // Create an array with 5 elements, initially filled
    // with 0s
    DynamicArray arr1(5);
    // Create another array with 10 elements, initially
    // filled with 0s
    DynamicArray arr2(10);

    cout << "====== BEFORE MOVING ======" << endl;

    // Print the initial state of arr1
    cout << "arr1: ";
    arr1.print();

    // Print the initial state of arr2
    cout << "arr2: ";
    arr2.print();

    // Let's assign arr1 to arr2 using the move assignment
    // operator
    arr2 = std::move(arr1);

    // Print the state of arr1 after the move (it's in a
    // valid but unspecified state)
    cout << endl << "====== AFTER MOVING ======" << endl;
    cout << "arr1: ";
    arr1.print();

    // Print the state of arr2 after the move (now contains
    // the resources of arr1)
    cout << "arr2: ";
    arr2.print();

    return 0;
}