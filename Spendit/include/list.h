#pragma once
#include "string.h"

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
    size_t size() const;
    void popAtIndex(int index);

    T& operator[](int index);
    List<T>& operator=(const List<T>& other);
};

// // Explicit instantiation for supported types
template class List<int>;
template class List<double>;
template class List<char>;
template class List<String>;
// // Add more instantiations as needed for other types
