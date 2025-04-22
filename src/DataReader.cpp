#include <iostream>
#include <fstream>
#include <sstream>
#include "../headers/DataReader.h"

#include "../data_structures/truck.h"

using namespace std;

DataReader::DataReader() = default;
DataReader::~DataReader() = default;

int DataReader::readTrucks(const std::string& fileName, Truck& truck) {
    ifstream file(fileName);
    if (!file) return 1;

    string capacityStr, numPalletsStr;
    double capacity;
    int numPallets;

    string line;
    getline(file, line);

    getline(file, line);
    istringstream iss(line);
    getline(iss, capacityStr, ',');
    getline(iss, numPalletsStr, '\r');

    capacity = stod(capacityStr);
    numPallets = stoi(numPalletsStr);

    truck.setCapacity(capacity);
    truck.setNumPallets(numPallets);

    return 0;
}


int DataReader::readPallets(const std::string& fileName, Truck& truck) {
    ifstream file(fileName);
    if (!file) return 1;

    string idStr, weightStr, valueStr;
    int id;
    double weight, value;
    vector<Pallet *> pallets;

    string line;
    getline(file, line);

    while (getline(file, line)) {
        istringstream iss(line);

        getline(iss, idStr, ',');
        getline(iss, weightStr, ',');
        getline(iss, valueStr, '\r');

        id = stoi(idStr);
        weight = stod(weightStr);
        value = stod(valueStr);

        pallets.push_back(new Pallet(id, weight, value));
    }
    truck.setPallets(pallets);
    file.close();

    return 0;
}



