#include <iostream>
#include "CarSystem.h"
#include "RentalSystem.h"

using namespace std;

int main() {
    CarSystem carSys;
    RentalSystem rentSys(carSys);

    int choice;
    
    while (true) {
        cout << "\n===== CAR SYSTEM MENU =====\n";
        cout << "1. Show all cars\n";
        cout << "2. Add car\n";
        cout << "3. Rent a car\n";
        cout << "4. Return a car\n";
        cout << "5. Show object types (RTTI)\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            carSys.showAll();
        }
        else if (choice == 2) {
            string brand, model;
            double price;

            cout << "\nEnter brand: ";
            cin >> brand;
            cout << "Enter model: ";
            cin >> model;
            cout << "Enter price: ";
            cin >> price;

            try {
                carSys.addCar(brand, model, price);
                cout << "Car added successfully.\n";
            } catch (const exception& e) {
                cout << e.what() << endl;
            }
        }
        else if (choice == 3) {
            string id;
            cout << "Enter Car ID (number only): ";
            cin >> id;
            rentSys.rentCar(id);
        }
        else if (choice == 4) {
            string id;
            cout << "Enter Car ID (number only): ";
            cin >> id;
            rentSys.returnCar(id);
        }
        else if (choice == 5) {
            carSys.showTypes();
        }
        else if (choice == 6) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid option. Try again.\n";
        }
    }

    return 0;
}
