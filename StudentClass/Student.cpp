#include <iostream>
#include "../StudentClass/Student.h"

using namespace std;

Student::Student(string studName, string studID, int StudGpa) {
    this->name = studName;
    this->id = studID;
    this->gpa = StudGpa;
}

ostream& operator << (ostream& out, const Student& st) {
    out << "Name: " << st.name << endl;
    out << "ID: " << st.id << endl;
    out << "GPA: " << st.gpa << endl;
    return out;
}

bool Student::operator< (const Student& st) {
    return this->name < st.name;
}