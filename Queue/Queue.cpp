#include <iostream>
#include "Queue.h"
using namespace std;

template <class T>
Queue<T>::Queue()
{
    this->front = NULL;
    this->rear = NULL;
    this->size = 0;
}

template <class T>
void Queue<T>::enqueue(T data)
{
    NodeG<T> *newNodeG = new NodeG<T>();
    newNodeG->data = data;
    newNodeG->next = NULL;

    if (front == NULL)
    {
        front = newNodeG;
        rear = newNodeG;
    }
    else
    {
        rear->next = newNodeG;
        rear = newNodeG;
    }
    size++;
}

template <class T>
T Queue<T>::first()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    return front->data;
}

template <class T>
T Queue<T>::dequeue()
{
    if (front == NULL)
    {
        cout << "Queue is empty" << endl;
        return 0;
    }
    T ans = front->data;
    NodeG<T> *temp = front;
    front = front->next;
    delete temp;
    size--;
    return ans;
}

template <class T>
int Queue<T>::queueSize()
{
    return size;
}

template <class T>
bool Queue<T>::isEmpty()
{
    return size == 0;
}

template <class t>
void Queue<t>::print()
{
    NodeG<t> *temp = front;
    cout << '[';
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << ']';
    cout << endl;
}

template <class T>
void Queue<T>::clear()
{
    NodeG<T> *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = front;
    size = 0;
}
