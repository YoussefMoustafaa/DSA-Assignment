#include <iostream>
#include "Student.cpp"
#include <bits/stdc++.h>
#include "SingleLinkedLIst.cpp"

bool studentGPAComparer(Student &S1, Student &S2)
{
    return S1.getGPA() < S2.getGPA();
} bool studentGPAComparerOrEqual(Student &S1, Student &S2)
{
    return S1.getGPA() <=S2.getGPA();
}
template<typename T>
int partiton(T Array[], int low , int high , bool compareByName = true){
    T pivot=Array[low];
    int i=low,j=high;
    Student temp;
    if(compareByName){
        do
        {
            do{i++;} while (studentNameComparer(Array[i],pivot));

            do{j--;} while (studentNameComparerOrEqual(pivot,Array[j]));

        } while (i<j);
        swap(Array[i],Array[j]);
        return j;
    }else{
        do
        {
            do{i++;} while (studentGPAComparer(Array[i],pivot));

            do{j--;} while (studentGPAComparerOrEqual(pivot,Array[j]));

        } while (i<j);
        swap(Array[i],Array[j]);
        return j;
    }

}
template<typename T>
void QuickSort(T Array[],int low,int high, bool compareByName = true){
    int j;
    if(compareByName){
        if(low<high){
            j= partiton(Array,low,high,compareByName);
            QuickSort(Array,low,j,compareByName);
            QuickSort(Array,j++,high,compareByName);
        }
    }else{
        if(low<high){
            j= partiton(Array,low,high,compareByName);
            QuickSort(Array,low,j,compareByName);
            QuickSort(Array,j++,high,compareByName);
        }
    }
}
template<typename T>
void QuickSortStudent(T Array[],int low,int high, bool compareByName = true){

    if(compareByName){
        QuickSort(Array,low,high,true);

    }else{
        QuickSort(Array,low,high, false);
    }

}
int main() {
    freopen("C:/cs/QuickSort/input.txt","r",stdin);
    freopen("C:/cs/QuickSort/output.txt","W",stdin);
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
    list.swap(3,4);
    list.display();

}
