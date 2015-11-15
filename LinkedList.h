//
// Created by Yue Wang on 11/7/15.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <iostream>
#include "Node.h"


template <typename T>
class LinkedList{
private:
    Node<T> * head;
    Node<T> * tail;
    int count;

    Node<T> * GetNode(int index);//helper function

public:

    LinkedList();   // Default constructor
    LinkedList(const LinkedList<T>& src);  // Copy constructor
    ~LinkedList();  // Destructor

    void Add(T value); // Add to the Linked List from the end
    void Insert(T value, int index); // insert at a specific index

    T Get(int index); // get the value of corresponding index
    T Remove(int index); // remove the value of corresponding index

    int Size();
    int IndexOf(T value);

    bool Empty();
    void Print();

};

#endif //LINKEDLIST_H
