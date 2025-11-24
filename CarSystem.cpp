#include "CarSystem.h"
#include <fstream>
#include <iostream>
#include <typeinfo>

using namespace std;

int CarSystem::nextId = 1;

CarSystem::CarSystem() : count(0) {
    load();
}

CarSystem::~CarSystem() {
    for (int i = 0; i < count; i++) delete list[i];
}

void CarSystem::addCar(const string& brand, const string& model, double price) {
    if (count >= 100) throw LimitReachedException();
    list[count++] = new Car(nextId++, brand, model, price, false);
    save();
}

void CarSystem::showAll() const {
    if (count == 0) { cout << "No cars.\n"; return; }

    cout << "\n--- CAR LIST ---\n";
    for (int i = 0; i < count; i++) list[i]->display();
}

void CarSystem::save() const {
    ofstream fout("vehicles.txt");
    for (int i = 0; i < count; i++)
        fout << list[i]->serialize() << "\n";
}

void CarSystem::load() {
    ifstream fin("vehicles.txt");
    if (!fin) return;

    int id;
    string brand, model;
    double price;
    bool rented;

    while (fin >> id >> brand >> model >> price >> rented) {
        list[count++] = new Car(id, brand, model, price, rented);
        nextId = max(nextId, id + 1);
    }
}

void CarSystem::rentCar(int id) {
    for (int i = 0; i < count; i++)
        if (list[i]->getId() == id) {
            Car* c = dynamic_cast<Car*>(list[i]);
            if (!c) throw InvalidTypeException();
            if (c->isRented()) throw CarAlreadyRentedException();
            c->setRented(true);
            save();
            return;
        }
    throw CarNotFoundException();
}

void CarSystem::returnCar(int id) {
    for (int i = 0; i < count; i++)
        if (list[i]->getId() == id) {
            Car* c = dynamic_cast<Car*>(list[i]);
            if (!c) throw InvalidTypeException();
            if (!c->isRented()) throw CarNotRentedException();
            c->setRented(false);
            save();
            return;
        }
    throw CarNotFoundException();
}

void CarSystem::showTypes() const {
    cout << "\n--- RTTI OBJECT TYPES ---\n";
    for (int i = 0; i < count; i++)
        cout << "Object " << list[i]->getId()
         << " -> " << typeid(*list[i]).name() << endl;
}
