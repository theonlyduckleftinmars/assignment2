#include "Chef.h"
#include <iostream>
#include <algorithm>

Chef::Chef(const std::string& name, int stress, int stamina, int reputation, const std::vector<std::string>& skills)
    : name(name), stress(stress), stamina(stamina), reputation(reputation), skills(skills) {}

void Chef::cook(const Dish& dish) {
    if (canCook(dish)) {
        std::cout << name << " is cooking " << dish.getName() << std::endl;
        stress += dish.getStressBoost();
        stamina += dish.getStaminaBoost();
        reputation += dish.getReputationBoost();

        std::cout << "Stats updated: Stress=" << stress
                  << ", Stamina=" << stamina
                  << ", Reputation=" << reputation << std::endl;
    } else {
        std::cout << name << " does not have the skills required to cook " << dish.getName() << std::endl;
    }
}

void Chef::manageStaff() {
    std::cout << name << " is managing the staff.\n";
}

bool Chef::canCook(const Dish& dish) const {
    const auto& requiredSkills = dish.getRequiredSkills();
    return std::all_of(requiredSkills.begin(), requiredSkills.end(), [this](const std::string& skill) {
        return std::find(skills.begin(), skills.end(), skill) != skills.end();
    });
}

int Chef::getStress() const {
    return stress;
}

int Chef::getStamina() const {
    return stamina;
}

int Chef::getReputation() const {
    return reputation;
}

const std::vector<std::string>& Chef::getSkills() const {
    return skills;
}

std::string Chef::getName() const {
    return name;
}

void Chef::setStress(int stress) {
    this->stress = stress;
}

void Chef::setStamina(int stamina) {
    this->stamina = stamina;
}

void Chef::setReputation(int reputation) {
    this->reputation = reputation;
}
