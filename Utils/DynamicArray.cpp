//
// Created by Asus on 23.06.2023.
//

#include "DynamicArray.h"
#include <string>

template <class T> DynamicArray<T>::DynamicArray()
{
    this->size = 0;
    this->capacity = 2;
    this->list_of_elements = new T[this->capacity * sizeof(T)];
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& array_to_be_copied)
{
    this->capacity = array_to_be_copied.capacity;
    this->size = array_to_be_copied.size;
    this->list_of_elements = new T[sizeof(T) * capacity];

    for(int current_position = 0; current_position < this->size; current_position++){
        this->list_of_elements[current_position] = array_to_be_copied.list_of_elements[current_position];
    }
    //memcpy(list_of_elements, array_to_be_copied.list_of_elements, size * sizeof(T));
}


template <class T> void DynamicArray<T>::add(T element_to_be_added)
{
    if (this->size == this->capacity) {
        this->capacity *= 2;
        T* aux = new T[this->capacity * sizeof(T)];
        for (int i = 0; i < this->size; i++) {
            aux[i] = this->list_of_elements[i];
        }
        delete[] this->list_of_elements;
        this->list_of_elements = aux;
    }
    this->list_of_elements[this->size] = element_to_be_added;
    this->size++;
}

template <class T> bool DynamicArray<T>::remove(T element_to_be_removed)
{
    int i;
    bool found = false;
    for (i = 0; i < this->size; i++) {
        if (this->list_of_elements[i] == element_to_be_removed) {
            this->list_of_elements[i] = this->list_of_elements[this->size - 1];
            this->size--;
            found = true;
            break;
        }
    }
    return found;
}

template <class T> int DynamicArray<T>::get_length()
{
    return this->size;
}

template <class T> bool DynamicArray<T>::search_element(T element_to_be_searched) {
    for (int i = 0; i < this->size;i++) {
        if (this->list_of_elements[i] == element_to_be_searched) {
            return true;
        }
    }
    return false;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator= (const DynamicArray<T>& array_to_be_assigned)
{
    if(&array_to_be_assigned == this){
        return *this;
    }
    this->capacity = array_to_be_assigned.capacity;
    this->size = array_to_be_assigned.size;
    list_of_elements = new T[capacity];
    memcpy(list_of_elements, array_to_be_assigned.list_of_elements, size * sizeof(T));
    return *this;
}

template<typename T>
T& DynamicArray<T>::at(int position)
{
    return this->list_of_elements[position];
}

template<typename T>
T& DynamicArray<T>::operator[](int position)
{
    return this->list_of_elements[position];
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete[] list_of_elements;
}

