#ifndef TRUCK_H
#define TRUCK_H

#include "pallet.h"
#include <vector>

class Truck {
  public:
    Truck(double capacity, int numPallets, std::vector<Pallet *> pallets);
    ~Truck();
    double getCapacity() const;
    int getNumPallets() const;
    std::vector<Pallet *> getPallets() const;
  private:
    double capacity;
    int numPallets;
    std::vector<Pallet *> pallets;
};

Truck::Truck(double capacity, int numPallets, std::vector<Pallet *> pallets) : capacity(capacity), numPallets(numPallets), pallets(pallets) {}
Truck::~Truck() {}

double Truck::getCapacity() const {
  return capacity;
}

int Truck::getNumPallets() const {
  return numPallets;
}

std::vector<Pallet *> Truck::getPallets() const {
  return pallets;
}

#endif //TRUCK_H
