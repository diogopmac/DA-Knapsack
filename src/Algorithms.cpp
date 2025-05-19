#include "../headers/Algorithms.h"
#include <cmath>
#include <bitset>
#include <iostream>
#include <ostream>

using namespace std;

Algorithms::Algorithms() = default;

Algorithms::~Algorithms() = default;

bool comp(Pallet* a, Pallet* b) {
    if (a->getValue() == b->getValue()) {
        return a->getWeight() < b->getWeight();
    }
    return a->getValue() > b->getValue();
}

std::vector<Pallet *> Algorithms::brute_force(const Truck& truck) {
    vector<Pallet *> pallets = truck.getPallets();
    int n = pallets.size();
    if (n > 32) return {};

    vector<Pallet *> sol;

    double maxvalue = 0;

    for (int i = 0; i < (1 << n); i++) {
        bitset<32> binarySubset(i);
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

std::vector<Pallet *> Algorithms::approximation_by_value(const Truck& truck) {
    double value = 0;
    double weight = 0;

    vector<Pallet *> pallets = truck.getPallets();
    sort(pallets.begin(), pallets.end(), comp);

    for (int i = 0; i < pallets.size(); i++) {
        cout << pallets[i]->getValue() << " " << pallets[i]->getWeight() << endl;
    }
    return pallets;
}

std::vector<Pallet *> Algorithms::approximation_by_ratio(const Truck& truck) {
    return {};
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
