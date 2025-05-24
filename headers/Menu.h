#ifndef MENU_H
#define MENU_H

#include "../data_structures/truck.h"
#include "DataReader.h"
#include "Algorithms.h"

/**
 * @file Menu.h
 * Declaration of the Menu class, which provides an interface for interacting with the program's functionalities.
 */

 /**
  * @class Menu
  * Provides a user interface for interacting with the program's functionalities, including menus' display and user input handling.
  */
class Menu {
  public:
    /**
     * Constructs a Menu object.
     */
    Menu();

    /**
     * Destroys the Menu object, cleaning up its resources.
     */
    ~Menu();


    /**
     * Displays the main menu and handles user interaction.
     */
    void MainMenu();

    /**
     * Displays the brute force menu and handles user interaction, allowing him to choose choose a bractracking approach instead.
     */
    void BruteForceMenu();

    /**
     * Displays the dynamic programming menu and handles user interaction.
     */
    void DynamicProgrammingMenu();

    /**
     * Displays the approximation algorithm menu and handles user interaction.
     */
    void ApproximationMenu();

    /**
     * Displays the ILP (Integer Linear Programming) menu and handles user interaction.
     */
    void ILPMenu();

    /**
     * Validates and retrieves an integer value from a string input.
     * @param s The input string to validate and convert.
     * @return The integer value extracted from the string.
     */
    int getIntValue(const std::string &s);


    /**
     * Displays information about the truck.
     */
    void truckInformation();

    /**
     * Loads the truck with items.
     * @return `0` if the truck is successfully loaded, or `1` if the operation fails.
     */
    int loadTruck();

    /**
     * Waits for the user to press Enter.
     */
    void waitForEnter();

    /**
     * Clears the console screen for better readability.
     */
    void clearScreen();

  private:
    Truck truck; ///< The truck object used for managing truck-related operations.
    DataReader reader; ///< The data reader object for reading input data.
    Algorithms solver; ///< The algorithms object for solving the knapsack problem.
};

#endif //MENU_H