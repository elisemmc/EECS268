#ifndef NODE_H
#define NODE_H

class Node
{
    typedef int item;

    private:
        Node *next;
        item  value;

    public:
        Node(int _value, Node *node);
        ~Node();

        void setValue(int _value);
        void setNext(Node *node);

        int getValue();
        Node* getNext();
};

#endif
