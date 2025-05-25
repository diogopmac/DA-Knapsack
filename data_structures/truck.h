#ifndef TRUCK_H
#define TRUCK_H

#include "pallet.h"
#include <vector>

/**
 * @file truck.h
 * Declaration of the Truck class.
 */

/**
 * @class Truck
 * @brief Represents a truck with a specific capacity and a set of pallets.
 */
class Truck {
  public:
    /**
     * Default constructor for the Truck class.
     */
    Truck();

    /**
     * Constructs a Truck object with the given ID, capacity, number of pallets and pallets.
     * @param id The unique identifier of the truck.
     * @param capacity The maximum capacity of the truck in weight.
     * @param numPallets The number of pallets the truck can carry.
     * @param pallets A vector of pointers to the pallets currently loaded on the truck.
     */
    Truck(int id, double capacity, int numPallets, std::vector<Pallet *> pallets);

    /**
     * Destroys the Truck object, cleaning up its resources.
     */
    ~Truck();

    /**
     * Gets the unique identifier of the truck.
     * @return The ID of the truck.
     */
    int getId() const;

    /**
     * Gets the maximum capacity of the truck.
     * @return The capacity of the truck.
     */
    double getCapacity() const;

    /**
     * Gets the number of pallets the truck can carry.
     * @return The number of pallets.
     */
    int getNumPallets() const;

    /**
     * Gets the list of pallets currently loaded on the truck.
     * @return A vector of pointers to the pallets.
     */
    std::vector<Pallet *> getPallets() const;

    /**
     * Checks if the truck is currently loaded with pallets.
     * @return True if the truck is loaded, false otherwise.
     */
    bool isLoaded() const;

    /**
     * Sets the unique identifier of the truck.
     * @param id The new ID of the truck.
     */
    void setId(int id);

    /**
     * Sets the maximum capacity of the truck.
     * @param capacity The new capacity of the truck.
     */
    void setCapacity(double capacity);

    /**
     * Sets the number of pallets the truck can carry.
     * @param numPallets The new number of pallets.
     */
    void setNumPallets(int numPallets);

    /**
     * Sets the list of pallets currently loaded on the truck.
     * @param pallets A vector of pointers to the new pallets.
     */
    void setPallets(std::vector<Pallet *> pallets);

  private:
    int id; ///< The unique identifier of the truck.
    double capacity; ///< The maximum capacity of the truck in weight.
    int numPallets; ///< The number of pallets the truck can carry.
    std::vector<Pallet *> pallets; ///< A vector of pointers to the pallets currently loaded on the truck.
};

#endif // TRUCK_H