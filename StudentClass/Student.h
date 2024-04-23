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
    Student& operator=(const Student& other) {
        if (this != &other) {
            name = other.name;
            id = other.id;
            gpa = other.gpa;
        }
        return *this;
    }
    Student(string studName, string studID, double studGpa);
    Student();
    Student(Student &student);
    Student(const Student& other);
    friend ostream &operator<<(ostream &out, const Student &st);
    friend std::istream& operator>>(std::istream& in, Student& st);
    bool operator<(const Student &st);
    void setName(string studName);
    void setID(string studID);
    void setGPA(double studGpa);
    string getName() const;
    string getID() const;
    double getGPA() const;
};

#endif // STUDENT_H
