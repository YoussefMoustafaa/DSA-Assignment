#include<iostream>
#include "circular_linked_list.h"

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


template<typename T>
Node<T>::Node() {
    this->data = 0;
    this->next = nullptr;
}

template <typename T>
Node<T>::Node(T element)
{
    this->data = element;
    this->next = nullptr;
}

template<typename T>
int circular_linked_list<T>::linkedListSize()
{
    int len = 0;
    Node<T> *p = Head;
    if (p != nullptr) {
        do
        {
            len++;
            p = p->next;
        } while (p != Head);
    }
    return len;
}

template<typename T>
bool circular_linked_list<T>::isEmpty()
{
    return (Head == nullptr);
}

template<typename T>
void circular_linked_list<T>::clear()
{
    delete Head;
    Head = nullptr;
}

template<typename T>
void circular_linked_list<T>::print()
{
    if (isEmpty()) {
        cout << "List is empty!\n";
    } else {
        Node<T> *p = this->Head;
        do
        {
            cout << p->data << ' ';
            p = p->next;
        } while (p != Head);
        cout << "\n";
    }
}

template<typename T>
void circular_linked_list<T>::insertAtHead(T element)
{
    Node<T> *t, *p;
    t = new Node<T>(element);
    if (isEmpty()) {
        Head = t;
        Head->next = Head;
    } else {
        p = Head;
        while (p->next != Head) p = p->next;
        p->next = t;
        t->next = Head;
        Head = t;
    }
}

template<typename T>
void circular_linked_list<T>::insertAtTail(T element)
{
    Node<T> *t, *p;
    t = new Node<T>(element);
    if (isEmpty()) {
        Head = t;
        Head->next = Head;
    } else {
        p = Head;
        while (p->next != Head) p = p->next;
        p->next = t;
        t->next = Head;
    }
}

template<typename T>
void circular_linked_list<T>::insertAt(T element, int index)
{
    int size = linkedListSize();
    if (index < 0 || index > size) {
        cout << "Invalid Index!\n";
        return;
    }
    Node<T> *t, *p;
    t = new Node<T>(element);
    if (isEmpty()) {
        Head = t;
        Head->next = Head;
    } else {
        if (index == 0) {
            insertAtHead(element);
        } else if (index == size) {
            insertAtTail(element);
        } else {
            p = Head;
            for (int i = 0; i < index-1; i++)
                p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}

template<typename T>
void circular_linked_list<T>::removeAtHead()
{
    if (isEmpty()) {
        cout << "List is already empty!\n";
    } else {
        Node<T> *p = Head;
        while (p->next != Head) p = p->next;
        p->next = Head->next;
        delete Head;
        Head = p->next;
    }
}

template<typename T>
void circular_linked_list<T>::removeAtTail()
{
    if (isEmpty()) {
        cout << "List is already empty!\n";
    } else {
        Node<T> *p = Head;
        int size = linkedListSize();
        for (int i = 0; i < size-2; i++)
            p = p->next;
        Node<T> *t = p->next;
        p->next = Head;
        delete t;
    }
}

template<typename T>
void circular_linked_list<T>::removeAt(int index)
{
    int size = linkedListSize();
    if (index < 0 || index > size) {
        cout << "Invalid index!\n";
        return;
    }
    if (isEmpty()) {
        cout << "List is already empty!\n";
    } else {
        if (index == 0) {
            removeAtHead();
        } else if (index == size) {
            removeAtTail();
        } else {
            Node<T> *p = Head;
            for (int i = 0; i < index-2; i++)
                p = p->next;
            Node<T> *t = p->next;
            p->next = t->next;
            delete t;
        }
    }
}

template<typename T>
T circular_linked_list<T>::retrieveAt(int index)
{
    int size = linkedListSize();
    if (index < 0 || index > size) {
        cout << "Invalid Index!\n";
        return 0;
    } else {
        Node<T> *p = Head;
        for (int i = 0; i < index; i++)
            p = p->next;
        return p->data;
    }
}



using namespace std;

int main() {

    circular_linked_list<int> list;
    list.insertAtHead(1);
    list.insertAtHead(2);
    
    list.insertAtTail(3);
    list.insertAtTail(4);

    list.print();

    list.insertAt(7, 0);
    list.print();
    list.insertAt(6, 5);
    list.print();
    list.insertAt(9, 2);
    list.print();

    list.removeAtHead();
    list.print();
    list.removeAtTail();
    list.print();
    list.removeAt(3);
    list.print();

    cout << list.retrieveAt(2) << endl;

    cout << "clear" << endl;
    list.clear();
    list.print();

    return 0;
}