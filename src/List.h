//
// Created by asus on 13.09.2021.
//

#include "Node.h"
#include <string>
#ifndef LMP_LIST_H
#define LMP_LIST_H

template<class T>
class List {
private:
    Node<T>* first_node = nullptr;
    Node<T>* last_node = nullptr;
    int n = 0;
    //throw std::invalid_argument, std::out_of_range
    Node<T>* find_node(int index);
    //doesn't frees memory
    void lose_control();
public:
    ~List();
    [[nodiscard]] int size() const;
    void push_back(T value);
    //throw std::invalid_argument, std::out_of_range
    void add(int index, T value);
    /*
    throw std::invalid_argument, std::out_of_range
    list will be empty
    */
    void add(int index, List<T>& list);
    //throw std::out_of_range
    void remove_last();
    //throw std::invalid_argument, std::out_of_range
    void remove(int index);
    [[nodiscard]] bool empty() const;
    //throw std::invalid_argument, std::out_of_range
    void swap(int first, int right);
    std::string to_string(std::string (*to_string)(T));
    //throw std::invalid_argument, std::out_of_range
    T operator[](int index);
    //throw std::invalid_argument, std::out_of_range
    void sublist(int start, int end, List<T>& subList);
    //return index or -1
    int find_value(bool (*check)(T t), int start = 0);
    void remove(int start, int end);
    //используется сортировка слиянием
    void sort(bool (*comparator)(T left, T right));
    void clear();
};
#endif //LMP_LIST_H