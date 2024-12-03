#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <cstdlib>
#include <ctime>
#include "Chef.h"
#include "Dish.h"
#include "Restaurant.h"

void displayMainMenu() {
    std::cout << "Welcome to the Restaurant Management Game!\n";
    std::cout << "1. Start New Game\n";
    std::cout << "2. Load Game\n";
    std::cout << "3. Exit\n";
}

std::unique_ptr<Restaurant> startNewGame(std::vector<Dish>& dishes) {
    std::string restaurantName;
    std::cout << "Enter your restaurant name: ";
    std::cin.ignore();
    std::getline(std::cin, restaurantName);

    std::vector<std::unique_ptr<Chef>> chefCandidates;
    chefCandidates.push_back(std::make_unique<Chef>("Gordon Ramsay", 10, 100, 50, std::vector<std::string>{"Boiling", "Baking", "Grilling"}));
    chefCandidates.push_back(std::make_unique<Chef>("Jamie Oliver", 8, 90, 45, std::vector<std::string>{"Sauce Preparation", "Vegetable Cutting"}));
    chefCandidates.push_back(std::make_unique<Chef>("Julia Child", 5, 80, 60, std::vector<std::string>{"French Cuisine", "Baking"}));

    std::cout << "Choose your head chef:\n";
    for (size_t i = 0; i < chefCandidates.size(); ++i) {
        std::cout << i + 1 << ". " << chefCandidates[i]->getName() << "\n";
    }

    int chefChoice;
    std::cin >> chefChoice;
    while (chefChoice < 1 || chefChoice > static_cast<int>(chefCandidates.size())) {
        std::cout << "Invalid choice. Please select a valid chef.\n";
        std::cin >> chefChoice;
    }

    std::unique_ptr<Chef> selectedChef = std::move(chefCandidates[chefChoice - 1]);
    std::unique_ptr<Restaurant> restaurant = std::make_unique<Restaurant>(restaurantName, std::move(selectedChef));

    dishes = {
        Dish("Pasta", -5, 10, 15, {"Boiling", "Sauce Preparation"}),
        Dish("Pizza", -10, 15, 20, {"Baking", "Dough Preparation"}),
        Dish("Salad", -2, 5, 10, {"Vegetable Cutting"}),
    };

    std::cout << "New game started successfully!\n";
    return restaurant;
}

void gameLoop(Restaurant& restaurant, std::vector<Dish>& dishes) {
    while (true) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Serve Food\n";
        std::cout << "2. Manage Staff\n";
        std::cout << "3. Save Game\n";
        std::cout << "4. Exit Game\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1:
                restaurant.serveFood(dishes);
                break;
            case 2:
                restaurant.manageStaff();
                break;
            case 3:
                restaurant.saveGame();
                break;
            case 4:
                std::cout << "Exiting game. Goodbye!\n";
                return;
            default:
                std::cout << "Invalid choice. Please select an option from the menu.\n";
                break;
        }
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<Dish> dishes;
    std::unique_ptr<Restaurant> restaurant;

    while (true) {
        displayMainMenu();
        int mainChoice;
        std::cin >> mainChoice;

        if (mainChoice == 1) {
            restaurant = startNewGame(dishes);
            gameLoop(*restaurant, dishes);
            break;
        } else if (mainChoice == 2) {
            restaurant = std::make_unique<Restaurant>("", nullptr);
            restaurant->loadGame();
            if (restaurant->getChef() != nullptr) {
                dishes = {
                    Dish("Pasta", -5, 10, 15, {"Boiling", "Sauce Preparation"}),
                    Dish("Pizza", -10, 15, 20, {"Baking", "Dough Preparation"}),
                    Dish("Salad", -2, 5, 10, {"Vegetable Cutting"}),
                };
                gameLoop(*restaurant, dishes);
                break;
            } else {
                std::cout << "Failed to load game. Starting a new game.\n";
                restaurant = startNewGame(dishes);
                gameLoop(*restaurant, dishes);
                break;
            }
        } else if (mainChoice == 3) {
            std::cout << "Thank you for playing!\n";
            break;
        } else {
            std::cout << "Invalid choice. Please select a valid option.\n";
        }
    }

    return 0;
}
