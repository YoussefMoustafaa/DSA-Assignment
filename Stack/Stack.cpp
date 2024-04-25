#include <iostream>
using namespace std;

template <class T>
struct Node
{
    T data;
    Node<T> *next;
    Node<T> *prev;
};

template <class T>
class Stack
{
    Node<T> *rear;
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
    this->rear = NULL;
    this->size = 0;
}

template <class T>
void Stack<T>::Push(T data)
{
    Node<T> *newNode = new Node<T>();
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    if (rear == NULL) {
        rear = newNode;
    } else {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
    }
    size++;
}

template <class T>
T Stack<T>::Top()
{
    if (rear == NULL)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    return rear->data;
}

template <class T>
T Stack<T>::Pop()
{
    if (rear == NULL)
    {
        cout << "Stack is empty" << endl;
        return 0;
    }
    T ans = rear->data;
    Node<T> *temp = rear;
    rear = rear->prev;
    if (rear != NULL) {
        rear->next = NULL;
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
    Node<t> *temp = rear;
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
    Node<T> *temp;
    while (rear != NULL)
    {
        temp = rear;
        rear = rear->prev;
        delete temp;
    }
    rear = NULL;
    size = 0;
}
int main(){
    Stack <int> w;
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

