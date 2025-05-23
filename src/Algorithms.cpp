#include "../headers/Algorithms.h"
#include <cmath>
#include <bitset>
#include <iostream>
#include <ostream>
#include <algorithm>

using namespace std;

Algorithms::Algorithms() = default;

Algorithms::~Algorithms() = default;

bool sortByValue(Pallet* a, Pallet* b) {
    if (a->getValue() == b->getValue()) {
        return a->getWeight() < b->getWeight();
    }
    return a->getValue() > b->getValue();
}

bool sortByRatio(Pallet* a, Pallet* b) {
    if (a->getRatio() == b->getRatio()) {
        return a->getWeight() > b->getWeight();
    }
    return a->getRatio() > b->getRatio();
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

std::vector<Pallet *> Algorithms::dp_vector(const Truck& truck) {
    vector<Pallet *> sol;
    vector<Pallet *> pallets = truck.getPallets();


    std::vector dp(pallets.size()+1, std::vector<double>(truck.getCapacity()+1, 0));


    for (int i = 1; i < pallets.size()+1; i++) {
        for (int j = 1; j < truck.getCapacity()+1; j++) {
            double option1 = dp[i-1][j];
            double option2 = 0;
            if (j - pallets[i-1]->getWeight() >= 0) option2 = dp[i-1][j - pallets[i-1]->getWeight()] + pallets[i-1]->getValue();
            dp[i][j] = max(option1, option2);
        }
    }

    int i = pallets.size();
    int j = truck.getCapacity();

    while (i > 0 && j > 0) {
        if (dp[i][j] != dp[i-1][j]) {
            sol.push_back(pallets[i-1]);
            j -= pallets[i-1]->getWeight();
        }
        i--;
    }
    std::reverse(sol.begin(), sol.end());
    return sol;
}

std::vector<Pallet *> Algorithms::dynamic_program(const Truck& truck) {
    return dp_vector(truck);
}

std::pair<std::vector<Pallet *>, std::pair<double, double>>  Algorithms::approximation_by_value(const Truck& truck) {
    double value = 0;
    double weight = 0;
    int index = 0;

    vector<Pallet *> pallets = truck.getPallets();
    std::sort(pallets.begin(), pallets.end(), sortByValue);

    vector<Pallet *> sol;

    while (weight <= truck.getCapacity() && index < pallets.size()) {
        if (pallets[index]->getWeight() + weight <= truck.getCapacity()) {
            sol.push_back(pallets[index]);
            weight += pallets[index]->getWeight();
            value += pallets[index]->getValue();
        }
        index++;
    }

    return std::make_pair(sol, std::make_pair(weight, value));
}

std::pair<std::vector<Pallet *>, std::pair<double, double>> Algorithms::approximation_by_ratio(const Truck& truck) {
    double value = 0;
    double weight = 0;
    int index = 0;

    vector<Pallet *> pallets = truck.getPallets();
    std::sort(pallets.begin(), pallets.end(), sortByRatio);

    vector<Pallet *> sol;

    while (weight <= truck.getCapacity() && index < pallets.size()) {
        if (pallets[index]->getWeight() + weight <= truck.getCapacity()) {
            sol.push_back(pallets[index]);
            weight += pallets[index]->getWeight();
            value += pallets[index]->getValue();
        }
        index++;
    }

    return std::make_pair(sol, std::make_pair(weight, value));
}

std::vector<Pallet *> Algorithms::approximation(const Truck& truck) {
    pair<vector<Pallet *>, pair<double, double>> sol_value = approximation_by_value(truck);
    pair<vector<Pallet *>, pair<double, double>> sol_ratio = approximation_by_ratio(truck);

    cout << "Solution 1 (Select by Value):\n"
            "Weight used: " <<  sol_value.second.first << " Value obtained: " <<  sol_value.second.second << endl;
    cout << "Solution 2 (Select by Ratio):\n"
            "Weight used: " << sol_ratio.second.first << " Value obtained: " << sol_ratio.second.second << endl;

    return sol_value.second > sol_ratio.second ? sol_value.first : sol_ratio.first;
}

vector<Pallet *> Algorithms::int_linear_program(const Truck& truck) {
    vector<Pallet *> sol;
    return sol;
}
