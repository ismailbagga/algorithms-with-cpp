//
// Created by ismail-bagga on 2/3/25.
//

#include "DynamicArray.h"

#include <iostream>
#include <stdexcept>

#include "StaticArray.h"


namespace datastructures {
    DynamicArray::DynamicArray() : DynamicArray(16) {
    }

    DynamicArray::DynamicArray(const int *array, const int size) : DynamicArray(size) {
        this->size = size;
        for (int index = 0; index < size; index++) {
            this->array[index] = array[index];
        }
    }

    DynamicArray::DynamicArray(const int size) {
        this->capacity = size * 2;
        this->size = 0;
        this->array = new int[this->capacity];
    }

    void DynamicArray::display() const {
        std::cout << "Array: [";

        for (int i = 0; i < this->size; i++) {
            std::cout << this->array[i];
            if (i != this->size - 1) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }

    std::string DynamicArray::toString() const {
        std::string representation = "Array [";
        for (int i = 0; i < size; i++) {
            representation += std::to_string(array[i]);
            if (i != size - 1) {
                representation += ",";
            }
        }
        representation += ']';
        return representation;
    }

    int DynamicArray::getSize() const {
        return this->size;
    }

    int DynamicArray::get(const int index) const {
        if (index < 0 || index >= this->size) {
            throw std::invalid_argument("index is out of range");
        }
        return this->array[index];
    }

    int DynamicArray::indexOf(int value) const {
        for (int index = 0; index < this->size; index++) {
            if (this->array[index] == value) return index;
        }
        return -1;
    }

    int DynamicArray::contains(const int value) const {
        return indexOf(value) != -1;
    }

    int DynamicArray::binarySearch(const int value) const {
        int start = 0;
        int end = size - 1;



        while (start <= end) {
            const int mid = start + (end - start) / 2;
            const int midValue = array[mid];
            if (midValue == value) return mid;
            if (midValue > value) end = mid - 1;
            else start = mid + 1;
        }

        return -1;


        return indexOf(value);
    }

    void DynamicArray::set(const int index, const int value) const {
        if (index < 0 || index >= this->size)
            throw std::invalid_argument("Invalid Index");

        this->array[index] = value;
    }


    void DynamicArray::expand_array() {
        capacity *= 2;
        const auto newArray = new int[capacity];
        for (int index = 0; index < size; index++) {
            newArray[index] = this->array[index];
        }

        delete[] this->array;
        this->array = newArray;
    }

    void DynamicArray::insert(const int insertAt, const int value) {
        if (insertAt < 0 || insertAt > size)
            throw std::invalid_argument("index must be between 0 to " + size);
        if (size >= capacity) {
            expand_array();
        }

        for (int index = size - 1; index >= insertAt; index--) {
            array[index + 1] = array[index];
        }
        array[insertAt] = value;
        size++;
    }

    void DynamicArray::leftShiftingInsert(const int insertAt, const int value) {
        if (insertAt < 0 || insertAt >= size)
            throw std::invalid_argument("");
        if (size >= capacity) {
            expand_array();
        }
        int prevValue = array[insertAt];
        int storedValue = 0;

        for (int index = insertAt; index < size; index++) {
            storedValue = array[index + 1];
            array[index + 1] = prevValue;
            prevValue = storedValue;
        }
        size++;
    }

    void DynamicArray::insertAtTail(const int value) {
        insert(size, value);
    }


    void DynamicArray::insertAtHead(const int value) {
        insert(0, value);
    }

    int DynamicArray::remove(const int index) {
        if (index < 0 || index >= size || size == 0)
            throw std::invalid_argument("Invalid Index");

        if (size < capacity / 2) {
            shrinking_array();
        }

        const auto valueToRemove = array[index];

        for (int i = index; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        array[size - 1] = 0;
        size--;
        return valueToRemove;
    }

    int DynamicArray::pop() {
        return remove(size - 1);
    }


    void DynamicArray::shrinking_array() {
        capacity /= 2;
        const auto newArray = new int[capacity];

        for (int index = 0; index < size; index++) {
            newArray[index] = this->array[index];
        }
        delete[] this->array;
        this->array = newArray;
    }
}
