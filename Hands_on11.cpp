#include <iostream>
#include <stdexcept>

class DynamicArray {
private:
    int* data;       // Pointer to the array
    int capacity;    // Current capacity of the array
    int size;        // Current number of elements in the array

    // Helper function to resize the array when needed
    void resize(int newCapacity) {
        int* newData = new int[newCapacity];
        for (int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

public:
    DynamicArray() : data(new int[1]), capacity(1), size(0) {}

    ~DynamicArray() {
        delete[] data;
    }

    int getSize() const {
        return size;
    }

    int getCapacity() const {
        return capacity;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    void set(int index, int value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        data[index] = value;
    }

    void push(int value) {
        if (size == capacity) {
            resize(2 * capacity);  // Double the capacity if size reaches capacity
        }
        data[size++] = value;
    }

    void pop() {
        if (isEmpty()) {
            throw std::out_of_range("Array is empty");
        }
        --size;
        if (size <= capacity / 4) {
            resize(capacity / 2);  // Shrink capacity if the array is only a quarter full
        }
    }

    int getAt(int index) const {
        return get(index);
    }

    void insert(int index, int value) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }
        if (size == capacity) {
            resize(2 * capacity);
        }
        for (int i = size; i > index; --i) {
            data[i] = data[i - 1];
        }
        data[index] = value;
        ++size;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (int i = index; i < size - 1; ++i) {
            data[i] = data[i + 1];
        }
        --size;
        if (size <= capacity / 4) {
            resize(capacity / 2);
        }
    }
};

int main() {
    DynamicArray arr;
    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.insert(1, 4);
    arr.remove(2);

    for (int i = 0; i < arr.getSize(); ++i) {
        std::cout << arr.getAt(i) << " ";
    }
    std::cout << std::endl;

    return 0;
}
