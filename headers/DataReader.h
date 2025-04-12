#ifndef DATAREADER_H
#define DATAREADER_H
#include <string>

#include "../data_structures/truck.h"

class DataReader {
    public:
    DataReader();
    ~DataReader();
    void readPallets(std::string& fileName, Truck& truck);
    void readTrucks(std::string fileName, Truck& truck);
};

#endif //DATAREADER_H
