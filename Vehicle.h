#pragma once
#include <string>

class Vehicle {
protected:
    int id;
    std::string brand;
    std::string model;
    double price;

public:
    Vehicle(int, const std::string&, const std::string&, double);
    virtual ~Vehicle() {}

    virtual void display() const = 0;
    virtual std::string serialize() const = 0;

    int getId() const;
};
