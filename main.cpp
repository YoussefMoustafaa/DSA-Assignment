#include <iostream>
#include "Student.cpp"
#include <bits/stdc++.h>

template<typename T>
int partiton(vector<T>& Array, int low, int high){
    T pivot=Array[low];
    int i=low,j=high;
    do
    {
        do{i++;} while (Array[i]<=pivot);

        do{j--;} while (pivot<Array[j]);
        if(i<j){
            swap(Array[i],Array[j]);
        }

    } while (i<j);
    swap(Array[low],Array[j]);
    return j;


}
template<typename T>
void QuickSort(vector<T>& Array, int low, int high){
    int j;
    if(low<high){
        j= partiton(Array,low,high);
        QuickSort(Array,low,j);
        QuickSort(Array,j+1,high);
    }

}
bool compareByGPA(const Student& a, const Student& b) {
    return a.getGPA() < b.getGPA();
}
bool compareByName(const Student& a, const Student& b) {
    return a.getName() < b.getName();
}

template<typename Compare>
int partition(vector<Student>& arr, int low, int high, Compare comp) {
    Student pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (comp(arr[j], pivot)) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Quick sort for student class
template<typename Compare>
void quickSort(vector<Student>& arr, int low, int high, Compare comp) {
    if (low < high) {
        int part = partition(arr, low, high, comp);
        quickSort(arr, low, part - 1, comp);
        quickSort(arr, part + 1, high, comp);
    }
}
template<typename T>
void O(vector<T>& v){
    ofstream outputFile("C:\\cs\\QuickSort\\output.txt");
    if (!outputFile.is_open()) {
        throw ("Failed to open the output file.");
    }

    for (const auto& student : v) {
        outputFile << "Name: " << student.getName() << endl;
        outputFile << "ID: " << student.getID() << endl;
        outputFile << "GPA: " << student.getGPA() << endl << endl;
    }

    outputFile.close();

    cout << "Data has been successfully written to output.txt" << endl;
}

int main() {
    ifstream file("C:\\cs\\QuickSort\\input.txt");
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
        return 1;
    }

    int size;
    file >> size;
    file.ignore();
    vector<Student> students(size);
    for (int i = 0; i < size; ++i) {
        string name, id;
        double gpa;

        getline(file, name);
        file >> id >> gpa;
        file.ignore();
        students[i]=Student(name, id, gpa);
    }
    file.close();
    quickSort(students,0,3, compareByName);
    O( students);
    vector<int> arr ={4,2,8,1,9,10,5,3,6};
    QuickSort(arr,0,9);

}
