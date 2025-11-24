#pragma once
#include <string>
#include "CarSystem.h"

class RentalSystem {
private:
    CarSystem& system;

public:
    RentalSystem(CarSystem& sys);

    void rentCar(const std::string& id);
    void returnCar(const std::string& id);
};
