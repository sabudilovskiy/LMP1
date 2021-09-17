//
// Created by asus on 13.09.2021.
//

#include "Node.h"
#include <string>
#ifndef LMP_LIST_H
#define LMP_LIST_H

class List {
private:
    Node* first_node = nullptr;
    Node* last_node = nullptr;
    int n = 0;
    //throw std::invalid_argument, std::out_of_range
    Node* find_node(int index);
    //doesn't frees memory
    void lose_control();
public:
    ~List();
    [[nodiscard]] int size() const;
    void push_back(int value);
    //throw std::invalid_argument, std::out_of_range
    void add(int index, int value);
    /*
    throw std::invalid_argument, std::out_of_range
    list will be empty
    */
    void add(int index, List& list);
    //throw std::out_of_range
    void remove_last();
    //throw std::invalid_argument, std::out_of_range
    void remove(int index);
    [[nodiscard]] bool empty() const;
    //throw std::invalid_argument, std::out_of_range
    void swap(int first, int right);
    std::string to_string();
    //throw std::invalid_argument, std::out_of_range
    int operator[](int index);
    //throw std::invalid_argument, std::out_of_range
    void sublist(int start, int end, List& subList);
    //return index or -1
    int find_value(bool (*check)(int), int start = 0);
    void remove(int start, int end);
    void sort(bool (*comparator)(int left, int right));
    void clear();
};
#endif //LMP_LIST_H