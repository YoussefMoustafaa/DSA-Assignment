#include <iostream>
#include <string>

#ifndef STUDENT_H
#define STUDENT_H

using namespace std;

class Student
{
private:
    string name;
    string id;
    double gpa;
public:
    Student(string studName, string studID, int studGpa);
    friend ostream& operator << (ostream& out, const Student& st);
    bool operator < (const Student& st);
};

#endif // STUDENT_H