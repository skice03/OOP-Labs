#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Address
{
private:
    string street;
    string city;
    string postalCode;

public:
    Address(string street, string city, string postalCode)
        : street(street), city(city), postalCode(postalCode) {}

    string getStreet() const { return street; }
    string getCity() const { return city; }
    string getPostalCode() const { return postalCode; }

    string getAddress() const
    {
        return street + ", " + city + ", " + postalCode;
    }
};

class Mosquito
{
private:
    string species;

public:
    Mosquito(string species) : species(species) {}

    string getSpecies() const { return species; }
};

class Person
{
protected:
    string name;
    Address address;

public:
    Person(string name, Address address) : name(name), address(address) {}

    string getName() const { return name; }
    Address getAddress() const { return address; }
};

class Student : public Person
{
public:
    Student(string name, Address address) : Person(name, address) {}
};

class Commuter : public Person
{
public:
    Commuter(string name, Address address) : Person(name, address) {}
};

class Engine
{
private:
    bool isStarted;

public:
    Engine() : isStarted(false) {}

    void start()
    {
        isStarted = true;
        cout << "Engine started." << endl;
    }

    void stop()
    {
        isStarted = false;
        cout << "Engine stopped." << endl;
    }

    bool isRunning() const { return isStarted; }
};

class Vehicle
{
protected:
    string make;
    string model;
    int year;

public:
    Vehicle(string make, string model, int year)
        : make(make), model(model), year(year) {}

    virtual void displayInfo() const
    {
        cout << make << " " << model << " (" << year << ")" << endl;
    }

    string getMake() const { return make; }
    string getModel() const { return model; }
    int getYear() const { return year; }
};

class Driver;

class Bus : public Vehicle
{
private:
    string busNumber;
    Engine engine;
    Driver *driver;
    vector<Person *> commuters;
    vector<Mosquito *> mosquitoes;

public:
    Bus(string busNumber, string make, string model, int year)
        : Vehicle(make, model, year), busNumber(busNumber), driver(nullptr) {}

    void setDriver(Driver *driver)
    {
        this->driver = driver;
    }

    void addCommuter(Person *commuter)
    {
        commuters.push_back(commuter);
    }

    void addMosquito(Mosquito *mosquito)
    {
        mosquitoes.push_back(mosquito);
    }

    bool hasMosquito(const string &species) const
    {
        for (const auto &mosquito : mosquitoes)
        {
            if (mosquito->getSpecies() == species)
            {
                return true;
            }
        }
        return false;
    }

    void startEngine()
    {
        engine.start();
    }

    int getCommuterCount() const
    {
        return commuters.size();
    }

    void displayBusInfo() const
    {
        cout << "Bus " << busNumber << " has " << commuters.size() << " commuters." << endl;
    }

    string getBusNumber() const { return busNumber; }
    vector<Person *> getCommuters() const { return commuters; }
    Driver *getDriver() const { return driver; }
    Engine &getEngine() { return engine; }
};

class Driver : public Person
{
public:
    Driver(string name, Address address) : Person(name, address) {}

    void driveBus(Bus *bus)
    {
        bus->startEngine();
        cout << "Driver " << getName() << " started driving bus " << bus->getBusNumber() << endl;
    }
};

class BusStation
{
private:
    string stationName;
    vector<Bus *> buses;

public:
    BusStation(string stationName) : stationName(stationName) {}

    void addBus(Bus *bus)
    {
        buses.push_back(bus);
    }

    void displayBuses() const
    {
        cout << "Buses at station " << stationName << ":" << endl;
        for (const auto &bus : buses)
        {
            cout << "Bus " << bus->getBusNumber() << endl;
        }
    }

    vector<Bus *> getBuses() const { return buses; }
    string getStationName() const { return stationName; }
};

class Apartment
{
private:
    string apartmentNumber;
    vector<Mosquito *> mosquitoes;

public:
    Apartment(string apartmentNumber) : apartmentNumber(apartmentNumber) {}

    void addMosquito(Mosquito *mosquito)
    {
        mosquitoes.push_back(mosquito);
    }

    bool hasMosquito(const string &species) const
    {
        for (const auto &mosquito : mosquitoes)
        {
            if (mosquito->getSpecies() == species)
            {
                return true;
            }
        }
        return false;
    }

    string getApartmentNumber() const { return apartmentNumber; }
    vector<Mosquito *> getMosquitoes() const { return mosquitoes; }
};

class Car : public Vehicle
{
private:
    bool hasMosquito;

public:
    Car(string make, string model, int year) : Vehicle(make, model, year), hasMosquito(false) {}

    void addMosquito()
    {
        hasMosquito = true;
    }

    bool checkMosquito() const
    {
        return hasMosquito;
    }
};

#endif