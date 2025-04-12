//
// Created by diogo on 12/04/2025.
//

#include "../headers/truck.h"


Truck::Truck() = default;
Truck::Truck(double capacity, int numPallets, std::vector<Pallet *> pallets) : capacity(capacity), numPallets(numPallets), pallets(pallets) {}
Truck::~Truck() = default;

double Truck::getCapacity() const {
    return capacity;
}

int Truck::getNumPallets() const {
    return numPallets;
}

std::vector<Pallet *> Truck::getPallets() const {
    return pallets;
}
