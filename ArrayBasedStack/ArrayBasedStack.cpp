#include<iostream>
using namespace std;

template <class T>
class ArrayBasedStack
{
private:
    T *arr;

    int rear;
    int size;
    int length = 0 ;

public:
    ArrayBasedStack(int size)
    {
        this->size = size;
        arr = new T[size];
        rear = -1;
    }
    void Push(T data)
    {
        if (rear == size - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        else
        {

            rear++;
            arr[rear] = data;
            length++;
        }
    }
    T Pop()
    {
        if (rear == -1 )
        {
            cout << "Stack is empty" << endl;
        }
        else {
            T data = arr[rear];
            rear--;
            length--;
            return data;
        }

    }

    int Size()
    {
        return this->length;
    }

    bool isEmpty()
    {
        return rear == -1;
    }

    T Top()
    {
        if (this->isEmpty())
        {
            cout << "This Stack is empty " << endl;
            return arr[rear];
        }
        return arr[rear];
    }
    void clear()
    {
        rear = -1;
        length = 0;
    }
    void print()
    {
        cout << '[';
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ,";
        }

        cout << ']' << endl;
    }
};
int main(){
    ArrayBasedStack<int> w(5);
    w.Push(5);
    w.Push(4);
    w.Push(3);
    w.Push(2);
    w.Push(1);
    cout<<w.Pop()<<endl;
    cout<<w.Pop()<<endl;
    cout<<w.Pop()<<endl;

    cout<<w.Size()<<endl;
    w.print();
    cout<<w.Top()<<endl;
    w.clear();
    cout<<w.Size()<<endl;
    w.print();
    cout<<w.isEmpty()<<endl;
    cout<<w.Top()<<endl;


}