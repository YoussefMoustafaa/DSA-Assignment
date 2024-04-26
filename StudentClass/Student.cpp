#include <iostream>

#include "../StudentClass/Student.h"
// #include "../Sorting/Sorting.cpp"

using namespace std;

Student::Student() {
    this->name = "";
    this->id = "";
    this->gpa = 0.0;
}

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


Student :: Student(const Student& other) : name(other.name), id(other.id), gpa(other.gpa) {}

ostream &operator<<(ostream &out, const Student &st)
{

    out << "Name: " << st.name << endl;
    out << "ID: " << st.id << endl;
    out << "GPA: " << st.gpa << endl;
    return out;
}
istream& operator>>(istream& in, Student& st){
    in >> st.name >> st.id >> st.gpa;
    return in;
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

