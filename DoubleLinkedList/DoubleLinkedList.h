#include <bits/stdc++.h>
using namespace std;
#ifndef DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
#define DOUBLELINKEDLIST_DOUBLELINKEDLIST_H
template <typename T>
class Node {
    public:
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node(T d);
};

template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
public:
    DoubleLinkedList(); // Constructor
    DoubleLinkedList(T array[],int size);
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
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
};

#endif