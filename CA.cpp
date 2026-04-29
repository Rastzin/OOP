#include <iostream>
#include <string>
using namespace std;

class Vehicle {
private:
    string brand;
    string model;
    int year;

public:
    Vehicle(string b, string m, int y) {
        brand = b;
        model = m;
        year = y;
    }

    virtual string GetInfo() {
        return brand + " " + model + " " + to_string(year);
    }
};

class Car : public Vehicle {
private:
    int numDoors;

public:
    Car(string b, string m, int y, int d) : Vehicle(b, m, y) {
        numDoors = d;
    }

    string GetInfo() {
        return Vehicle::GetInfo() + " " + to_string(numDoors) + " doors";
    }
};

class Motorcycle : public Vehicle {
private:
    bool hasSidecar;

public:
    Motorcycle(string b, string m, int y, bool s) : Vehicle(b, m, y) {
        hasSidecar = s;
    }

    string GetInfo() {
        return Vehicle::GetInfo() + (hasSidecar ? " sidecar" : " no sidecar");
    }
};

int main() {
    Car c("Toyota", "Corolla", 2022, 4);
    Motorcycle m("Yamaha", "R1", 2021, false);

    cout << c.GetInfo() << endl;
    cout << m.GetInfo() << endl;
    return 0;
}