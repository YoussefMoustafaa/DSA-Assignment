#include <iostream>

#ifndef QUEUE_H
#define QUEUE_H
using namespace std;

template <class T>
struct NodeG
{
    T data;
    NodeG<T> *next;
};

template <class T>
class Queue
{
    NodeG<T> *front, *rear;
    int size;

public:
    Queue();
    void enqueue(T element);
    T dequeue();
    T first();
    bool isEmpty();
    int queueSize();
    void clear();
    void print();
};

// enqueue (elementType element) : void
// o dequeue () : elementType element //return the first element and remove it.
// o first () : elementType element //return the first element without removing it.
// o isEmpty () : bool
// o queueSize () : int
// o clear (): void
// o print () : void

#endif