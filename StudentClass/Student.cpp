#include <iostream>
#include "../StudentClass/Student.h"
#include "Student.h"

using namespace std;

Student::Student(string studName, string studID, double StudGpa)
{
    this->name = studName;
    this->id = studID;
    this->gpa = StudGpa;
}
Student ::Student(Student &student)
{
    this->name = student.name;
    this->id = student.id;
    this->gpa = student.gpa;
}

Student::Student()
{
}

ostream &operator<<(ostream &out, const Student &st)
{
    out << "Name: " << st.getName() << endl;
    out << "ID: " << st.getID() << endl;
    out << "GPA: " << st.getGPA() << endl;
    return out;
}

void Student::setName(string studName)
{
    this->name = studName;
}

void Student::setID(string studID)
{
    this->id = studID;
}
void Student::setGPA(double studGpa)
{
    this->gpa = studGpa;
}

string Student::getName() const
{
    return this->name;
}

string Student::getID() const
{
    return this->id;
}

double Student::getGPA() const
{
    return this->gpa;
}

bool Student::operator<(const Student &st)
{
    return this->name < st.name;
}

bool studentNameComparer(Student &S1, Student &S2)
{
    return S1.getName() < S2.getName();
}

bool studentGPAComparer(Student &S1, Student &S2)
{
    return S1.getGPA() < S2.getGPA();
}