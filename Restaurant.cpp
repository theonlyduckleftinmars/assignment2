#include "Restaurant.h"
#include <iostream>
#include <fstream>

Restaurant::Restaurant(const std::string& name, std::unique_ptr<Chef> chef)
    : name(name), chef(std::move(chef)) {}

void Restaurant::serveFood(const std::vector<Dish>& dishes) {
    std::cout << "Select a dish to serve:\n";
    for (size_t i = 0; i < dishes.size(); ++i) {
        std::cout << i + 1 << ". " << dishes[i].getName() << "\n";
    }

    int choice;
    std::cin >> choice;

    if (choice < 1 || choice > static_cast<int>(dishes.size())) {
        std::cout << "Invalid choice. Returning to menu.\n";
        return;
    }

    const Dish& selectedDish = dishes[choice - 1];
    if (chef->canCook(selectedDish)) {
        std::cout << "Serving " << selectedDish.getName() << "...\n";
        chef->cook(selectedDish);
    } else {
        std::cout << "Error: " << chef->getName() << " does not have the skills required to cook " << selectedDish.getName() << ".\n";
    }
}

void Restaurant::manageStaff() {
    std::cout << "Managing staff...\n";
    std::cout << "Chef's Stats:\n";
    std::cout << "Name: " << chef->getName() << "\n";
    std::cout << "Stress: " << chef->getStress() << "\n";
    std::cout << "Stamina: " << chef->getStamina() << "\n";
    std::cout << "Reputation: " << chef->getReputation() << "\n";
}

void Restaurant::saveGame() const {
    std::ofstream outFile("savegame.txt");
    if (outFile.is_open()) {
        outFile << name << "\n";
        outFile << chef->getName() << "\n";
        outFile << chef->getStress() << "\n";
        outFile << chef->getStamina() << "\n";
        outFile << chef->getReputation() << "\n";
        outFile << chef->getSkills().size() << "\n";
        for (const auto& skill : chef->getSkills()) {
            outFile << skill << "\n";
        }
        outFile.close();
        std::cout << "Game saved successfully.\n";
    } else {
        std::cout << "Error saving game.\n";
    }
}

void Restaurant::loadGame() {
    std::ifstream inFile("savegame.txt");
    if (inFile.is_open()) {
        std::string chefName;
        int stress, stamina, reputation, skillCount;
        std::vector<std::string> skills;

        std::getline(inFile, name);
        std::getline(inFile, chefName);
        inFile >> stress >> stamina >> reputation >> skillCount;
        inFile.ignore();

        for (int i = 0; i < skillCount; ++i) {
            std::string skill;
            std::getline(inFile, skill);
            skills.push_back(skill);
        }

        chef = std::make_unique<Chef>(chefName, stress, stamina, reputation, skills);
        inFile.close();
        std::cout << "Game loaded successfully.\n";
    } else {
        std::cout << "No saved game found. Starting a new game.\n";
    }
}

Chef* Restaurant::getChef() const {
    return chef.get();
}

std::string Restaurant::getName() const {
    return name;
}

void Restaurant::setName(const std::string& name) {
    this->name = name;
}
