#include "list.h"

template <typename T>
List<T>::List(){
    capacity = 10;
    data = new T[capacity];
    currentSize = 0;
}

template <typename T>
List<T>::List(int Capacity){
    capacity = Capacity;
    data = new T[capacity];
    currentSize = 0;
}

template <typename T>
List<T>::~List(){
    delete[] data;
}

template <typename T>
void List<T>::push(const T& value){
    if (currentSize == capacity) {
        int newCapacity = capacity * 2;
        T* newData = new T[newCapacity];

        for (int i = 0; i < currentSize; i++) {
            newData[i] = data[i];
        }

        delete[] data;
        data = newData;
        capacity = newCapacity;
    }

    data[currentSize++] = value;
}

template <typename T>
void List<T>::pop(){
    if (currentSize > 0) {
        currentSize--;
    } else {
        throw "Already empty list!";
    }
}

template <typename T>
size_t List<T>::size() const{
    return currentSize;
}

template <typename T>
T& List<T>::back() const{
    if (currentSize > 0) {
        return data[currentSize - 1];
    } else {
        throw "Already empty list!";
    }
}

template <typename T>
void List<T>::popAtIndex(int index){
    if (index >= 0 && index < currentSize) {
        for (int i = index; i < currentSize - 1; i++) {
            data[i] = data[i + 1];
        }
        currentSize--;
    } else {
        throw "Out of bound in list at pop\n";
    }
}

template <typename T>
T& List<T>::operator[](int index){
    if (index >= 0 && index < currentSize) {
        return data[index];
    } else {
        throw "Out of bound in list at []\n";
    }
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& other) {
    if (this != &other) { // Check for self-assignment
        delete[] data; // Delete the current data

        capacity = other.capacity;
        currentSize = other.currentSize;
        data = new T[capacity];

        for (int i = 0; i < currentSize; i++) {
            data[i] = other.data[i]; // Copy elements from 'other' list
        }
    }
    return *this;
}
