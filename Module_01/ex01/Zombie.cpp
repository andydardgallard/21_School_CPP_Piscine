#include "Zombie.hpp"

Zombie::Zombie()
{

}

Zombie::~Zombie()
{
	std::cout << n << " " << name << ": freed" << std::endl;
}

void Zombie::set(int n, std::string name)
{
	this->n = n;
	this->name = name;
}

void Zombie::annonce(void)
{
	std::cout << n << " " << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
