#include "DoubleLinkedList.h"
#include <iostream>

template<typename T>
Node<T>::Node(T d){
     {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
}

template<typename T>
DoubleLinkedList<T>::DoubleLinkedList() {
    head = nullptr;
}
template<typename T>
DoubleLinkedList<T>::DoubleLinkedList(T array[], int arraySize) {
    head = nullptr;
    for (int i = 0; i < arraySize; i++) {
        insertAtTail(array[i]);
    }
}
template<typename T>
void DoubleLinkedList<T>::insertAtHead(T element) {
    Node<T>* newNode = new Node<T>(element);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}


template<typename T>
void DoubleLinkedList<T>::insertAtTail(T element){
    Node<T>* newNode = new Node<T>(element);
    if (head == nullptr) {
    head = newNode;
    }
    else {
        Node<T>* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->next = current;
        newNode->next = nullptr;
    }
}

template<typename T>
void DoubleLinkedList<T>::insertAt(T element, int index) {
    if (index < 0)
        return; 

    Node<T>* newNode = new Node<T>(element);

    if (index == 0) {
        insertAtHead(element);
    } else {
        if (head == nullptr) {
            cout << "Position not found." << endl;
            delete newNode; 
            return;
        }
        Node<T>* current = head;
        int currentIndex = 0;
        while (current->next != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }
        if (currentIndex != index - 1) {
            cout << "Position not found." << endl;
            delete newNode; 
            return;
        }

        if (current->next == nullptr && currentIndex == index - 1) {
            insertAtTail(element);
        } else {
            newNode->next = current->next;
            if (current->next != nullptr)
                current->next->prev = newNode;
            current->next = newNode;
            newNode->prev = current;
        }
    }
}

template <typename T>
void DoubleLinkedList<T>::removeAtHead(){
if(head == nullptr) {
    return;
}
 Node<T>* temp = head;
 if(head->next == nullptr) {
     head = nullptr;
    }
 else {
    head = head->next;
    head ->prev = nullptr;
 }   
 delete temp;
 if (head == nullptr) {
     cout << "The list is now empty." << endl;
 }
}
// traversing the linked list with two pointers
template<typename T>
void DoubleLinkedList<T>::removeAtTail() {
    if (head == nullptr) {
        return;
    } else if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node<T>* previous = nullptr;
        Node<T>* current = head;
        
        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        
        delete current;
        previous->next = nullptr;
    }
}
 
// traversing the linked list with 1 pointer
/*
template<typename T>
void DoubleLinkedList<T>::removeAtTail() {
    if (head == nullptr) {
        // If the list is empty, do nothing
        return;
    } else if (head->next == nullptr) {
        // If the list has only one node
        delete head;
        head = nullptr;
    } else {
        // If the list has more than one node
        Node<T>* current = head;
        while (current->next->next != nullptr) {
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
}
*/
template<typename T>
void DoubleLinkedList<T>::removeAt(int index) {
    if (head == nullptr) {
        throw out_of_range("List is empty");
    }

    if (index < 0) {
        throw out_of_range("Index is out of scope");
    }

    Node<T>* current = head;
    Node<T>* previous = nullptr;
    int currentIndex = 0;

    while (current != nullptr && currentIndex < index) {
        previous = current;
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        throw out_of_range("Index is out of scope");
    }

    if (previous == nullptr) {
        head = current->next;
    } else {
        previous->next = current->next;
    }

    if (current->next != nullptr) {
        current->next->prev = previous;
    }

    delete current;
}


template<typename T>
T DoubleLinkedList<T>::retrieveAt(int index) {
    if (index < 0) {
        throw out_of_range("Index is out of bounds. Index cannot be negative");
    }

    if (head == nullptr) {
        throw out_of_range("The list is empty.");
    }

    Node<T>* current = head;
    int currentIndex = 0;
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        throw out_of_range("Index is out of bounds.");
    }
    return current->data;
}

template<typename T>
void DoubleLinkedList<T>::replaceAt(T newElement, int index) {
    if (index < 0) {
        cout << "Position not found. Index is out of bounds" << endl;
        return;
    }

    if (head == nullptr) {
        cout << "Position not found. The list is empty." << endl;
        return;
    }

    Node<T>* current = head;
    int currentIndex = 0;
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        cout << "Position not found. Index is out of bounds" << endl;
        return;
    }

    current->data = newElement;
}

template<typename T>
bool DoubleLinkedList<T>::isExist(T element) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->data == element) {
            return true; 
        }
        current = current->next;
    }
    return false;
}

template<typename T>
bool DoubleLinkedList<T>::isItemAtEqual(T element, int index) {
    if (index < 0) {
        cout << "Invalid index. Index must be non-negative." << endl;
        return false;
    }

    Node<T>* current = head;
    int currentIndex = 0;
    while (current != nullptr && currentIndex < index) {
        current = current->next;
        currentIndex++;
    }

    if (current == nullptr) {
        cout << "Invalid index. Index is out of bounds." << endl;
        return false;
    }
    return current->data == element;
}

template<typename T>
void DoubleLinkedList<T>::swap(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx < 0 || secondItemIdx < 0) {
        cout << "Invalid index. Indecies cannot be negative" << endl;
        return;
    }
    if (firstItemIdx == secondItemIdx) {
        return;
    }
    Node<T>* firstNode = nullptr;
    Node<T>* secondNode = nullptr;

    Node<T>* current = head;
    int currentIndex = 0;
    while (current != nullptr && (firstNode == nullptr || secondNode == nullptr)) {
        if (currentIndex == firstItemIdx) {
            firstNode = current;
        }
        if (currentIndex == secondItemIdx) {
            secondNode = current;
        }
        current = current->next;
        currentIndex++;
    }
    if (firstNode == nullptr || secondNode == nullptr) {
        cout << "Invalid index. One or both indices are out of bounds." << endl;
        return;
    }
    T temp = firstNode->data;
    firstNode->data = secondNode->data;
    secondNode->data = temp;
}
template<typename T>
bool DoubleLinkedList<T>::isEmpty() {
    if (head == nullptr) {
        return true; 
    } else {
        return false; 
    }
}
template<typename T>
int DoubleLinkedList<T>::linkedListSize() {
    int size = 0;
    Node<T>* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}
template<typename T>
void DoubleLinkedList<T>::clear() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr; 
}
template<typename T>
void DoubleLinkedList<T>::print() {
    Node<T>* current = head;
    cout << "Linked List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}



