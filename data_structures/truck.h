#ifndef TRUCK_H
#define TRUCK_H

#include "pallet.h"
#include <vector>

class Truck {
  public:
    Truck();
    Truck(int id, double capacity, int numPallets, std::vector<Pallet *> pallets);
    ~Truck();

    int getId() const;
    double getCapacity() const;
    int getNumPallets() const;
    std::vector<Pallet *> getPallets() const;
    bool isLoaded() const;

    void setId(int id);
    void setCapacity(double capacity);
    void setNumPallets(int numPallets);
    void setPallets(std::vector<Pallet *> pallets);

  private:
    int id;
    double capacity{};
    int numPallets{};
    std::vector<Pallet *> pallets;
};


#endif //TRUCK_H
