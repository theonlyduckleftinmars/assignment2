#ifndef RESTAURANT_H
#define RESTAURANT_H

#include "Chef.h"
#include "Dish.h"
#include <string>
#include <vector>

class Restaurant {
public:
    Restaurant(const std::string& name, std::unique_ptr<Chef> chef);

    void serveFood(const std::vector<Dish>& dishes);
    void manageStaff();
    void saveGame() const;
    void loadGame();

    Chef* getChef() const;
    std::string getName() const;

    void setName(const std::string& name);

private:
    std::string name;
    std::unique_ptr<Chef> chef;
};

#endif // RESTAURANT_H
