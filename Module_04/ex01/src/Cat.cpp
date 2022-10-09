/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:15:17 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 20:40:47 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default Constructor is called" << std::endl;
    this->type = "Cat";
    this->brains = new Brain();
    if (this->brains == NULL)
    {
        std::cerr << "Allocation for " << this->type << " is failed" << std::endl;
        delete this->brains;
        exit(1);
    }
}

Cat::~Cat()
{
    std::cout << "Cat Destructor is called" << std::endl;
    delete this->brains;
}

Cat::Cat(const Cat &other)
{
    std::cout << "Cat Copy Constructor is called" << std::endl;
    *this = other;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout << "Cat Assignment operator is called" << std::endl;
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

void Cat::makeSound() const
{
    std::cout << "MUR MUR MUR" << std::endl;
}

std::string Cat::getIdea(int count) const
{
    return this->brains->getIdea(count);
}

void Cat::setIdea(std::string idea, int count) const
{
    this->brains->setIdea(idea, count);
}
