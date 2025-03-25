#include <iostream>
#include <vector>
#include <string>

using namespace std;

// clasa abstracta de baza
class Vehicle
{
public:
    virtual void start() = 0; // virtual function
    virtual ~Vehicle() {}     // destructor
};

// clasele rocket / car care mostenesc vehicle
class Rocket : public Vehicle
{
private:
    string name;

public:
    Rocket(string n) : name(n) {}

    void start() override
    {
        cout << "start " << name << " rocket" << endl;
    }
};

class Car : public Vehicle
{
private:
    string name;

public:
    Car(string n) : name(n) {}

    void start() override
    {
        cout << "start " << name << " car" << endl;
    }
};

int main()
{
    vector<Vehicle *> vehicles; // vector de pointeri catre vehicles

    // se adauga elemente (vehicles) in vector si se da start la fiecare
    vehicles.push_back(new Car("red"));
    vehicles.push_back(new Car("blue"));
    vehicles.push_back(new Rocket("Space"));

    for (auto element : vehicles)
    {
        element->start();
    }

    // se elibereaza memoria alocata
    for (auto element : vehicles)
    {
        delete element;
    }

    return 0;
}