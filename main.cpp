#include <iostream>

#include "src/data-structures/DynamicArray.h"
#include "src/data-structures/StaticArray.h"
using namespace  datastructures;
int main() {
    const auto array = new DynamicArray(16);
    array->insertAtTail(1) ;
    array->insertAtTail(2) ;
    array->insertAtTail(3) ;
    array->insertAtTail(4) ;
    array->display();
    std::cout << array->binarySearch(-1);
;

    return 0;
}
