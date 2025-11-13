#ifndef CAR_H
#define CAR_H

#include "Vehicle.h"

class Car : public Vehicle {
private:
    int doors;

public:
    Car(string b, int y, int d) : Vehicle(b, y) {
        doors = d;
    }

    void displayInfo() override {
        Vehicle::displayInfo();
        cout << "Doors: " << doors << endl;
    }

    ~Car() override {
        cout << "Car is destroyed" << endl;
    }
};

#endif