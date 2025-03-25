#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class Vehicle
{
protected:
    string type;
    int speed;

public:
    Vehicle(string t) : type(t), speed(0) {}

    void setRandomSpeed()
    {
        speed = rand() % 101; // viteza random intre 0 si 100
    }

    void changeSpeed()
    {
        speed += rand() % 21 - 10; // schimbare viteza random intre -10 si 10
        if (speed < 0)
            speed = 0;
    }

    void display() const
    {
        cout << type << " speed: " << speed;
        if (speed == 0)
            cout << " (stopped)";
        cout << endl;
    }

    bool isMoving() const
    {
        return speed > 0;
    }

    int getSpeed() const
    {
        return speed;
    }
};

int main()
{
    srand(time(0));
    vector<Vehicle> vehicles = {Vehicle("Bike"), Vehicle("Car"), Vehicle("Plane")};

    for (auto &vehicle : vehicles)
        vehicle.setRandomSpeed();

    cout << "Initial vehicle speeds:" << endl;
    for (const auto &vehicle : vehicles)
        vehicle.display();

    for (auto &vehicle : vehicles)
        vehicle.changeSpeed();

    cout << "\nUpdated vehicle speeds:" << endl;
    for (const auto &vehicle : vehicles)
        vehicle.display();

    int movingVehicles = 0, totalSpeed = 0;
    for (const auto &vehicle : vehicles)
    {
        if (vehicle.isMoving())
        {
            movingVehicles++;
            totalSpeed += vehicle.getSpeed();
        }
    }

    if (movingVehicles > 0)
        cout << "\nAverage speed of moving vehicles: " << totalSpeed / movingVehicles << endl;
    else
        cout << "\nNo vehicles are moving." << endl;

    return 0;
}