#include "pallet.h"

Pallet::Pallet() = default;
Pallet::Pallet(int id, double weight, double value) : id(id), weight(weight), value(value), ratio(value / weight) {}
Pallet::~Pallet() = default;

int Pallet::getId() const {
    return id;
}

double Pallet::getWeight() const {
    return weight;
}

double Pallet::getValue() const {
    return value;
}

double Pallet::getRatio() const {
    return ratio;
}