#pragma once
#include "Vehicle.h"
#include "Car.h"
#include "Exceptions.h"
#include <string>

class CarSystem {
private:
    Vehicle* list[100];
    int count;
    static int nextId;

public:
    CarSystem();
    ~CarSystem();

    void addCar(const std::string& brand, const std::string& model, double price);
    void showAll() const;

    void save() const;
    void load();

    void rentCar(int id);
    void returnCar(int id);
};
