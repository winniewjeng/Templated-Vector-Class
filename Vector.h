
#ifndef VECTOR_H
#define VECTOR_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

template <class T> class Vector {
private:
    int size;
    int capacity;
    T* list;

public:

    //constructor

    Vector() {
        size = 0;
        capacity = 100;
        list = new T[capacity];
    }

    //copy constructor

    Vector(const Vector& other) {
        this->size = other.size;
        this->capacity = other.capacity;
        list = new T[other.capacity]; //allocate space
        copy_list(list, other.list, size);
    }

    //destructor

    ~Vector() {
        delete[] list;
    }

    //assignment operator

    Vector<T>& operator=(const Vector<T>& rhs) {
        //self-check
        if (this == &rhs) {
            return *this;
        }
        //clean up the dynamic array of the lhs
        delete[] this->list;

        //instantiate all the attributes of lhs again
        this->capacity = rhs.capacity;
        this->size = rhs.size;
        this->list = allocate(list, capacity); //allocate space for the lhs

        //copy the junk over.
        copy_list(list, rhs.list, size);
        return *this;
    }

    //allocate new dynamic memory

    T* allocate(T* list, int capacity) {
        list = new T[capacity];
        return list;
    }

    void copy_list(T* dest, T* src, int size) {
        for (int i = 0; i < size; i++) {
            *(dest + i) = *(src + i);
        }
        list = dest;
    }

    T* add_entry(T* list, const T& item, int& size, int& capacity) {
        //resize if the list capacity is full
        if (size >= capacity - 1) {
            capacity *= 2;
        }

        T* destination = allocate(list, capacity);
        copy_list(destination, list, size);
        //add new_entry at the end of the list, where the size is.
        T* placer = destination + size;
        *placer = item;
        //increment the size by 1
        size++;
        //      
        delete[] list;
        return destination;
    }

    void push_back(const T& item) {

        list = add_entry(list, item, size, capacity);

    }

    void pop_back() {

        size--;
        //        if (size == capacity / 4) {
        //            T* desitnation = allocate(list, capacity);
        //            copy_list(desitnation, list, size);
        //        }
    }

    void print_capacity() {
        cout << "current capacity: " << capacity << endl;
    }

    friend ostream& operator<<(ostream& outs, const Vector& print_me) {
        //code goes here.
        for (int i = 0; i < print_me.size; i++) {
            outs << print_me.list[i] << "  ";
        }
        return outs;
    }

    T& operator[](int index) {
        return list[index];
    }

    T at(int index) {
        return list[index];
    }

};


#endif /* VECTOR_H */

