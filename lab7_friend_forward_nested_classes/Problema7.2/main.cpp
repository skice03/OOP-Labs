#include <iostream>
#include <vector>

using namespace std;

class Driver
{
public:
    string name;

    Driver(string n) : name(n) {}
    void display() const
    {
        cout << "Driver: " << name << endl;
    }
};

class Car
{
public:
    string licensePlate;

    Car(string lp) : licensePlate(lp) {}
    void display() const
    {
        cout << "Car License Plate: " << licensePlate << endl;
    }
};

class ManagementSystem
{
private:
    vector<pair<Driver, Car>> records;

public:
    void addRecord(const Driver &driver, const Car &car)
    {
        records.emplace_back(driver, car);
    }

    void removeRecord(int index)
    {
        if (index >= 0 && index < records.size())
            records.erase(records.begin() + index);
    }

    void displayRecords() const
    {
        cout << "Driver-Car Records:" << endl;
        for (const auto &record : records)
        {
            record.first.display();
            record.second.display();
            cout << "------------------" << endl;
        }
    }

    int getRecordCount() const
    {
        return records.size();
    }
};

int main()
{
    ManagementSystem system;

    system.addRecord(Driver("Jake"), Car("MIU-123"));
    system.addRecord(Driver("John Smith"), Car("CAR-098"));

    cout << "All Records:" << endl;
    system.displayRecords();

    cout << "Total Records: " << system.getRecordCount() << endl;

    system.removeRecord(0);
    cout << "\nAfter Removal:" << endl;
    system.displayRecords();

    return 0;
}