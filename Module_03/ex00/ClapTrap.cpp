/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:44:11 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/09 06:04:45 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("ClapTrap Default name"), hit_pnts(10), enrgy_pnts(10), attck_dmg(0)
{
	std::cout << "ClapTrap Default constructor is called for: " << name << ": Hit points: ";
	std::cout << hit_pnts << " Energy points: " << enrgy_pnts;
	std::cout << " Attack demage: " << attck_dmg << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap Copy constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor is called for: " << name << std::endl;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "ClapTrap Assignment operator is called" << std::endl;
	if (this == &other)
		return *this;
	this->name = other.name;
	this->hit_pnts = other.hit_pnts;
	this->enrgy_pnts = other.enrgy_pnts;
	this->attck_dmg = other.attck_dmg;
	return *this;
}

ClapTrap::ClapTrap(const std::string& name)
{
	this->name = name;
	hit_pnts = 10;
	enrgy_pnts = 10;
	attck_dmg = 0;
	std::cout << "ClapTrap Init constructor is called for: " << name << ": Hit points: ";
	std::cout << hit_pnts << " Energy points: " << enrgy_pnts;
	std::cout << " Attack demage: " << attck_dmg << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(hit_pnts >= 0 && enrgy_pnts)
	{
		enrgy_pnts -= 1;
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attck_dmg << " points of damage!" << std::endl;
	}
	else if (hit_pnts <= 0)
		std::cout << "ClapTrap No Hit points left for attack. Hit points = " << hit_pnts << ", Energy points = " << enrgy_pnts << std::endl;
	else
		std::cout << "ClapTrap No Energy points left for attack. Hit points = " << hit_pnts << ", Energy points = " << enrgy_pnts << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
	if (hit_pnts >= 0)
	{
		hit_pnts -= amount;
		std::cout << "ClapTrap " << name << " take " << amount << " points of damage! Hit points left = " << hit_pnts << std::endl;
	}
	else
		std::cout << "ClapTrap No Hit points left. " << name << " is Died! Hit points = " << hit_pnts << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(hit_pnts >= 0 && enrgy_pnts)
	{
		hit_pnts += amount;
		enrgy_pnts -= 1;
		std::cout << "ClapTrap " << name << " repaired " << amount << " Hit points left = " << hit_pnts << ", Energy points = " << enrgy_pnts << std::endl;
	}
	else if (hit_pnts <= 0)
		std::cout << "ClapTrap No Hit points left for repaire. Hit points = " << hit_pnts << ", Energy points = " << enrgy_pnts << std::endl;
	else
		std::cout << "ClapTrap No Energy points left for repaire. Hit points = " << hit_pnts << ", Energy points = " << enrgy_pnts << std::endl;
}
