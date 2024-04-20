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
    Student(string studName, string studID, double studGpa);
    friend ostream &operator<<(ostream &out, const Student &st);
    bool operator<(const Student &st);
    void setName(string studName);
    void setID(string studID);

    void setGPA(double studGpa);

    string getName() const;
    string getID() const;
    double getGPA() const;
};

#endif // STUDENT_H