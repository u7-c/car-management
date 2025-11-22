#include "Car.h"
#include <iostream>
#include <sstream>

Car::Car(int i, const std::string& b, const std::string& m, double p, bool r)
: Vehicle(i, b, m, p), rented(r) {}

void Car::display() const {
    std::cout << id << " " << brand << " " << model << " " << price 
              << " " << (rented ? "Rented" : "Available") << "\n";
}

std::string Car::serialize() const {
    std::ostringstream out;
    out << id << "," << brand << "," << model << "," << price << "," << (rented ? 1 : 0);
    return out.str();
}

bool Car::isRented() const { return rented; }
void Car::setRented(bool r) { rented = r; }
