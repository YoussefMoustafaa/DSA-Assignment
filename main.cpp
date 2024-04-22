#include "SingleLinkedLIst.cpp"


int main() {
    SingleLinkedLIst<int> ls;
    int array[]={1,2,3,4,5};
    SingleLinkedLIst<int> list(array,5);
    list.insertAtHead(0);
    list.display();
    list.insertAtTail(6);
    list.display();
    list.insertAt(3,0);
    list.display();
    list.replaceAt(33,7);
    list.display();
    list.swap(7,0);
    list.display();

}
