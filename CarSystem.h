#pragma once
#include <vector>
#include <string>
#include "Car.h"

class CarSystem {
private:
    std::vector<Vehicle*> list;
    static int nextId;

public:
    CarSystem();
    ~CarSystem();
    void load();
    void save() const;

    void addCar(const std::string&, const std::string&, double);
    void show() const;
};
