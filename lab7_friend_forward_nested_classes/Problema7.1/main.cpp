#include <iostream>
#include <vector>

using namespace std;

class Group
{
public:
    class Student
    {
    private:
        string name;
        int age;

    public:
        Student(string n, int a) : name(n), age(a) {}
        void display() const
        {
            cout << "Name: " << name << ", Age: " << age << endl;
        }
    };

private:
    string groupName;
    vector<Student> students;

public:
    Group(string gName) : groupName(gName) {}

    void addStudent(const string &name, int age)
    {
        students.emplace_back(name, age);
    }

    void displayGroup() const
    {
        cout << "Group: " << groupName << endl;
        for (const auto &student : students)
            student.display();
    }
};

int main()
{
    Group group1("Computer Science");
    group1.addStudent("Gigi", 45);
    group1.addStudent("Costi", 36);

    cout << "Group Details:" << endl;
    group1.displayGroup();

    return 0;
}