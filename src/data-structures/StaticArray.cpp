//
// Created by ismail-swe on 12/29/24.
//

#include "StaticArray.h"

#include <iostream>
#include <stdexcept>
using namespace datastructures;

StaticArray::StaticArray() : StaticArray(16) {
}

StaticArray::StaticArray(const int size) {
    this->size = size;
    this->array = new int[size];
    for (int i = 0; i < size; i++) {
        this->array[i] = 0;
    }
}

StaticArray::StaticArray(const int *array, const int size) : StaticArray(size) {
    this->array = new int[size];
    for (int i = 0; i < size; i++) {
        this->array[i] = array[i];
    }
}

int StaticArray::getSize() const {
    return this->size;
}

int StaticArray::get(int index) const {
    if (index < 0 || index >= this->size) {
        throw std::invalid_argument("index is out of range");
    }
    return this->array[index];
}

int StaticArray::indexOf(int value) const {
    for (int i = 0; i < this->size; i++) {
        if (this->array[i] == value) return i;
    }
    return -1;
}

int StaticArray::contains(int value) const {
    return this->indexOf(value) != -1;
}

int StaticArray::binarySearch(int value) const {
    int leftIndex = 0;
    int rightIndex = this->size - 1;

    while (leftIndex <= rightIndex) {
        
    }

}

void StaticArray::insert(const int index, const int value) const {
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Invalid Index");
    }
    for (int i = this->size - 1; i > index; i--) {
        this->array[i] = this->array[i - 1];
    }
    this->array[index] = value;
}

void StaticArray::insertAtTail(const int value) const {
    this->insert(this->size - 1, value);
}

void StaticArray::insertAtHead(const int value) const {
    this->insert(0, value);
}

void StaticArray::remove(const int index) const {
    if (index < 0 || index >= this->size)
        throw std::invalid_argument("index is out of range");

    for (int i = index; i < this->size - 1; i++) {
        this->array[index] = this->array[index + 1];
    }
    this->array[size - 1] = NULL;
}

int StaticArray::pop() const {
    const auto value = this->get(size-1);
    this->remove(size-1) ;
    return value ;
}



void StaticArray::set(const int index, const int value) const {
    if (index < 0 || index >= size)
        throw std::invalid_argument("index is out of range");
    this->array[index] = value;
}

void StaticArray::display() const {
    std::cout << "[";
    for (int i = 0; i < this->size; i++) {
        std::cout << this->array[i];
        auto isLastItem = this->size - 1 == i;
        if (!isLastItem) std::cout << ",";
    }
    std::cout << "]" << std::endl;
}
