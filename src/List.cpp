#include "List.h"
#include <stdexcept>

List::~List() {
    clear();
}

void List::push_back(int value) {
    if (n == 0){
        first_node = new Node(value);
        last_node = first_node;
    }
    else{
        last_node->setNext(new Node(value));
        last_node = last_node->getNext();
    }
    n++;
}

void List::add(int index, int value) {
    if (index < 0)throw std::out_of_range("");
    if (index < n){
        int i = 0;
        Node* previous, *cur_node = first_node, *next;
        while (i != index && cur_node->getNext()!= nullptr){
            cur_node = cur_node->getNext();
            i++;
        }
        if (i != index) throw std::invalid_argument("");
        previous = cur_node;
        next = previous->getNext();
        Node*new_node = new Node(value);
        previous->setNext(new_node);
        new_node->setNext(next);
    }
    else if (index == n && index != 0){
        push_back(value);
    }
    else if (index == n && index == 0){
        first_node = new Node(value);
        last_node = first_node;
    }
    else throw std::out_of_range("");
    n++;
}

bool List::empty() const {return n == 0;}

std::string List::to_string() {
    std::string answer;
    if (first_node != nullptr) {
        answer += std::to_string(first_node->getValue());
        Node* cur_node = first_node->getNext();
        while (cur_node != nullptr){
            answer += " " + std::to_string(cur_node->getValue());
            cur_node = cur_node->getNext();
        }
        return answer;
    }
    else return "";
}

void List::remove_last() {
    if (last_node != nullptr){
        Node* cur_node = find_node(n - 2);
        delete last_node;
        last_node = cur_node;
        last_node->setNext(nullptr);
    }
    else throw std::out_of_range("");
}

void List::remove(int index){
    if (index == 0 && n == 1){
        delete first_node;
        first_node = nullptr;
        last_node = nullptr;
    }
    else if (index < n){
        Node* previous_node = find_node(index - 1);
        Node* next_node = previous_node->getNext()->getNext();
        delete previous_node->getNext();
        previous_node->setNext(next_node);
        if (next_node == nullptr) last_node = previous_node;
    }
    else throw std::out_of_range("");
    n--;
}
void List::remove(int start, int end) {
    int i = end - start + 1;
    int j = 0;
    //слишком гениальный код
    List subList;
    sublist(start, end, subList);
    subList.List::~List();
}

int List::size() const {
    return n;
}

int List::operator[](int index) {
   return find_node(index)->getValue();
}

void List::sublist(int start, int end, List& subList) {
    {
        if (start < 0 || start > end || end >= n) throw std::invalid_argument("");
        else if (start > 0 && end < n - 1){
            subList.clear();
            Node* last_prev_sublist = find_node(start - 1);
            Node* last_sublist_node = find_node(end);
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
            Node* end_node = find_node(end);
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
            Node*first_prev_sublist = find_node(start - 1);
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

Node* List::find_node(int index) {
    if (index >= 0 && index < n){
        Node* cur_node = first_node;
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
void List::swap(int first, int second) {
    Node *firstNode{find_node(first)},*secondNode{find_node(second)};
    int first_value = firstNode->getValue();
    int second_value = secondNode->getValue();
    firstNode->setValue(second_value);
    secondNode->setValue(first_value);
}

int List::find_value(bool (*check)(int), int start) {
    Node* cur_node = first_node;
    int index = start;
    while (cur_node!= nullptr ){
        if (check(cur_node->getValue())) return index;
        index++;
        cur_node = cur_node->getNext();
    }
    return -1;
}

void List::add(int index, List& list) {
    if (index!= 0 && index < n){
        Node* previous_node = find_node(index);
        Node* next_node = previous_node->getNext();
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

void List::lose_control() {
    n = 0;
    first_node = nullptr;
    last_node = nullptr;
}

void List::sort(bool (*comparator)(int, int)) {

}

void List::clear() {
    int index = 0;
    Node* cur_node = first_node;
    while (index < n){
        Node* temp = cur_node->getNext();
        delete cur_node;
        cur_node = temp;
        index++;
    }
}


