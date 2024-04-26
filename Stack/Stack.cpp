#include <iostream>
using namespace std;

template <class T>
struct NodeO
{
    T data;
    NodeO<T> *next;
    NodeO<T> *prev;
};

template <class T>
class Stack
{
    NodeO<T> *top;
    int size;

public:
    Stack();
    void Push(T element);
    T Pop();
    T Top();
    bool isEmpty();
    int Size();
    void clear();
    void print();
};


template <class T>
Stack<T>::Stack()
{
//    this->front = NULL;
    this->top = NULL;
    this->size = 0;
}

template <class T>
void Stack<T>::Push(T data)
{
    NodeO<T> *newNodeO = new NodeO<T>();
    newNodeO->data = data;
    newNodeO->next = NULL;
    newNodeO->prev = NULL;
    if (top == NULL) {
        top = newNodeO;
    } else {
        top->next = newNodeO;
        newNodeO->prev = top;
        top = newNodeO;
    }
    size++;
}

template <class T>
T Stack<T>::Top()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return top->data;
}

template <class T>
T Stack<T>::Pop()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    T ans = top->data;
    NodeO<T> *temp = top;
    top = top->prev;
    if (top != NULL) {
        top->next = NULL;
    }
    delete temp;
    size--;
    return ans;
}

template <class T>
int Stack<T>::Size()
{
    return size;
}

template <class T>
bool Stack<T>::isEmpty()
{
    return size == 0;
}

template <class t>
void Stack<t>::print()
{
    NodeO<t> *temp = top;
    cout << '[';
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << ']';
    cout << endl;
}

template <class T>
void Stack<T>::clear()
{
    NodeO<T> *temp;
    while (top != NULL)
    {
        temp = top;
        top = top->prev;
        delete temp;
    }
    top = NULL;
    size = 0;
}
//int main(){
//    Stack <int> w;
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
//}

