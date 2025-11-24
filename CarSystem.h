#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Exceptions.h"

class CarSystem {
private:
    Vehicle* list[100];
    int count;
    static int nextId;

public:
    CarSystem();
    ~CarSystem();

    void addCar(const std::string&, const std::string&, double);
    void showAll() const;
    void showTypes() const;

    void save() const;
    void load();

    void rentCar(int);
    void returnCar(int);
};

