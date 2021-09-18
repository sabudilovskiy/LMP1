#include "List.h"
#include <stdexcept>

template<class T>
List<T>::~List() {
    clear();
}
template<class T>
void List<T>::push_back(T value) {
    if (n == 0){
        first_node = new Node<T>(value);
        last_node = first_node;
    }
    else{
        last_node->setNext(new Node<T>(value));
        last_node = last_node->getNext();
    }
    n++;
}

template<class T>
void List<T>::add(int index, T value) {
    if (index < 0)throw std::out_of_range("");
    if (index < n){
        int i = 0;
        Node<T>* previous, *cur_node = first_node, *next;
        while (i != index && cur_node->getNext()!= nullptr){
            cur_node = cur_node->getNext();
            i++;
        }
        if (i != index) throw std::invalid_argument("");
        previous = cur_node;
        next = previous->getNext();
        Node<T>*new_node = new Node<T>(value);
        previous->setNext(new_node);
        new_node->setNext(next);
    }
    else if (index == n && index != 0){
        push_back(value);
    }
    else if (index == n && index == 0){
        first_node = new Node<T>(value);
        last_node = first_node;
    }
    else throw std::out_of_range("");
    n++;
}

template<class T>
bool List<T>::empty() const {return n == 0;}

template<class T>
std::string List<T>::to_string(std::string (*to_string)(T t)) {
    std::string answer;
    if (first_node != nullptr) {
        answer += std::to_string(first_node->getValue());
        Node<T>* cur_node = first_node->getNext();
        while (cur_node != nullptr){
            answer += " " + std::to_string(cur_node->getValue());
            cur_node = cur_node->getNext();
        }
        return answer;
    }
    else return "";
}

template<class T>
void List<T>::remove_last() {
    if (last_node != nullptr){
        Node<T>* cur_node = find_node(n - 2);
        delete last_node;
        last_node = cur_node;
        last_node->setNext(nullptr);
    }
    else throw std::out_of_range("");
}

template<class T>
void List<T>::remove(int index){
    if (index == 0 && n == 1){
        delete first_node;
        first_node = nullptr;
        last_node = nullptr;
    }
    else if (index < n){
        Node<T>* previous_node = find_node(index - 1);
        Node<T>* next_node = previous_node->getNext()->getNext();
        delete previous_node->getNext();
        previous_node->setNext(next_node);
        if (next_node == nullptr) last_node = previous_node;
    }
    else throw std::out_of_range("");
    n--;
}

template<class T>
void List<T>::remove(int start, int end) {
    int i = end - start + 1;
    int j = 0;
    //слишком гениальный код
    List subList;
    sublist(start, end, subList);
    subList.List::~List();
}

template<class T>
int List<T>::size() const {
    return n;
}

template<class T>
T List<T>::operator[](int index) {
   return find_node(index)->getValue();
}

template<class T>
void List<T>::sublist(int start, int end, List<T>& subList) {
    {
        if (start < 0 || start > end || end >= n) throw std::invalid_argument("");
        else if (start > 0 && end < n - 1){
            subList.clear();
            Node<T>* last_prev_sublist = find_node(start - 1);
            Node<T>* last_sublist_node = find_node(end);
            subList.n = end - start + 1;
            subList.first_node = last_prev_sublist->getNext();
            subList.last_node = last_sublist_node;
            last_prev_sublist->setNext(last_sublist_node->getNext());
            subList.last_node->setNext(nullptr);

            n -= subList.n;
        }
        else if (start == 0 && end == n - 1){
            subList.clear();
            subList.add(0, *this);
        }
        else if (start == 0){
            Node<T>* end_node = find_node(end);
            subList.clear();
            subList.first_node = first_node;
            subList.last_node = end_node;
            first_node->setNext(end_node->getNext());
            subList.last_node->setNext(nullptr);
            subList.n = end - start + 1;
            n -= subList.n;
        }
        // end == n - 1
        else{
            Node<T>*first_prev_sublist = find_node(start - 1);
            subList.clear();
            subList.n = end - start + 1;
            subList.first_node = first_prev_sublist->getNext();
            subList.last_node = last_node;
            last_node = first_prev_sublist;
            last_node->setNext(nullptr);
            n -= subList.n;
        }
    }
}

template<class T>
Node<T>* List<T>::find_node(int index) {
    if (index >= 0 && index < n){
        Node<T>* cur_node = first_node;
        int cur_index = 0;
        while (index!=cur_index){
            cur_node = cur_node->getNext();
            cur_index++;
        }
        return cur_node;
    }
    else if (index < 0) throw std::invalid_argument("");
    else throw std::out_of_range("");
}

template<class T>
void List<T>::swap(int first, int second) {
    Node<T> *firstNode{find_node(first)},*secondNode{find_node(second)};
    int first_value = firstNode->getValue();
    int second_value = secondNode->getValue();
    firstNode->setValue(second_value);
    secondNode->setValue(first_value);
}

template<class T>
int List<T>::find_value(bool (*check)(T t), int start) {
    Node<T>* cur_node = first_node;
    int index = start;
    while (cur_node!= nullptr ){
        if (check(cur_node->getValue())) return index;
        index++;
        cur_node = cur_node->getNext();
    }
    return -1;
}

template<class T>
void List<T>::add(int index, List<T>& list) {
    if (index!= 0 && index < n){
        Node<T>* previous_node = find_node(index);
        Node<T>* next_node = previous_node->getNext();
        previous_node->setNext(list.first_node);
        list.last_node->setNext(next_node);
        n+= list.n;
        list.lose_control();
    }
    else if (index==0 && n == 0) std::swap(*this, list);
    else if (index == 0 && n > 0){
        list.last_node->setNext(first_node);
        first_node = list.first_node;
        n+=list.n;
        list.lose_control();
    }
    else if (index == n){
        last_node->setNext(list.first_node);
        last_node = list.last_node;
        n += list.n;
        list.lose_control();
    }
    else throw std::out_of_range("");
}

template<class T>
void List<T>::lose_control() {
    n = 0;
    first_node = nullptr;
    last_node = nullptr;
}

template<class T>
void List<T>::sort(bool (*comparator)(T, T)) {

}

template<class T>
void List<T>::clear() {
    int index = 0;
    Node<T>* cur_node = first_node;
    while (index < n){
        Node<T>* temp = cur_node->getNext();
        delete cur_node;
        cur_node = temp;
        index++;
    }
}


