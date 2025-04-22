#ifndef ALGORTIHMS_H
#define ALGORTIHMS_H
#include <string>

#include "../data_structures/truck.h"

class Algorithms {
    public:
    Algorithms();
    ~Algorithms();
    std::vector<Pallet *> brute_force(Truck& truck);
    std::vector<Pallet *> dynamic_program(Truck& truck);
    std::vector<Pallet *> approximation(Truck& truck);
    std::vector<Pallet *> int_linear_program(Truck& truck);
};

#endif //ALGORTIHMS_H
