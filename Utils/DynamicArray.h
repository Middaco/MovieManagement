//
// Created by Asus on 23.06.2023.
//

#ifndef A45_CLION_DYNAMICARRAY_H
#define A45_CLION_DYNAMICARRAY_H


template <typename T> class DynamicArray {
private:
    int size{}, capacity{};
    T* list_of_elements;

public:
    DynamicArray();
    DynamicArray(const DynamicArray<T>& array_to_be_copied);
    void add(T element_to_be_added);
    bool remove(T element_to_be_removed);
    int get_length();
    bool search_element(T element_to_be_searched);
    DynamicArray<T>& operator=(const DynamicArray<T>& array_to_be_assigned);
    T& at(int position);
    T& operator[](int position);

    ~DynamicArray();
};


#endif //A45_CLION_DYNAMICARRAY_H
