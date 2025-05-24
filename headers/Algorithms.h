#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <string>

#include "../data_structures/truck.h"

/**
 * @file Algorithms.h
 * @brief Header file for the Algorithms class, which implements various algorithms
 *        for solving the knapsack problem in the context of truck loading.
 * 
 * This class provides multiple approaches to solve the knapsack problem, including
 * brute force, backtracking, dynamic programming, approximation algorithms, and
 * integer linear programming.
 */

/**
 * @class Algorithms
 * A class that encapsulates different algorithms for solving the knapsack problem.
 */
class Algorithms {
public:
    /**
     * Constructs an Algorithms object.
     */
    Algorithms();

    /**
     * Destroys the Algorithms object, cleaning up its resources.
     */
    ~Algorithms();

    /**
     * Solves the knapsack problem using the brute force approach.
     * @param truck The truck object containing the constraints and pallets.
     * @return A vector of pointers to the selected pallets.
     * 
     * @note Time Complexity: O(2^n), where n is the number of pallets.
     * @note Space Complexity: O(n), due to recursion stack.
     */
    std::vector<Pallet *> brute_force(const Truck& truck);

    /**
     * Solves the knapsack problem using the backtracking approach.
     * 
     * @param truck The truck object containing the constraints and pallets.
     * @return A vector of pointers to the selected pallets.
     * 
     * @note Time Complexity: O(2^n), where n is the number of pallets.
     * @note Space Complexity: O(n), due to recursion stack.
     */
    std::vector<Pallet *> backtracking(const Truck& truck);

    /**
     * Solves the knapsack problem using dynamic programming.
     * @param truck The truck object containing the constraints and pallets.
     * @return A vector of pointers to the selected pallets.
     * 
     * @note Time Complexity: O(n * W), where n is the number of pallets and W is the truck's weight capacity.
     * @note Space Complexity: O(n * W), for the DP table.
     */
    std::vector<Pallet *> dynamic_program(const Truck& truck);

    /**
     * Solves the knapsack problem using an approximation algorithm based on value.
     * @param truck The truck object containing the constraints and pallets.
     * @return A pair containing the selected pallets and a pair of total value and weight.
     * 
     * @note Time Complexity: O(n log n), where n is the number of pallets (due to sorting).
     * @note Space Complexity: O(n), for storing the sorted pallets.
     */
    std::pair<std::vector<Pallet *>, std::pair<double, double>> approximation_by_value(const Truck& truck);

    /**
     * Solves the knapsack problem using an approximation algorithm based on value-to-weight ratio.
     * @param truck The truck object containing the constraints and pallets.
     * @return A pair containing the selected pallets and a pair of total value and weight.
     * 
     * @note Time Complexity: O(n log n), where n is the number of pallets (due to sorting).
     * @note Space Complexity: O(n), for storing the sorted pallets.
     */
    std::pair<std::vector<Pallet *>, std::pair<double, double>> approximation_by_ratio(const Truck& truck);

    /**
     * Solves the knapsack problem using a general approximation algorithm.
     * @param truck The truck object containing the constraints and pallets.
     * @return A vector of pointers to the selected pallets.
     */
    std::vector<Pallet *> approximation(const Truck& truck);

    /**
     * Solves the knapsack problem using integer linear programming (ILP).
     * @param truck The truck object containing the constraints and pallets.
     * @return A vector of pointers to the selected pallets.
     */
    std::vector<Pallet *> int_linear_program(const Truck& truck);
};

#endif //ALGORITHMS_H