#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

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
        int id;

        cout << "Enter name of student " << i + 1 << ": ";
        cin >> name;
        cout << "Enter ID of student " << i + 1 << ": ";
        cin >> id;

        students.emplace_back(name, id); // se adauga studentul in vector
    }

    string nameToSearch;
    cout << "Enter the name of the student to search for: ";
    cin >> nameToSearch;

    searchStudentByName(students, nameToSearch);

    return 0;
}