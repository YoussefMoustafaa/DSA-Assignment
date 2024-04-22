//
// Created by mahmoud on 4/20/2024.
//
#include "SingleLinkedLIst.h"
template<typename T>
Node<T>::Node() {
    this->data=0;
    this->next=NULL;
}
template<typename T>
SingleLinkedLIst<T>::SingleLinkedLIst(){
    this->first=NULL;
    this->last=NULL;
    this->size=0;
};
template<typename T>
SingleLinkedLIst<T>::SingleLinkedLIst(T array[],int arraySize){//time o(n) space o(n)
    this->size=1;
    Node<T> *newNode;
    first=new Node<T>;
    first->data=array[0];
    first->next=NULL;
    last=first;
    for(int i = 1; i<arraySize; i++)
    {
        newNode =new Node<T>;
        newNode->data=array[i];
        newNode->next=NULL;
        last->next=newNode;
        last=newNode;
        size++;
    }
};

template<typename T>
void SingleLinkedLIst<T>::insertAtHead(T element){ //time o(1) space o(1)
    Node<T> *newNode = new Node<T>();
    newNode->data = element;
    newNode->next = NULL;
    if(first){
        newNode->next=first;
        first=newNode;
    }else{
        first=last=newNode;
    }size++;
};
template<typename T>
void SingleLinkedLIst<T>::insertAtTail (T element){
    Node<T> *newNode = new Node<T>();
    newNode->data = element;
    newNode->next = NULL;
    if(last){
        last->next=newNode;
        last=newNode;
    }else{
        first=last=newNode;
    }size++;
};
template<typename T>
void SingleLinkedLIst<T>:: insertAt (T element, int index){
    Node<T> *newNode = new Node<T>();
    newNode->data = element;
    newNode->next = NULL;
    Node<T> *postion=first;
    if(index<0 or size<index){
        throw out_of_range("Index is out of scope");
    }else if(index==0){
        newNode->next=first;
        first=newNode;
        size++;
    }else{
        Node<T> *postion=first;
        for(int i =0 ; i<index-1;i++){
            postion=postion->next;
        }
        newNode->next=postion->next;
        postion->next=newNode;
        size++;
        if(index==(size-1)){
            last=postion;
        }

    }
};
template<typename T>
void SingleLinkedLIst<T>:: removeAtHead(){
    if(!size){
        throw out_of_range("The list is already empty!");
    }else if(size==1){
        first=last=NULL;
        size--;
    }else{
        Node<T> *temp =first;
        first=first->next;
        delete temp;
        size--;
    }
};
template<typename T>
void SingleLinkedLIst<T>:: removeAtTail (){
    if(!size){
        throw out_of_range("The list is already empty!");

    }else if(size==1){
        first=last=NULL;
        size--;
    }else{
        Node<T> *postion=first;
        for(int i =0 ; i<size-2;i++){
            postion=postion->next;
        }
        last=postion;
        postion=postion->next;
        delete postion;
        size--;
    }
};
template<typename T>
void SingleLinkedLIst<T> ::display() {
    Node<T> *postion=first;
    cout<<"List elements: ";
    for(int i =0; i<size;i++){
        cout<<postion->data<<" ";
        postion=postion->next;
    }cout<<"\n";
}
template<typename T>
void SingleLinkedLIst<T> ::removeAt(int index){
    Node<T> *postion=first;
    if(index<0 or size<index){
        throw out_of_range("Index is out of scope");
    }else if(index==1){
        postion=first;
        first=first->next;
        delete postion;
        size--;
    }else{
        Node<T> *postion=first,*temp=NULL;
        for(int i =0 ; i<index;i++){
            temp=postion;
            postion=postion->next;
        }
        temp->next=postion->next;
        if(index==(size-1)){
            last=postion;
        }
        size--;
    }
};
template<typename T>
T SingleLinkedLIst<T> :: retrieveAt (int index){
    if(index<0 or index>=size){
        throw out_of_range("Index is out of scope");
    }
    Node<T> *postion=first;
    for(int i =0 ; i<index;i++){
        postion=postion->next;
    }
    return postion->data;
};
template<typename T>
void SingleLinkedLIst<T> :: replaceAt (T newElement, int index){
    if(index<0 or size<=index){
        throw out_of_range("Index is out of scope");
    }else if(index==0){
        first->data=newElement;
    }else{
        Node<T> *postion=first;
        for(int i =0 ; i<index;i++){
            postion=postion->next;
        }postion->data=newElement;



    }
};
template<typename T>
bool SingleLinkedLIst<T> :: isExist (T element){
    Node<T> *postion=first;
    for(int i=0;i<size;i++){
        if(postion->data==element)
            return 1;
        postion=postion->next;

    }return 0;

};
template<typename T>
bool SingleLinkedLIst<T> ::isItemAtEqual (T element, int index){
    Node<T> *postion=first;
    if(index<0 or size<index){
        throw out_of_range("Index is out of scope");
    }else{
        for(int i=0;i<index;i++){
            postion=postion->next;
        }if(postion->data==element)
            return 1;
        return 0;
        };
    }

template<typename T>
void SingleLinkedLIst<T> ::swap (int firstItemIdx, int secondItemIdx){
    if(firstItemIdx<0 or size<=firstItemIdx){
        throw out_of_range("First index is out of scope");
    }else if(secondItemIdx<0 or size<=secondItemIdx){
        throw out_of_range("Second index is out of scope");
    }else{
        Node<T> *Fposition=first,*Sposition=first;
        for(int i =0 ;i<firstItemIdx;i++){
            Fposition=Fposition->next;
        }for(int i =0 ;i<secondItemIdx;i++){
            Sposition=Sposition->next;
        }
        T temp = Fposition->data;
        Fposition->data = Sposition->data;
        Sposition->data = temp;

    }
}
        template<typename T>
bool SingleLinkedLIst<T> :: isEmpty (){
    if(size==0)
        return 1;
    return 0;
};
template<typename T>
int SingleLinkedLIst<T> :: linkedListSize (){
    return size;
};
template<typename T>
void SingleLinkedLIst<T> ::clear (){
    Node<T> *postion=first;

    while (first){
        first=first->next;
        delete postion;
        postion=first;
    }last=size=0;

};
template<typename T>
void SingleLinkedLIst<T> ::print (){
    Node<T> *postion=first;
    cout<<"List elements: ";
    for(int i =0; i<size;i++){
        cout<<postion->data<<" ";
        postion=postion->next;
    }cout<<"\n";

};


