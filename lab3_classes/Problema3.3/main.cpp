#include <iostream>
#include <vector>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    vector<Student> students;
    int numStudents;

    cout << "Enter the number of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; ++i)
    {
        string name;
        double grade;

        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter grade of student " << i + 1 << ": ";
        cin >> grade;

        students.emplace_back(name, grade); // se adauga studentul in vector
    }

    findTopStudents(students);

    return 0;
}