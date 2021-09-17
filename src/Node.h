#include <string>
#ifndef LMP_NODE_H
#define LMP_NODE_H
class Node {
private:
    Node* next = nullptr;
    int value;
public:
    Node(int value);
    int getValue();
    void setValue(int value);
    Node* getNext();
    void setNext(Node*);
    std::string to_string();
};


#endif //LMP_NODE_H
