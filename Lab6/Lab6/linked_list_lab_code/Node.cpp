#include "Node.h"

using namespace std;

Node::Node(int _value, Node *node) : value(_value), next(node)
{
}

Node::~Node()
{
}

void Node::setValue(int _value)
{
    value = _value;
}

void Node::setNext(Node *node)
{
    next = node;
}

int Node::getValue()
{
    return value;
}

Node* Node::getNext()
{
    return next;
}

