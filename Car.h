#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
private:
    bool rented;
public:
    Car(int, const std::string&, const std::string&, double, bool = false);

    void display() const override;
    std::string serialize() const override;

    bool isRented() const;
    void setRented(bool);
};

