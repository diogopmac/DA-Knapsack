#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <string>

#include "../data_structures/truck.h"

class Algorithms {
    public:
    Algorithms();
    ~Algorithms();
    std::vector<Pallet *> brute_force(const Truck& truck);
    std::vector<Pallet *> dynamic_program(const Truck& truck);
    std::vector<Pallet *> approximation(const Truck& truck);
    std::vector<Pallet *> int_linear_program(const Truck& truck);
};

#endif //ALGORITHMS_H
