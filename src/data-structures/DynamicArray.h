//
// Created by ismail-bagga on 2/3/25.
//

#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H


namespace datastructures {
    class DynamicArray {
    public:
        DynamicArray();

        DynamicArray(const int *array, int size);

        explicit DynamicArray(int size);

        ~DynamicArray() = default;

        void display() const;

        [[nodiscard]] int getSize() const;

        [[nodiscard]] int get(int index) const;

        [[nodiscard]] int indexOf(int value) const;

        [[nodiscard]] int contains(int value) const;

        [[nodiscard]] int binarySearch(int value) const;


        void set(int index, int value) const;

        void insert(int insertAt, int value) ;
        void leftShiftingInsert(int insertAt , int value ) ;

        void insertAtTail(int value) ;

        void insertAtHead(int value) ;

        void remove(int index) const;

        int pop() const;

    private:
        int *array;
        int size;
        int capacity ;

        void expand_array() ;
        void shrinking_array() ;
    };
}


#endif //DYNAMICARRAY_H
