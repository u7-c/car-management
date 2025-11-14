#include "CarSystem.h"
#include <iostream>

int main() {
    CarSystem sys;
    bool run = true;

    while (run) {
        std::cout << "1 Add Car\n2 Show Cars\n3 Exit\n";
        int ch;
        std::cin >> ch;

        if (ch == 1) {
            std::string brand, model;
            double price;
            std::cin >> brand >> model >> price;
            sys.addCar(brand, model, price);
        }

        else if (ch == 2) {
            sys.show();
        }

        else run = false;
    }
}
