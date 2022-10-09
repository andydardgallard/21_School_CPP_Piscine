/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 13:27:44 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 20:41:01 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default Constructor is called" << std::endl;
    this->type = "Dog";
    this->brains = new Brain();
    if (this->brains == NULL)
    {
        std::cerr << "Allocation for " << this->type << " is failed" << std::endl;
        delete this->brains;
        exit(1);
    }
}

Dog::~Dog()
{
    std::cout << "Dog Destructor is called" << std::endl;
    delete this->brains;
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
    this->brains = new Brain();
    if (this->brains == NULL)
    {
        std::cerr << "Allocation for " << this->type << " is failed" << std::endl;
        delete this->brains;
        exit(1);
    }
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "GAV GAV GAV" << std::endl;
}

std::string Dog::getIdea(int count) const
{
    return this->brains->getIdea(count);
}

void Dog::setIdea(std::string idea, int count) const
{
    this->brains->setIdea(idea, count);
}
