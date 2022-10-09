/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:27:44 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 16:23:36 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default Constructor is called" << std::endl;
    this->type = "Dog";
}

Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
}

Dog::Dog(const Dog& other)
{
    std::cout << "Dog Copy Constructor is called" << std::endl;
    *this = other;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog Assignment operator is called" << std::endl;
    if (this == &other)
        return *this;
    this->type = other.type;
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "GAV GAV GAV" << std::endl;
}
