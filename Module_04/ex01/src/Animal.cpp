/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 07:28:43 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 18:24:04 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal Default Constructor is called" << std::endl;
	this->type = "Animal";
}

Animal::~Animal()
{
    std::cout << "Animal Destructor is called" << std::endl;
}

Animal::Animal(const Animal& other)
{
    *this = other;
	std::cout << "Animal Copy Constructor is called" << std::endl;
}

Animal& Animal::operator=(const Animal& other)
{
	std::cout << "Animal Assignment operator is called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Animal makeSound() method is called" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}
