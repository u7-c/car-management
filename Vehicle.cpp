#include "Vehicle.h"

Vehicle::Vehicle(int i, const std::string& b, const std::string& m, double p)
    : id(i), brand(b), model(m), price(p) {}

int Vehicle::getId() const {
    return id;
}
