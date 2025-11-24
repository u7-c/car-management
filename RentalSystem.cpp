#include "RentalSystem.h"
#include <iostream>
using namespace std;

RentalSystem::RentalSystem(CarSystem& sys) : system(sys) {}

void RentalSystem::rentCar(const string& id) {
    try {
        system.rentCar(stoi(id));
        cout << "Car " << id << " rented successfully.\n";
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}

void RentalSystem::returnCar(const string& id) {
    try {
        system.returnCar(stoi(id));
        cout << "Car " << id << " returned successfully.\n";
    } catch (const exception& e) {
        cout << e.what() << endl;
    }
}
