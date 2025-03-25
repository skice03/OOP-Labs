#include <iostream>
#include <vector>
#include <string>
#include "header.h"

using namespace std;

int main()
{
    // creare objects
    Address address("123 Main St", "Springfield", "98765");

    Engine engine(450, "Diesel");

    Driver driver("Jane Doe", "D12345");

    Commuter commuter1("Marian", "C001");
    Commuter commuter2("Sandel", "C002");

    Bus bus1("B001", engine, driver, 50, "Mercedes", "Sprinter", 2022);
    bus1.addCommuter(commuter1);
    bus1.addCommuter(commuter2);

    BusStation station("Central Station", address);
    station.addBus(bus1);

    // afisare informatii
    station.displayBuses();

    Mosquito mosquito("Anopheles", "Near Station");

    mosquito.displayMosquitoInfo();

    return 0;
}