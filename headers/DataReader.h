#ifndef DATAREADER_H
#define DATAREADER_H
#include <string>

#include "../data_structures/truck.h"

class DataReader {
    public:
    DataReader();
    ~DataReader();
    int readPallets(const std::string& fileName, Truck& truck);
    int readTrucks(const std::string& fileName, Truck& truck);
};

#endif //DATAREADER_H
