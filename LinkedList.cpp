// Created by Yue Wang on 11/7/15.
#include <iostream>
#include "LinkedList.h"

using namespace std;

// constructor
template <typename T>
LinkedList<T>::LinkedList()   // Default constructor
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

// copy constructor
/* copy constructor here needs a deep copy !!*/
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& src)
{
    // initialize the head pointer
    if (src.count > 0) {
        head = new Node<T>(src.head->Value());
        tail = head;
        count = 1;

        Node<T> *current = src.head->Next();
        cout << src.count << endl;
        // traverse the Node
        while (current != nullptr)
        {
            this->Add(current->Value());
            current = current->Next();
        }
        tail  = GetNode(count);

    }
    else
    {
        head = nullptr;
        tail = nullptr;
        count = 0;
    }
//    delete current;
//    tail = this->GetNode(count);
}


// Destructor
template <typename T>
LinkedList<T>::~LinkedList() // Destructor
{
    while(count!= 0)
    {
        Remove(1);
    }
}

// Add the specified element at the end of the list
template <typename T>
void LinkedList<T>::Add(T value)
{
    Node<T> * next_node = new Node<T> (value);

    if (count == 0)
    {
        head = next_node;
        tail = head;
    }
    else
    {
        tail->Set(*next_node);
        tail = next_node;
    }

    count ++;
}

// Add the specified element at the specified index - starting from 1
template <typename T>
void LinkedList<T>::Insert(T value, int index)
{
    if (count == 0)
    {
        head = new Node<T> (value);
        tail = head;
    }
    else if (index == 1)
    {
        Node<T> * next_node = new Node<T>(value,head);
        head = next_node;
    }
    else if (index >= count)
    {
        Node<T> * next_node = new Node<T>(value);
        tail->Set(*next_node);
        tail = next_node;
    }
    else
    {
        Node<T> *tmp = GetNode(index - 1);
        Node<T> *next_node = new Node<T>(value,tmp->Next());
        tmp->Set(*next_node);
        tail = next_node;

    }
    count ++;
}

// Get the element at the specified index - helper function : starting from index 1
template <typename T>
Node<T> * LinkedList<T>::GetNode(int index)
{
    Node<T> * current = head;
    index --; // first index in 0
    while(index > 0)
    {
        index --;
        current = current->Next();
    }

    return current;

}

template <typename T>
// Get the value of Node at the specified index
T LinkedList<T>::Get(int index)
{
    return GetNode(index)->Value();
}

// Retrieve the index of the specified element -1 if it does not exist in the list
template <typename T>
int LinkedList<T>::IndexOf(T value)
{
    int index = 0;
    Node<T>* current = head;
    while (current->Value() != value && current != nullptr)
    {
        current = current->Next();
        index ++;
    }

    if (current != nullptr)
    {
        return ++index;
    }

    return -1;
}

// Remove the element at the specified index
template <typename T>
T LinkedList<T>::Remove(int index)
{
    T to_return;
    if (count == 1) {
        Node<T> * old_node = head;
        to_return = head->Value();
        head = nullptr;
        tail = nullptr;
        delete old_node;
    }
    else if (index == 1)
    {
        Node<T> * next_node = head->Next();
        Node<T> * old_node = head;
        head = next_node;
        to_return = old_node->Value();
        delete old_node;
    }
    else if (index >= count)
    {
        Node<T> *new_tail = GetNode(count - 1);
        Node<T> *old_tail = tail;
        new_tail->Set(*(old_tail->Next()));
        tail = new_tail;
        to_return = old_tail->Value();
        delete old_tail;
    }
    else
    {
        Node<T> *previous = GetNode(index - 1);
        Node<T> *to_remove = previous->Next();
        previous->Set(*(to_remove->Next()));
        to_return = to_remove->Value();
        delete to_remove;
    }
    count --;
    return to_return;
}

template <typename T>
bool LinkedList<T>::Empty()
{
    return count == 0 ;
}

template <typename T>
int LinkedList<T>::Size()
{
    return count;
}

template <typename T>
void LinkedList<T>::Print()
{

    cout << "(";

    Node<T> * current = head;

    if (current != nullptr) {

        while (current->Next() != nullptr) {
            cout << current->Value() << ", ";
            current = current->Next();
        }
        cout << current->Value();
    }

    cout << ")" << endl;
}
