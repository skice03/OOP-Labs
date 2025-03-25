#include <iostream>
#include <vector>

using namespace std;

class Person
{
public:
    int age;
    Person(int a) : age(a) {}
};

class Car
{
public:
    int yearsOld;
    Car(int y) : yearsOld(y) {}
};

template <typename T>
class AverageCalculator
{
public:
    static double computeAverage(const vector<T> &elements)
    {
        double sum = 0;
        for (const auto &e : elements)
            sum += e.age;
        return sum / elements.size();
    }
};

template <>
class AverageCalculator<Car>
{
public:
    static double computeAverage(const vector<Car> &cars)
    {
        double sum = 0;
        for (const auto &car : cars)
            sum += car.yearsOld;
        return sum / cars.size();
    }
};

int main()
{
    vector<Person> people = {Person(20), Person(30), Person(25)};
    vector<Car> cars = {Car(10), Car(15), Car(8)};

    cout << "Average age of persons: " << AverageCalculator<Person>::computeAverage(people) << endl;
    cout << "Average age of cars: " << AverageCalculator<Car>::computeAverage(cars) << endl;

    return 0;
}