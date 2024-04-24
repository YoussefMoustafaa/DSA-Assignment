#include <bits/stdc++.h>
using namespace std;

template <class T>
class ArrayBasedQueue
{
private:
    T *arr;
    int front;
    int rear;
    int size;
    int length;

public:
    ArrayBasedQueue(int size)
    {
        this->size = size;
        arr = new T[size];
        front = -1;
        rear = -1;
    }
    void enqueue(T data)
    {
        if (rear == size - 1)
        {
            cout << "Queue is full" << endl;
            return;
        }
        else
        {
            if (front == -1)
            {
                front = 0;
            }
            rear++;
            arr[rear] = data;
            length++;
        }
    }
    T dequeue()
    {
        if (front == -1 || front > rear)
        {
            cout << "Queue is empty" << endl;
        }
        T data = arr[front];
        front++;
        length--;
        if (front > rear)
        {
            front = rear = -1;
        }
        return data;
    }

    int getLength()
    {
        return this->length;
    }

    bool isEmpty()
    {
        return front == -1;
    }

    T peek()
    {
        if (this->isEmpty())
        {
            cout << "This Queue empty " << endl;
            return;
        }
        return arr[front];
    }
    void clear()
    {
        front = rear = 1;
        length = 0;
    }
    void print()
    {
        cout << '[';
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ,";
        }

        cout << ']' << endl;
    }
};