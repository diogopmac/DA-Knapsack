//
// Created by diogo on 12/04/2025.
//

#include "truck.h"


Truck::Truck() = default;
Truck::Truck(int id, double capacity, int numPallets, std::vector<Pallet *> pallets) : id(id), capacity(capacity), numPallets(numPallets), pallets(pallets) {}
Truck::~Truck() = default;

int Truck::getId() const {
    return id;
}

double Truck::getCapacity() const {
    return capacity;
}

int Truck::getNumPallets() const {
    return numPallets;
}

std::vector<Pallet *> Truck::getPallets() const {
    return pallets;
}

bool Truck::isLoaded() const {
    return !this->getPallets().empty();
}


void Truck::setId(int id) {
    this->id = id;
}

void Truck::setCapacity(double capacity) {
    this->capacity = capacity;
}

void Truck::setNumPallets(int numPallets) {
    this->numPallets = numPallets;
}

void Truck::setPallets(std::vector<Pallet *> pallets) {
    this->pallets = std::move(pallets);
}
