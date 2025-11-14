#include "Car.h"
#include <iostream>
#include <sstream>

Car::Car(int i, const std::string& b, const std::string& m, double p)
: Vehicle(i, b, m, p) {}

void Car::display() const {
    std::cout << id << " " << brand << " " << model << " " << price << "\n";
}

std::string Car::serialize() const {
    std::ostringstream out;
    out << id << "," << brand << "," << model << "," << price;
    return out.str();
}
