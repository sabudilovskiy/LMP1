#include "Node.h"
#include <string>

Node::Node(int value) {this->value = value;}
Node *Node::getNext() {return next;}
int Node::getValue() {return value;}
void Node::setNext(Node* node) {next = node;}
void Node::setValue(int value) {this->value = value;}
std::string Node::to_string() {return std::to_string(value);}
