#pragma once
#include "string.h"
#include "category.h"
//#include "budget.h"

template <typename T>
class List {
private:
    T* data;
    int capacity;
    int currentSize;

public:
    List();
    List(int Capacity);
    ~List();
    
    void push(const T& value);
    void pop();
    T& back() const;
    int size() const;
    void popAtIndex(int index);

    T& operator[](int index);
    List<T>& operator=(const List<T>& other);
};

// // Explicit instantiation for supported types
template class List<int>;
template class List<double>;
template class List<char>;
template class List<String>;
template class List<Category>;
//template class List<Budget>;
// // Add more instantiations as needed for other types
