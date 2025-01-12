//
// Created by ismail-swe on 12/29/24.
//

#ifndef STATICARRAY_H
#define STATICARRAY_H

namespace datastructures {
    class StaticArray {
    public:
        StaticArray();

        StaticArray(const int *array, int size);

        explicit StaticArray(int size);

        ~StaticArray() = default;

        void display() const;
        int getSize() const ;

        int get(int index) const ;
        int indexOf(int value) const ;
        int contains(int value) const ;
        int binarySearch(int value) const ;


        void set(int index, int value) const;
        void insert(int index, int value) const;
        void insertAtTail(int value) const ;
        void insertAtHead(int value) const ;

        void remove(int index) const;

        int pop() const ;


    private:
        int *array;
        int size;
    };
}


#endif //STATICARRAY_H
