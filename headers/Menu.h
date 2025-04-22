//
// Created by diogo on 07/04/2025.
//

#ifndef MENU_H
#define MENU_H

#include "../data_structures/truck.h"
#include "DataReader.h"

class Menu {
  public:
    Menu();
    ~Menu();
    void MainMenu();
    int getIntValue(const std::string &s);
    void truckInformation();
    int loadTruck();
  private:
    Truck truck;
    DataReader reader;
};

#endif //MENU_H
