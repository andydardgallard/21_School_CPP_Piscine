/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 06:41:00 by andy              #+#    #+#             */
/*   Updated: 2022/06/11 00:18:28 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
    _name = "ScavTrap Default name";
    _hit_pnts = 100;
    _enrgy_pnts = 50;
    _attck_dmg = 20;
    std::cout << "ScavTrap Default constructor is called for: " << _name << ": Hit points: ";
	std::cout << _hit_pnts << " Energy points: " << _enrgy_pnts;
	std::cout << " Attack demage: " << _attck_dmg << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destructor is called for: " << _name << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap & other)
{
    *this = other;
    std::cout << "ScavTrap Copy constructor is called" << std::endl;
}

ScavTrap & ScavTrap::operator=(const ScavTrap & other)
{
    std::cout << "ScavTrap Assignment operator is called" << std::endl;
    if (this == &other)
        return *this;
    this->_name = other._name;
    this->_hit_pnts = other._hit_pnts;
    this->_enrgy_pnts = other._enrgy_pnts;
    this->_attck_dmg = other._attck_dmg;
    return *this;
}

ScavTrap::ScavTrap(std::string name)
{
    _name = name;
    _hit_pnts = 100;
    _enrgy_pnts = 50;
    _attck_dmg = 20;
    std::cout << "ScavTrap Init constructor is called for: " << _name << ": Hit points: ";
	std::cout << _hit_pnts << " Energy points: " << _enrgy_pnts;
	std::cout << " Attack demage: " << _attck_dmg << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
    if(_hit_pnts >= 0 && _enrgy_pnts)
	{
		_enrgy_pnts -= 1;
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attck_dmg << " points of damage!" << std::endl;
	}
	else if (_hit_pnts <= 0)
		std::cout << "ScavTrap No Hit points left for attack. Hit points = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
	else
		std::cout << "ScavTrap No Energy points left for attack. Hit points = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
}

void ScavTrap::guardGate()
{
    if(_hit_pnts >= 0 && _enrgy_pnts)
        std::cout << "ScavTrap " << _name << " is now in Gate keeper mode." << std::endl;
    else
        std::cout << "ScavTrap " << _name << " is NOT in Gate keeper mode. Hit points = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
}

