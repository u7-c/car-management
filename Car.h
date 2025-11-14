#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
public:
    Car(int, const std::string&, const std::string&, double);
    void display() const override;
    std::string serialize() const override;
};
