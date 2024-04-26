#include "DoubleLinkedList.h"
#include <iostream>

template<typename T>
NodeD<T>::NodeD(T d){
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
    NodeD<T>* newNodeD = new NodeD<T>(element);
    if (head == nullptr) {
        head = newNodeD;
    } else {
        newNodeD->next = head;
        head->prev = newNodeD;
        head = newNodeD;
    }
}


template<typename T>
void DoubleLinkedList<T>::insertAtTail(T element){
    NodeD<T>* newNodeD = new NodeD<T>(element);
    if (head == nullptr) {
    head = newNodeD;
    }
    else {
        NodeD<T>* current = head;
        while (current->next != nullptr)
        {
            current = current->next;
        }
        current->next = newNodeD;
        newNodeD->next = current;
        newNodeD->next = nullptr;
    }
}

template<typename T>
void DoubleLinkedList<T>::insertAt(T element, int index) {
    if (index < 0)
        return; 

    NodeD<T>* newNodeD = new NodeD<T>(element);

    if (index == 0) {
        insertAtHead(element);
    } else {
        if (head == nullptr) {
            cout << "Position not found." << endl;
            delete newNodeD; 
            return;
        }
        NodeD<T>* current = head;
        int currentIndex = 0;
        while (current->next != nullptr && currentIndex < index - 1) {
            current = current->next;
            currentIndex++;
        }
        if (currentIndex != index - 1) {
            cout << "Position not found." << endl;
            delete newNodeD; 
            return;
        }

        if (current->next == nullptr && currentIndex == index - 1) {
            insertAtTail(element);
        } else {
            newNodeD->next = current->next;
            if (current->next != nullptr)
                current->next->prev = newNodeD;
            current->next = newNodeD;
            newNodeD->prev = current;
        }
    }
}

template <typename T>
void DoubleLinkedList<T>::removeAtHead(){
if(head == nullptr) {
    return;
}
 NodeD<T>* temp = head;
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
        NodeD<T>* previous = nullptr;
        NodeD<T>* current = head;
        
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
        // If the list has only one NodeD
        delete head;
        head = nullptr;
    } else {
        // If the list has more than one NodeD
        NodeD<T>* current = head;
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

    NodeD<T>* current = head;
    NodeD<T>* previous = nullptr;
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

    NodeD<T>* current = head;
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

    NodeD<T>* current = head;
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
    NodeD<T>* current = head;
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

    NodeD<T>* current = head;
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
    NodeD<T>* firstNodeD = nullptr;
    NodeD<T>* secondNodeD = nullptr;

    NodeD<T>* current = head;
    int currentIndex = 0;
    while (current != nullptr && (firstNodeD == nullptr || secondNodeD == nullptr)) {
        if (currentIndex == firstItemIdx) {
            firstNodeD = current;
        }
        if (currentIndex == secondItemIdx) {
            secondNodeD = current;
        }
        current = current->next;
        currentIndex++;
    }
    if (firstNodeD == nullptr || secondNodeD == nullptr) {
        cout << "Invalid index. One or both indices are out of bounds." << endl;
        return;
    }
    T temp = firstNodeD->data;
    firstNodeD->data = secondNodeD->data;
    secondNodeD->data = temp;
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
    NodeD<T>* current = head;
    while (current != nullptr) {
        size++;
        current = current->next;
    }
    return size;
}
template<typename T>
void DoubleLinkedList<T>::clear() {
    NodeD<T>* current = head;
    while (current != nullptr) {
        NodeD<T>* temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr; 
}
template<typename T>
void DoubleLinkedList<T>::print() {
    NodeD<T>* current = head;
    cout << "Linked List: ";
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}



