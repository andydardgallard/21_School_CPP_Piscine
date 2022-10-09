#include "Weapon.hpp"
#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &club)
{
    this->name = name;
    this->club = &club;
}

HumanA::~HumanA(){}

void HumanA::attack()
{
    std::cout << name << " attacks with their " << club->getType() << std::endl;
}
