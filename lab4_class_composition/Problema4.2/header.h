#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Address
{
private:
    string street;
    string city;
    string postalCode;

public:
    // constructor
    Address(string street, string city, string postalCode)
        : street(street), city(city), postalCode(postalCode) {}

    // afisare adresa
    void displayAddress() const
    {
        cout << "Street: " << street << ", City: " << city << ", Postal Code: " << postalCode << endl;
    }
};

// clasa pt. engine
class Engine
{
private:
    int horsepower;
    string engineType;

public:
    // constructor
    Engine(int horsepower, string engineType)
        : horsepower(horsepower), engineType(engineType) {}

    // informatii engine
    void displayEngineInfo() const
    {
        cout << "Horsepower: " << horsepower << " HP, Engine Type: " << engineType << endl;
    }
};

class Driver
{
private:
    string name;
    string licenseNumber;

public:
    Driver(string name, string licenseNumber)
        : name(name), licenseNumber(licenseNumber) {}

    void displayDriverInfo() const
    {
        cout << "Driver Name: " << name << ", License Number: " << licenseNumber << endl;
    }
};

class Commuter
{
private:
    string name;
    string ticketNumber;

public:
    Commuter(string name, string ticketNumber)
        : name(name), ticketNumber(ticketNumber) {}

    string getTicketNumber() const
    {
        return ticketNumber;
    }

    void displayCommuterInfo() const
    {
        cout << "Commuter Name: " << name << ", Ticket Number: " << ticketNumber << endl;
    }
};

class Mosquito
{
private:
    string species;
    string location;

public:
    Mosquito(string species, string location)
        : species(species), location(location) {}

    void displayMosquitoInfo() const
    {
        cout << "Mosquito Species: " << species << ", Location: " << location << endl;
    }
};

class Car
{
private:
    string make;
    string model;
    int year;

public:
    Car(string make, string model, int year)
        : make(make), model(model), year(year) {}

    void displayCarInfo() const
    {
        cout << "Car Make: " << make << ", Model: " << model << ", Year: " << year << endl;
    }
};

class Bus : public Car
{
private:
    string busNumber;
    Engine engine;
    Driver driver;
    int capacity;
    vector<Commuter> commuters;

public:
    Bus(string busNumber, Engine engine, Driver driver, int capacity, string make, string model, int year)
        : Car(make, model, year), busNumber(busNumber), engine(engine), driver(driver), capacity(capacity) {}

    string getBusNumber() const
    {
        return busNumber;
    }

    void addCommuter(const Commuter &commuter)
    {
        if (commuters.size() < capacity)
        {
            commuters.push_back(commuter);
        }
        else
        {
            cout << "Bus is full!" << endl;
        }
    }

    void removeCommuter(const string &ticketNumber)
    {
        for (auto it = commuters.begin(); it != commuters.end(); ++it)
        {
            if (it->getTicketNumber() == ticketNumber)
            {
                commuters.erase(it);
                return;
            }
        }
        cout << "Commuter not found!" << endl;
    }

    void displayBusDetails() const
    {
        cout << "\nBus Number: " << busNumber << endl;
        engine.displayEngineInfo();
        driver.displayDriverInfo();
        cout << "Capacity: " << capacity << endl;
        for (const auto &commuter : commuters)
        {
            commuter.displayCommuterInfo();
        }
    }
};

class BusStation
{
private:
    string name;
    Address address;
    vector<Bus> buses;

public:
    BusStation(string name, Address address) : name(name), address(address) {}

    void addBus(const Bus &bus)
    {
        buses.push_back(bus);
    }

    void removeBus(const string &busNumber)
    {
        for (auto it = buses.begin(); it != buses.end(); ++it)
        {
            if (it->getBusNumber() == busNumber)
            {
                buses.erase(it);
                return;
            }
        }
        cout << "Bus not found!" << endl;
    }

    void displayBuses() const
    {
        cout << "\nBuses at " << name << " Station:" << endl;
        for (const auto &bus : buses)
        {
            bus.displayBusDetails();
        }
    }
};

#endif