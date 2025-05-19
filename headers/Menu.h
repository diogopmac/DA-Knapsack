//
// Created by diogo on 07/04/2025.
//

#ifndef MENU_H
#define MENU_H

#include "../data_structures/truck.h"
#include "DataReader.h"
#include "Algorithms.h"

class Menu {
  public:
    Menu();
    ~Menu();
    void MainMenu();
    void BruteForceMenu();
    int getIntValue(const std::string &s);
    void truckInformation();
    int loadTruck();
    void waitForEnter();
    void clearScreen();
  private:
    Truck truck;
    DataReader reader;
    Algorithms solver;
};

#endif //MENU_H
