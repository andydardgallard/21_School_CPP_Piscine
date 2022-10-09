/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 10:00:51 by andy              #+#    #+#             */
/*   Updated: 2022/06/11 10:23:23 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap()
{
    _name = "FragTrap Default name";
    _hit_pnts = 100;
    _enrgy_pnts = 100;
    _attck_dmg = 30;
    std::cout << "FragTrap Default constructor is called for: " << _name << ": Hit points: ";
	std::cout << _hit_pnts << " Energy points: " << _enrgy_pnts;
	std::cout << " Attack demage: " << _attck_dmg << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destructor is called for: " << _name << std::endl;
}

FragTrap::FragTrap(const FragTrap& other)
{
    *this = other;
    std::cout << "FragTrap Copy constructor is called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap & other)
{
    std::cout << "FragTrap Assignment operator is called" << std::endl;
    if (this == &other)
        return *this;
    this->_name = other._name;
    this->_hit_pnts = other._hit_pnts;
    this->_enrgy_pnts = other._enrgy_pnts;
    this->_attck_dmg = other._attck_dmg;
    return *this;
}

FragTrap::FragTrap(std::string name)
{
    _name = name;
     _hit_pnts = 100;
    _enrgy_pnts = 100;
    _attck_dmg = 30;
    std::cout << "FragTrap Init constructor is called for: " << _name << ": Hit points: ";
	std::cout << _hit_pnts << " Energy points: " << _enrgy_pnts;
	std::cout << " Attack demage: " << _attck_dmg << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    if(_hit_pnts >= 0 && _enrgy_pnts)
        std::cout << "FragTrap " << _name << " is giving high five." << std::endl;
    else
        std::cout << "FragTrap " << _name << " is NOT giving high five. Hit points = " << _hit_pnts << ", Energy points = " << _enrgy_pnts << std::endl;
}
