#include "../headers/Algorithms.h"
#include <cmath>
#include <bitset>

using namespace std;

Algorithms::Algorithms() = default;

Algorithms::~Algorithms() = default;

std::vector<Pallet *> Algorithms::brute_force(const Truck& truck) {
    vector<Pallet *> sol;

    vector<Pallet *> pallets = truck.getPallets();
    int n = pallets.size();

    double maxvalue = 0;

    for (int i = 0; i < pow(2, n); i++) {
        bitset<20> binarySubset(i);
        double value = 0;
        double weight = 0;
        for (int k = 0; k < n; k++) {
            value += pallets[k]->getValue() * binarySubset[k];
            weight += pallets[k]->getWeight() * binarySubset[k];
        }
        if (value > maxvalue && weight <= truck.getCapacity()) {
            maxvalue = value;
            sol = {};
            for (int k = 0; k < n; k++) {
                if (binarySubset[k]) sol.push_back(pallets[k]);
            }
        }
    }
    return sol;
}


std::vector<Pallet *> Algorithms::dynamic_program(const Truck& truck) {
    vector<Pallet *> sol;
    return sol;
}

std::vector<Pallet *> Algorithms::approximation(const Truck& truck) {
    vector<Pallet *> sol;
    return sol;
}

vector<Pallet *> Algorithms::int_linear_program(const Truck& truck) {
    vector<Pallet *> sol;
    return sol;
}
