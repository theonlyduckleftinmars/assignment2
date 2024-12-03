#ifndef DISH_H
#define DISH_H

#include <string>
#include <vector>

class Dish {
public:
    Dish(const std::string& name, int stressBoost, int staminaBoost, int reputationBoost, const std::vector<std::string>& requiredSkills);

    std::string getName() const;
    int getStressBoost() const;
    int getStaminaBoost() const;
    int getReputationBoost() const;
    const std::vector<std::string>& getRequiredSkills() const;

private:
    std::string name;
    int stressBoost;
    int staminaBoost;
    int reputationBoost;
    std::vector<std::string> requiredSkills;
};

#endif // DISH_H
