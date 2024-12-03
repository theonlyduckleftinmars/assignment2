#ifndef CHEF_H
#define CHEF_H

#include <string>
#include <vector>
#include "Dish.h"

class Chef {
public:
    Chef(const std::string& name, int stress, int stamina, int reputation, const std::vector<std::string>& skills);

    void cook(const Dish& dish);
    void manageStaff();
    bool canCook(const Dish& dish) const;

    int getStress() const;
    int getStamina() const;
    int getReputation() const;
    const std::vector<std::string>& getSkills() const;
    std::string getName() const;

    void setStress(int stress);
    void setStamina(int stamina);
    void setReputation(int reputation);

private:
    std::string name;
    int stress;
    int stamina;
    int reputation;
    std::vector<std::string> skills;
};

#endif // CHEF_H
