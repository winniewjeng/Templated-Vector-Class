
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

    //constructors

    Vector() {
        size = 0;
        capacity = 1;
        list = new T[capacity];
//        T* walker = list;
//        while (walker != list + size) {
//            *walker = 0;
//            walker++;
//        }
    }

    Vector(Vector<T> &v) {
        //copy everything over
    }

    Vector(int sizeN, T& item) {
        size = sizeN;
        list = new T[size];
        T* walker = list;
        while (walker != list + size) {
            *walker = item;
            walker++;
        }
    }

    //copy constructor

    Vector(const Vector& orig) {
    }

    //destructor

    virtual ~Vector() {
        delete[] list;
    }

    //allocates new dynamic memory

    T* allocate(T* list, int capacity) {
        list = new T[capacity];
        return list;
    }

    void copy_list(T *dest, T* src, int many_to_copy) {
        for (int i = 0; i < many_to_copy; i++) {
            *(dest + i) = *(src + i);
        }
        //EXAAMINE THIS CODE......
        src = dest;
    }

    void print_list() {
        
        T* walker = list;
        
        while (walker != list + size) {
            cout << *walker << endl;
            walker++;
        }
        cout << endl;
    }

    //    T* add_entry(T* list, const T& new_entry, int& size, int& capacity) {
    //        return list;
    //    }

    void push_back(T item) {
        //scan through the list
        if (size < capacity) {
            T* walker = list;
            while (walker != list + size) {
                walker++;
            }
            //assign item to the end of the list
            *walker = item;
            //enlarge the size of list by 1
            size += 1;
            
        } else if (size == capacity) {
            //resizing the list by two-fold of original capacity
            capacity *= 2;
            //reallocate more dynamic memory
            T* destination = allocate(list, capacity);
            //copy the elements to the new memory space
            copy_list(destination, list, size);
            //traverse through the new list; put item at the end of list
            T*walker = list;
            while (walker != list + size) {
                walker++;
            }
            //assign item to the end of the list
            *walker = item;
            //enlarge the size of list by 1
            size += 1;
        }
    }

};


#endif /* VECTOR_H */

