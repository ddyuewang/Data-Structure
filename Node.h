//
// Created by Yue Wang on 11/7/15.
//

#ifndef NODE_H
#define NODE_H

template <typename T>
class LinkedList;

template <typename T>
class Node{
    // friend class to access the node class
    // friend class LinkedList<T>;

private:
    T data;
    Node<T> * next;
    friend class LinkedList<T>;

public:
    Node(): data(T()), next(nullptr){};

    // default constructor
    Node(T d, Node * n = nullptr): data(d), next(n){};
    Node(Node<T> * copyNode): data(copyNode->Value()), next(copyNode->Next()) {}; // copy constructor

    Node<T> * operator= (Node<T> * copyNode) //assignment constructor
    {
        this->data = copyNode-> data;
        this->next = copyNode->Next();
        // return the existing object
        return this;
    };

    // get function - return the pointer to the next node
    Node<T> * Next()
    {
        return next;
    };

    // set function - update the next to the new node
    void Set(Node<T>& _next)
    {
        next = &_next;
    };

    // return the value of the node
    T & Value()
    {
        return data;
    };


    //Node<T>& operator=(const Node<T>&);
    //Node<T>(const T& d):data(d), next() {}


};

#endif
