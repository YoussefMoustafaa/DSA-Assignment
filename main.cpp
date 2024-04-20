#include <iostream>
#include <bits/stdc++.h>
#include "./StudentClass/Student.cpp"
#include "./Sorting/Sorting.cpp"
#include <vector>
using namespace std;

int main()
{

    Student student1("John", "56789", 3.7);
    Student student2("Arthur", "12459", 2.9);
    Student s3("George", "8747", 0.5);
    Student s4("Zyad", "55555", 4);

    vector<Student> v{student1, student2, s3, s4};
    cout << "Before Sorting" << endl;
    printVector(v);
    cout << "after sortng by name" << endl;
    sort(v.begin(), v.end(), studentGPAComparer);
    printVector(v);

    return 0;
}
