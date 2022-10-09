/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:00:46 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 17:11:30 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal Default Constructor is called" << std::endl;
	this->type = "Wrong_Animal";
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal Destructor is called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
    *this = other;
	std::cout << "WrongAnimal Copy Constructor is called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other)
{
	std::cout << "WrongAnimal Assignment operator is called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makeSound() method is called" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return type;
}
