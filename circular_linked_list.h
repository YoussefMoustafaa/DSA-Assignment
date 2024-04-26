#include <iostream>


#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

using namespace std;



template<typename T>
class Node
{
public:
    T data;
    Node<T> *next;
    Node();
    Node(T x);
};


// T data;
// Node<T> *next;
// static Node<T> *Head;

template<typename T>
class circular_linked_list
{
private:
    Node<T> *Head;
public:
    // Node(T data, Node *next());
    int linkedListSize();
    bool isEmpty();
    void clear();
    void print();
    void insertAtHead(T element);
    void insertAtTail(T element);
    void insertAt(T element, int index);
    void removeAtHead();
    void removeAtTail();
    void removeAt(int index);
    T retrieveAt(int index);
    void replaceAt(T newElement, int index);
    bool isExist(T element);
    bool isItemAtEqual(T element, int index);
    void swap(int firstItemIdx, int secondItemIdx);
};


#endif // CIRCULAR_LINKED_LIST_H