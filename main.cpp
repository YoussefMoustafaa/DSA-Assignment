#include <iostream>
#include <bits/stdc++.h>
#include "./StudentClass/Student.cpp"
#include "./Sorting/Sorting.cpp"
#include "Queue/Queue.cpp"
#include "ArrayBasedQueue/ArrayBasedQueue.cpp"
#include <sys/time.h>

using namespace std;

void IO(string fileName = "")
{
    if (fileName == "")
    {
        std::freopen("C:/Users/george/Ds_assignmnet/input.txt", "r", stdin);
    }
    else
    {

        string path = "C:/Users/george/Ds_assignmnet/" + fileName;

        std::freopen(path.c_str(), "r", stdin);
    }

    std::freopen("C:/Users/george/Ds_assignmnet/output.txt", "w", stdout);
}

void outputValues(string AlgorothimName, string CompareBase, int NumberOfComparisons, double RunningTime, Student SortedStudentElements[], int SizeOFGivenArray)
{
    cout << "Sorting method = " << AlgorothimName << "\n\n";

    cout << "Number of comparisons = " << NumberOfComparisons << "\n\n";
    cout << "Running Time = " << RunningTime << setprecision(5) << "\n\n";
    printArray(SortedStudentElements, SizeOFGivenArray);
    cout << "compared based on " << CompareBase << "\n\n";
}

int main()
{

    // ArrayBasedQueue<int> q(15);
    // q.enqueue(10);
    // q.enqueue(80);
    // q.enqueue(500);
    // q.print();
    // int dqd = q.dequeue();
    // cout << dqd << endl;
    // q.print();

    IO();
    // int noOfStudents;

    // cin >> noOfStudents;
    // Student students[noOfStudents];

    // for (int i = 0; i < noOfStudents; i++)
    // {
    //     string name;
    //     cin >> name;
    //     string id;
    //     cin >> id;
    //     double gpa;
    //     cin >> gpa;
    //     Student student(name, id, gpa);
    //     students[i] = student;
    // }

    clock_t start = clock();
    // int comparions = insertionSortForStudents(students, noOfStudents);

    clock_t end = clock();
    double elapsed_secs = (double)(end - start) / (double)1000;
    cout << elapsed_secs;

    // outputValues("shell Sort", "Gpa", comparions, elapsed_secs, students, 4);

    // cout << "**********************************************************************************************";
    // cout << "\n\n";

    // clock_t start2 = clock();
    // int comparions2 = shellSortForStudent(students, 4, true);
    // clock_t end2 = clock();
    // double elapsed_secs2 = double(end2 - start2) / 1000.0;
    // outputValues("shell Sort", "Name", comparions2, elapsed_secs2, students, 4);

    // time_t start, end;

    // time(&start);
    // ios_base::sync_with_stdio(false);

    // int num = 0;
    // for (int i = 0; i < 1000000; i++)
    // {
    //     num += i;
    // }
    // time(&end);
    // double elapsed_secs = double(end - start);
    // cout << "Time taken: " << elapsed_secs << setprecision(5) << endl;

    return 0;
}
// Queue<int> *q = new Queue<int>();
// q->enqueue(1);
// q->enqueue(2);
// q->enqueue(3);
// q->enqueue(4);
// q->enqueue(5);
// q->enqueue(6);

// q->print();

// int num = q->dequeue();
// cout << "Dequeued: " << num << endl;
// q->print();

// int num2 = q->first();
// cout << "First: " << num2 << endl;
// q->print();
// cout << q->queueSize() << endl;
// q->clear();
// q->print();
// cout << q->queueSize() << endl;

// Student student1("John", "56789", 3.7);
// Student student2("Arthur", "12459", 2.9);
// Student s3("George", "8747", 0.5);
// Student s4("Zyad", "55555", 4);

// vector<Student> v{student1, student2, s3, s4};
// cout << "Before Sorting" << endl;
// printVector(v);
// cout << "after sortng by name" << endl;
// sort(v.begin(), v.end(), studentNameComparer);
// printVector(v);
// cout << "after sortng by Gpa" << endl;

// sort(v.begin(), v.end(), studentGPAComparer);
// printVector(v);
