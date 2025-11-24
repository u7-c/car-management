#pragma once
#include <exception>

class CarNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Car not found!";
    }
};

class CarAlreadyRentedException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Car is already rented!";
    }
};

class CarNotRentedException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Car is not rented yet!";
    }
};

class LimitReachedException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Car limit reached!";
    }
};

class InvalidTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Invalid vehicle type!";
    }
};
