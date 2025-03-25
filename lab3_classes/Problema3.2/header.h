#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Student
{
private:
    string name;
    int id;

public:
    // constructor
    Student(const string &name, int id) : name(name), id(id) {}

    // accessors
    string getName() const { return name; }
    int getId() const { return id; }
};

// cautare student
void searchStudentByName(const vector<Student> &students, const string &searchName)
{
    // cautare cu functie lambda
    auto it = find_if(students.begin(), students.end(),
                      [&searchName](const Student &student)
                      {
                          return student.getName() == searchName;
                      });

    if (it != students.end())
    {
        cout << "Student found: " << it->getName() << " (ID: " << it->getId() << ")\n";
    }
    else
    {
        cout << "Student not found.\n";
    }
}

#endif