#include "CarSystem.h"
#include <fstream>
#include <sstream>
#include <stdexcept>

int CarSystem::nextId = 1;

CarSystem::CarSystem() {
    load();
}

CarSystem::~CarSystem() {
    for (auto v : list) delete v;
}

void CarSystem::load() {
    std::ifstream in("vehicles.txt");
    std::string line;
    while (std::getline(in, line)) {
        std::stringstream s(line);
        int id;
        std::string brand, model;
        double price;
        char c;
        s >> id >> c >> brand >> c >> model >> c >> price;
        list.push_back(new Car(id, brand, model, price));
        if (id >= nextId) nextId = id + 1;
    }
}

void CarSystem::save() const {
    std::ofstream out("vehicles.txt", std::ios::trunc);
    for (auto v : list) out << v->serialize() << "\n";
}

void CarSystem::addCar(const std::string& brand, const std::string& model, double price) {
    list.push_back(new Car(nextId++, brand, model, price));
    save();
}

void CarSystem::show() const {
    for (auto v : list) v->display();
}
