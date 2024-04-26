#include<iostream>
using namespace std;

template <class T>
class ArrayBasedStack
{
private:
    T *arr;

    int top;
    int size;
    int length = 0 ;

public:
    ArrayBasedStack(int size)
    {
        this->size = size;
        arr = new T[size];
        top = -1;
    }
    void Push(T data)
    {
        if (top == size - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        else
        {

            top++;
            arr[top] = data;
            length++;
        }
    }
    T Pop()
    {
        if (top == -1 )
        {
            cout << "Stack is empty" << endl;
        }
        else {
            T data = arr[top];
            top--;
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
        return top == -1;
    }

    T Top()
    {
        if (this->isEmpty())
        {
            cout << "This Stack is empty " << endl;
            return arr[top];
        }
        return arr[top];
    }
    void clear()
    {
        top = -1;
        length = 0;
    }
    void print()
    {
        cout << '[';
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ,";
        }

        cout << ']' << endl;
    }
};
//int main(){
//    ArrayBasedStack<int> w(5);
//    w.Push(5);
//    w.Push(4);
//    w.Push(3);
//    w.Push(2);
//    w.Push(1);
//    cout<<w.Pop()<<endl;
//    cout<<w.Pop()<<endl;
//    cout<<w.Pop()<<endl;
//
//    cout<<w.Size()<<endl;
//    w.print();
//    cout<<w.Top()<<endl;
//    w.clear();
//    cout<<w.Size()<<endl;
//    w.print();
//    cout<<w.isEmpty()<<endl;
//    cout<<w.Top()<<endl;
//
//
//}