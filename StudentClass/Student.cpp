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

ostream &operator<<(ostream &out, const Student &st)
{
    out << "Name: " << st.name << endl;
    out << "ID: " << st.id << endl;
    out << "GPA: " << st.gpa << endl;
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