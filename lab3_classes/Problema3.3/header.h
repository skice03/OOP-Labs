#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student
{
private:
    string name;
    double grade;

public:
    // contructor
    Student(const string &name, double grade) : name(name), grade(grade) {}

    // accessors
    string getName() const { return name; }
    double getGrade() const { return grade; }
};

void findTopStudents(const vector<Student> &students)
{
    if (students.empty())
    {
        cout << "No students to compare.\n";
        return;
    }

    double highestGrade = students[0].getGrade();
    for (const auto &student : students)
    {
        if (student.getGrade() > highestGrade)
        {
            highestGrade = student.getGrade();
        }
    }

    // afisare studenti cu cea mai mare nota
    bool found = false;
    for (const auto &student : students)
    {
        if (student.getGrade() == highestGrade)
        {
            if (!found)
            {
                cout << "The student(s) with the highest grade (" << highestGrade << "):\n";
                found = true;
            }
            cout << "Name: " << student.getName() << ", Grade: " << student.getGrade() << endl;
        }
    }
}

#endif