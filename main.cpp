#include <iostream>

#include "src/data-structures/StaticArray.h"
using namespace  datastructures;
int main() {
    int a[2] = {10  ,20} ;
    const auto array = new StaticArray(4);
    array->set(0,10) ;
    array->set(1,100) ;
    array->set(2,1000) ;
    array->display();
    array->insert(4,20);
    array->display();

    return 0;
}
