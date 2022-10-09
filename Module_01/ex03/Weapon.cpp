#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
}

Weapon::Weapon(){}

Weapon::~Weapon(){}

void    Weapon::setType(std::string type)
{
    this->type = type;
}

std::string const &Weapon::getType()
{
    std::string const &str = type;
    return (str);
}
