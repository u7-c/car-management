#include <iostream>
#include "CarSystem.h"
#include "RentalSystem.h"

using namespace std;

int main() {
    CarSystem carSys;         // manages all car records
    RentalSystem rentSys(carSys); // manages renting & returning

    int choice;

    while (true) {
        cout << "\n===== CAR RENTAL MENU =====\n";
        cout << "1. Show all cars\n";
        cout << "2. Add car\n";
        cout << "3. Rent a car\n";
        cout << "4. Return a car\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            carSys.showAll();
        }
        else if (choice == 2) {
            string brand, model;
            double price;
            cout << "Enter brand: ";
            cin >> brand;
            cout << "Enter model: ";
            cin >> model;
            cout << "Enter price: ";
            cin >> price;

            try {
                carSys.addCar(brand, model, price);
                cout << "Car added!\n";
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
        else if (choice == 3) {
            string id;
            cout << "Enter Car ID to rent: ";
            cin >> id;

            try {
                rentSys.rentCar(id);
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
        else if (choice == 4) {
            string id;
            cout << "Enter Car ID to return: ";
            cin >> id;

            try {
                rentSys.returnCar(id);
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
        else if (choice == 5) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid option!\n";
        }
    }

    return 0;
}
