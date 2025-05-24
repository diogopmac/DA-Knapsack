#ifndef DATAREADER_H
#define DATAREADER_H
#include <string>

#include "../data_structures/truck.h"

/**
 * @file DataReader.h
 * Declaration of the DataReader class, responsible for reading data from files.
 */

/**
 * @class DataReader
 * A utility class for reading pallet and truck data from files.
 */
class DataReader {
    public:
    /**
     * Constructs a DataReader object.
     */
    DataReader();

    /**
     * Destroys the DataReader object, cleaning up its resources.
     */
    ~DataReader();

    /**
     * Reads pallet data from a file and populates the given Truck object.
     * @param fileName The name of the file containing pallet data.
     * @param truck A reference to the Truck object to populate with pallet data.
     * @return `0` if the reading is successful, or `1` if the operation fails.
     */
    int readPallets(const std::string& fileName, Truck& truck);

    /**
     * Reads truck data from a file and populates the given Truck object.
     * @param fileName The name of the file containing truck data.
     * @param truck A reference to the Truck object to populate with truck data.
     * @return `0` if the reading is successful, or `1` if the operation fails.
     */
    int readTrucks(const std::string& fileName, Truck& truck);
};

#endif //DATAREADER_H
