#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->name = name;
}

HumanB::~HumanB(){}

Weapon  HumanB::setWeapon(Weapon &club)
{
    this->club = &club;
    return (club);
}

void    HumanB::attack()
{
    std::cout << name << " attacks with their " << this->club->getType() << std::endl;
}
