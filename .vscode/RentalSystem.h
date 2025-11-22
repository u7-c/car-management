#ifndef RENTAL_SYSTEM_H
#define RENTAL_SYSTEM_H

#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include "Exceptions.h"
#include "Car.h"

class RentalSystem {
private:
    vector<Car> &cars;   

    string getTime() {
        time_t now = time(0);
        char* dt = ctime(&now);
        string s(dt);
        s.pop_back(); 
        return s;
    }

    void logRental(string carID, string action) {
        ofstream fout("rental.txt", ios::app);
        fout << carID << " | " << action << " | " << getTime() << "\n";
        fout.close();
    }

public:
    RentalSystem(vector<Car> &carsList) : cars(carsList) {}

    void rentCar(string carID) {
        for (auto &car : cars) {
            if (car.getId() == carID) {

                if (car.isRented())
                    throw CarAlreadyRentedException();

                car.setRented(true);
                logRental(carID, "Rented");
                cout << "Car " << carID << " rented successfully!\n";
                return;
            }
        }
        throw CarNotFoundException();
    }

    void returnCar(string carID) {
        for (auto &car : cars) {
            if (car.getId() == carID) {

                if (!car.isRented())
                    throw CarNotRentedException();

                car.setRented(false);
                logRental(carID, "Returned");
                cout << "Car " << carID << " returned successfully!\n";
                return;
            }
        }
        throw CarNotFoundException();
    }
};

#endif
