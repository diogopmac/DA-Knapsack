#ifndef PALLET_H
#define PALLET_H

/**
 * @file pallet.h
 * Definition of the Pallet class.
 */

/**
 * @class Pallet
 * Represents a pallet providing methods to access its ID, weight, value, and value-to-weight ratio.
 */
class Pallet {
public:
    /**
     * Constructs a Pallet object with the given ID, weight, and value.
     * @param id The unique identifier of the pallet.
     * @param weight The weight of the pallet.
     * @param value The value of the pallet.
     */
    Pallet(int id, double weight, double value);

    /**
     * Destroys the Pallet object, cleaning up its resources.
     */
    ~Pallet();

    /**
     * Gets the ID of the pallet.
     * @return The unique identifier of the pallet.
     */
    int getId() const;

    /**
     * Gets the weight of the pallet.
     * @return The weight of the pallet.
     */
    double getWeight() const;

    /**
     * Gets the value of the pallet.
     * @return The value of the pallet.
     */
    double getValue() const;

    /**
     * Gets the value-to-weight ratio of the pallet.
     * @return The value-to-weight ratio of the pallet.
     */
    double getRatio() const;

private:
    int id;        ///< The unique identifier of the pallet.
    double weight; ///< The weight of the pallet.
    double value;  ///< The value of the pallet.
    double ratio;  ///< The value-to-weight ratio of the pallet.
};

#endif // PALLET_H