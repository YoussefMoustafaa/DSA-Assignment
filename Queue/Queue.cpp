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
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
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
    Node<T> *temp = front;
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
    Node<t> *temp = front;
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
    Node<T> *temp;
    while (front != NULL)
    {
        temp = front;
        front = front->next;
        delete temp;
    }
    rear = front;
    size = 0;
}
