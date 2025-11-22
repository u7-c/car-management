#include "CarSystem.h"
#include <fstream>
using namespace std;

int CarSystem::nextId = 1;

CarSystem::CarSystem() {
    count = 0;
    load();
}

CarSystem::~CarSystem() {
    for (int i = 0; i < count; i++) {
        delete list[i];
    }
}

void CarSystem::addCar(const string& brand, const string& model, double price) {
    if (count >= 100) throw LimitReachedException();
    string id = "C" + to_string(nextId++);
    list[count++] = new Car(id, brand, model, price, false);
    save();
}

void CarSystem::showAll() const {
    for (int i = 0; i < count; i++) {
        list[i]->display();
    }
}

void CarSystem::save() const {
    ofstream fout("vehicles.txt");
    for (int i = 0; i < count; i++) {
        list[i]->serialize(fout);
    }
}

void CarSystem::load() {
    ifstream fin("vehicles.txt");
    if (!fin) return;

    string id, brand, model;
    double price;
    int rentedValue;

    while (fin >> id >> brand >> model >> price >> rentedValue) {
        list[count++] = new Car(id, brand, model, price, rentedValue == 1);
        int num = stoi(id.substr(1));
        if (num >= nextId) nextId = num + 1;
    }
}

void CarSystem::rentCar(int id) {
    string key = "C" + to_string(id);
    for (int i = 0; i < count; i++) {
        if (list[i]->getId() == key) {
            Car* c = dynamic_cast<Car*>(list[i]);
            if (c->isRented()) throw CarAlreadyRentedException();
            c->setRented(true);

            ofstream fout("rental.txt", ios::app);
            fout << key << " | Rented\n";

            save();
            return;
        }
    }
    throw CarNotFoundException();
}

void CarSystem::returnCar(int id) {
    string key = "C" + to_string(id);
    for (int i = 0; i < count; i++) {
        if (list[i]->getId() == key) {
            Car* c = dynamic_cast<Car*>(list[i]);
            if (!c->isRented()) throw CarNotRentedException();
            c->setRented(false);

            ofstream fout("rental.txt", ios::app);
            fout << key << " | Returned\n";

            save();
            return;
        }
    }
    throw CarNotFoundException();
}

