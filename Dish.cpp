#include "Dish.h"

Dish::Dish(const std::string& name, int stressBoost, int staminaBoost, int reputationBoost, const std::vector<std::string>& requiredSkills)
    : name(name), stressBoost(stressBoost), staminaBoost(staminaBoost), reputationBoost(reputationBoost), requiredSkills(requiredSkills) {}

std::string Dish::getName() const {
    return name;
}

int Dish::getStressBoost() const {
    return stressBoost;
}

int Dish::getStaminaBoost() const {
    return staminaBoost;
}

int Dish::getReputationBoost() const {
    return reputationBoost;
}

const std::vector<std::string>& Dish::getRequiredSkills() const {
    return requiredSkills;
}
