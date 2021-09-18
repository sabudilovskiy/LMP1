#include <string>
#ifndef LMP_NODE_H
#define LMP_NODE_H
template <class T>
class Node {
private:
    Node* next = nullptr;
    T value;
public:
    Node(T value);
    T getValue();
    void setValue(T value);
    Node* getNext();
    void setNext(Node*);
};


#endif //LMP_NODE_H
