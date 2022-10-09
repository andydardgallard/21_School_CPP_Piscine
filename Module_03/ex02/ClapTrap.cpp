/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:44:11 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/11 00:11:15 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): _name("ClapTrap Default name"), _hit_pnts(10), _enrgy_pnts(10), _attck_dmg(0)
{
	std::cout << "ClapTrap Default constructor is called for: " << _name << ": Hit points: ";
	std::cout << _hit_pnts << " Energy points: " << _enrgy_pnts;
	std::cout << " Attack demage: " << _attck_dmg << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	*this = other;
	std::cout << "ClapTrap Copy constructor is called" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap Destructor is called for: " << _name << std::endl;
}

ClapTrap & ClapTrap::operator = (const ClapTrap &other)
{
	std::cout << "ClapTrap Assignment operator is called" << std::endl;
	if (this == &other)
		return *this;
	this->_name = other._name;
	this->_hit_pnts = other._hit_pnts;
	this->_enrgy_pnts = other._enrgy_pnts;
	this->_attck_dmg = other._attck_dmg;
	return *this;
}

ClapTrap::ClapTrap(const std::string& name): _name(name), _hit_pnts(10), _enrgy_pnts(10), _attck_dmg(0)
{
	std::cout << "ClapTrap Init constructor is called for: " << _name << ": Hit points: ";
	std::cout << _hit_pnts << " Energy points: " << _enrgy_pnts;
	std::cout << " Attack demage: " << _attck_dmg << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if(_hit_pnts >= 0 && _enrgy_pnts)
	{
		_enrgy_pnts -= 1;
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attck_dmg << " points of damage!" << std::endl;
	}
	else if (_hit_pnts <= 0)
		std::cout << "ClapTrap No Hit points left for attack. Hit points = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
	else
		std::cout << "ClapTrap No Energy points left for attack. Hit points = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
	if (_hit_pnts >= 0)
	{
		_hit_pnts -= amount;
		std::cout << "ClapTrap " << _name << " take " << amount << " points of damage! Hit points left = " << _hit_pnts << std::endl;
	}
	else
		std::cout << "ClapTrap No Hit points left. " << _name << " is Died! Hit points = " << _hit_pnts << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if(_hit_pnts >= 0 && _enrgy_pnts)
	{
		_hit_pnts += amount;
		_enrgy_pnts -= 1;
		std::cout << "ClapTrap " << _name << " repaired " << amount << " Hit points left = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
	}
	else if (_hit_pnts <= 0)
		std::cout << "ClapTrap No Hit points left for repaire. Hit points = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
	else
		std::cout << "ClapTrap No Energy points left for repaire. Hit points = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
}
