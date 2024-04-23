#include <iostream>
#include <bits/stdc++.h>
#include "./StudentClass/Student.cpp"
#include "./Sorting/Sorting.cpp"
#include "Queue/Queue.cpp"
#include <vector>
using namespace std;
template<typename T>
vector<T> in(){
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
  return students;
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


int main()
{

}
