#include <iostream>
#include <bits/stdc++.h>
#include "./StudentClass/Student.cpp"
#include "./Sorting/Sorting.cpp"
#include "./DoubleLinkedList/DoubleLinkedList.cpp"
#include "Queue/Queue.cpp"
#include <vector>
#include "SingleLinkedList/SingleLinkedLIst.cpp"
#include "./circular linked List/circular_linked_list.cpp"
#include "./Stack/Stack.cpp"
#include "./ArrayBasedStack/ArrayBasedStack.cpp"
using namespace std;

void outGPA(Student studentList[],int size){
    ofstream outFileGPA("C:\\Users\\001\\Documents\\GitHub\\DSA-Assignment\\Output files\\outFileGPA.txt");
    outFileGPA << "Sorted By GPA\n";
    outFileGPA<<"\n\n";
    Student temp[size] ;
    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    int comparison;
    auto Start = chrono::steady_clock::now();
    comparison= insertionSortForStudents(temp,size,0);
    auto End = chrono::steady_clock::now();
    auto timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileGPA << "Algorithm: Insertion Sort\n";
    outFileGPA << "Number of comparisons: " << comparison << " comparisons\n";
    outFileGPA << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileGPA << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileGPA<<temp[i];
    }
    outFileGPA<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= quickSort(temp,0,size-1, compareByGPA);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileGPA << "Algorithm: Quick Sort\n";
    outFileGPA << "Number of comparisons: " << comparison << " comparisons\n";
    outFileGPA << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileGPA << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileGPA<<temp[i];
    }
    outFileGPA<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= shellSortForStudent(temp, size,false);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileGPA << "Algorithm: Shell Sort\n";
    outFileGPA << "Number of comparisons: " << comparison << " comparisons\n";
    outFileGPA << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileGPA << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileGPA<<temp[i];
    }
    outFileGPA<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= mergeSortForStudents(temp, size, false);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileGPA << "Algorithm: Merge Sort\n";
    outFileGPA << "Number of comparisons: " << comparison << " comparisons\n";
    outFileGPA << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileGPA << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileGPA<<temp[i];
    }
    outFileGPA<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= selectionSortForstudent(temp,size,false);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileGPA << "Algorithm: Selection Sort\n";
    outFileGPA << "Number of comparisons: " << comparison << " comparisons\n";
    outFileGPA << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileGPA << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileGPA<<temp[i];
    }
    outFileGPA<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= bubbleSortForStudent(temp,size,false);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileGPA << "Algorithm: Bubble Sort\n";
    outFileGPA << "Number of comparisons: " << comparison << " comparisons\n";
    outFileGPA << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileGPA << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileGPA<<temp[i];
    }
    outFileGPA<<"\n\n";
    outFileGPA.close();
}
void outName(Student studentList[],int size){
    int comparison;
    Student temp[size] ;
    ofstream outFileName("C:\\Users\\001\\Documents\\GitHub\\DSA-Assignment\\Output files\\outFileName.txt");
    outFileName << "Sorted By Name\n";
    outFileName<<"\n\n";
    auto Start = chrono::steady_clock::now();
    comparison= insertionSortForStudents(temp,size,1);
    auto End = chrono::steady_clock::now();
    auto timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileName << "Algorithm: Insertion Sort\n";
    outFileName << "Number of comparisons: " << comparison << " comparisons\n";
    outFileName << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileName << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileName<<temp[i];
    }
    outFileName<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= quickSort(temp,0,size-1, compareByName);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileName << "Algorithm: Quick Sort\n";
    outFileName << "Number of comparisons: " << comparison << " comparisons\n";
    outFileName << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileName << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileName<<temp[i];
    }
    outFileName<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= shellSortForStudent(temp, size,1);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileName << "Algorithm: Shell Sort\n";
    outFileName << "Number of comparisons: " << comparison << " comparisons\n";
    outFileName << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileName << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileName<<temp[i];
    }
    outFileName<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= mergeSortForStudents(temp,size,1);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileName << "Algorithm: Merge Sort\n";
    outFileName << "Number of comparisons: " << comparison << " comparisons\n";
    outFileName << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileName << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileName<<temp[i];
    }
    outFileName<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= selectionSortForstudent(temp,size,1);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileName << "Algorithm: Selection Sort\n";
    outFileName << "Number of comparisons: " << comparison << " comparisons\n";
    outFileName << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileName << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileName<<temp[i];
    }
    outFileName<<"\n\n";


    for(int i =0;i<size;i++){
        temp[i]=studentList[i];
    }
    Start = chrono::steady_clock::now();
    comparison= bubbleSortForStudent(temp,size,1);
    End = chrono::steady_clock::now();
    timeTaken = chrono::duration_cast<std::chrono::nanoseconds>(End - Start);
    outFileName << "Algorithm: Bubble Sort\n";
    outFileName << "Number of comparisons: " << comparison << " comparisons\n";
    outFileName << "Running Time:" << timeTaken.count() << " nanoseconds" << "\n";
    outFileName << "Sorted List:\n";
    for(int i =0;i<size;i++){
        outFileName<<temp[i];
    }
    outFileName<<"\n\n";
    outFileName.close();
}

void in(){
    ifstream file("C:\\Users\\001\\Documents\\GitHub\\DSA-Assignment\\Output files\\student.txt");
    if (!file.is_open()) {
        cout << "Failed to open the file." << endl;
    }
    int size;
    file >> size;
    file.ignore();
    Student studentList[size];
    for (int i = 0; i < size; ++i) {
        string name, id;
        double gpa;
        getline(file, name);
        file >> id >> gpa;
        file.ignore();
        studentList[i]=Student(name, id, gpa);
    }
    file.close();
    outGPA(studentList,size);
    outName(studentList,size);
}
int main()
{

  in();

}
