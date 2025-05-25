#include "../headers/Algorithms.h"
#include <cmath>
#include <bitset>
#include <iostream>
#include <ostream>
#include <functional>
#include <climits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>

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
    if (n >= 30) return {};

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

std::vector<Pallet *> Algorithms::backtracking_pruning(const Truck& truck) {
    const vector<Pallet *> &pallets = truck.getPallets();
    int n = pallets.size();
    double capacity = truck.getCapacity();
    if (n > 36) return {};

    vector<Pallet *> bestSolution;
    double maxValue = 0;
    int minPallets = INT_MAX;

    vector<Pallet *> currentSolution;

    // Memoization: key = (idx, currWeight), value = maxValue found so far
    map<pair<int, int>, double> memo;

    // Helper recursive function
    function<void(int, double, double)> backtrack = [&](int idx, double currWeight, double currValue) {
        int w = static_cast<int>(currWeight * 1000); // scale to avoid floating point issues in memoization
        auto key = make_pair(idx, w);
        if (memo.count(key) && memo[key] >= currValue) return;
        memo[key] = currValue;

        if (idx == n) {
            if ((currValue > maxValue) ||
                (currValue == maxValue && currentSolution.size() < minPallets)) {
                maxValue = currValue;
                minPallets = currentSolution.size();
                bestSolution = currentSolution;
            }
            return;
        }

        // Include current pallet if it fits
        if (currWeight + pallets[idx]->getWeight() <= capacity) {
            currentSolution.push_back(pallets[idx]);
            backtrack(idx + 1, currWeight + pallets[idx]->getWeight(), currValue + pallets[idx]->getValue());
            currentSolution.pop_back();
        }

        // Exclude current pallet
        backtrack(idx + 1, currWeight, currValue);
    };

    backtrack(0, 0.0, 0.0);
    return bestSolution;
}

std::vector<Pallet *> Algorithms::backtracking_no_pruning(const Truck& truck) {
    const vector<Pallet *> &pallets = truck.getPallets();
    int n = pallets.size();
    double capacity = truck.getCapacity();
    if (n > 36) return {};

    vector<Pallet *> bestSolution;
    double maxValue = 0;
    int minPallets = INT_MAX;

    vector<Pallet *> currentSolution;

    // Helper recursive function
    function<void(int, double, double)> backtrack = [&](int idx, double currWeight, double currValue) {
        if (idx == n) {
            if ((currValue > maxValue) ||
                (currValue == maxValue && currentSolution.size() < minPallets)) {
                maxValue = currValue;
                minPallets = currentSolution.size();
                bestSolution = currentSolution;
                }
            return;
        }


        // Include current pallet if it fits
        if (currWeight + pallets[idx]->getWeight() <= capacity) {
            currentSolution.push_back(pallets[idx]);
            backtrack(idx + 1, currWeight + pallets[idx]->getWeight(), currValue + pallets[idx]->getValue());
            currentSolution.pop_back();
        }

        // Exclude current pallet
        backtrack(idx + 1, currWeight, currValue);
    };

    backtrack(0, 0.0, 0.0);
    return bestSolution;
}

std::pair<std::vector<Pallet *>, std::pair<double, double>>  Algorithms::approximation_by_value(const Truck& truck) {
    double value = 0;
    double weight = 0;
    int index = 0;

    vector<Pallet *> pallets = truck.getPallets();
    ranges::sort(pallets, sortByValue);

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
    ranges::sort(pallets, sortByRatio);

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

std::vector<Pallet *> Algorithms::dynamic_program(const Truck& truck) {
    vector<Pallet *> sol;
    vector<Pallet *> pallets = truck.getPallets();

    std::vector dp(pallets.size()+1,
                                    std::vector<double>(truck.getCapacity()+1, 0));


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

    return sol;
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
    if (truck.getPallets().size() > 300) return {};
    ofstream outfile("../docs/input.txt");
    if (!outfile.is_open()) {
        cerr << "Unable to open file \"../docs/input.txt\"" << endl;
        return sol;
    }
    outfile << truck.getNumPallets() << "\n";
    outfile << truck.getCapacity() << "\n";

    auto pallets = truck.getPallets();
    for (auto i = 0; i < pallets.size(); ++i) {
        outfile << pallets[i]->getWeight();
        if (i != pallets.size() - 1) outfile << " ";
        else outfile << "\n";
    }

    for (size_t i = 0; i < pallets.size(); ++i) {
        outfile << pallets[i]->getValue();
        if (i != pallets.size() - 1) outfile << " ";
        else outfile << "\n";
    }

    outfile.close();

    int ret = system("../venv/bin/python ../docs/knapsack_solver.py ../docs/input.txt ../docs/output.txt >null");
    if (ret != 0) {
        std::cerr << "Unable to run knapsack_solver.py (" << ret << ")" << std::endl;
        return sol;
    }

    std::ifstream infile("../docs/output.txt");
    if (!infile.is_open()) {
        std::cerr << "Unable to open file \"../docs/output.txt\"" << std::endl;
        return sol;
    }

    std::vector<int> selected;
    std::string line;

    std::getline(infile, line);
    std::getline(infile, line);

    if (std::getline(infile, line)) {
        std::istringstream iss(line);
        int index;
        while (iss >> index) {
            selected.push_back(index);
        }
    }
    infile.close();

    for (int idx : selected) {
        sol.push_back(pallets[idx]);
    }

    return sol;
}
