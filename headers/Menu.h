//
// Created by diogo on 07/04/2025.
//

#ifndef MENU_H
#define MENU_H

#include "../data_structures/truck.h"

class Menu {
  public:
    Menu();
    ~Menu();
    void MainMenu();
    int getIntValue(const std::string &s);
  private:
    Truck truck;
    // Datareader
};

#endif //MENU_H
