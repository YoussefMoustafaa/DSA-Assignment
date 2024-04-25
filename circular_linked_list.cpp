#include<iostream>

using namespace std;


// class Node
// {
// private:
//     int data;
//     Node* next;
// public:
//     Node(int data, Node* next);
//     Node();

//     void Display(Node* head);
//     void recursive_display(Node* head);
// };

// Node::Node() {
//     this->data = 0;
//     this->next = nullptr;
// }

// Node::Node(int data, Node* next)
// {
//     this->data = data;
//     this->next = next;
// }

// void Node::Display(Node* head) {
//     Node *p = head;
//     do
//     {
//         cout << p->data << ' ';
//         p = p->next;
//     } while (p != head);
    
// }

// void Node::recursive_display(Node* head) {
//     static int flag = 0;
//     static Node* p = head;
//     if (p != head || flag == 0) {
//         flag = 1;
//         cout << p->data << ' ';
//         recursive_display(p->next);
//     }    
// }


template<typename T> class Node
{
private:
    T data;
    Node<T> *next;
    static Node<T> *Head;
public:
    Node();
    Node(T x);
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



template<typename T>
int Node<T>::linkedListSize()
{
    int len = 0;
    Node<T> *p = Head;
    do
    {
        len++;
        p = p->next;
    } while (p != Head);
    return len;
}

template<typename T>
bool Node<T>::isEmpty()
{
    int length = linkedListSize();
    return (length ? true : false);
}

template<typename T>
void Node<T>::clear()
{
    delete Head;
    Head = nullptr;
}

template<typename T>
void Node<T>::print()
{
    Node<T> *p = Head;
    do
    {
        cout << p->data << ' ';
        p = p->next;
    } while (p != Head);
}


template<typename T>
Node<T>::Node() {
    this->data = 0;
    this->next = new Node<T>();
}

template <typename T>
Node<T>::Node(T element)
{
    this->data = element;
}

template<typename T>
void Node<T>::insertAtHead(T element)
{
    Node<T> *t, *p;
    t = new Node<T>(element);
    p = Head;
    while (p->next != Head) p = p->next;
    p->next = t;
    t->next = Head;
    Head = t;
}


using namespace std;

int main() {

    Node<int> *t = new Node<int>(5);

    t->print();

    cout << "Hello World";

    return 0;
}