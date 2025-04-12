#ifndef TRUCK_H
#define TRUCK_H

#include "pallet.h"
#include <vector>

class Truck {
  public:
    Truck();
    Truck(double capacity, int numPallets, std::vector<Pallet *> pallets);
    ~Truck();
    double getCapacity() const;
    int getNumPallets() const;
    std::vector<Pallet *> getPallets() const;
  private:
    double capacity{};
    int numPallets{};
    std::vector<Pallet *> pallets;
};


#endif //TRUCK_H
