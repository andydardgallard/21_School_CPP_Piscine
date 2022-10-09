/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:15:17 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 16:23:59 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default Constructor is called" << std::endl;
    this->type = "Cat";
}

Cat::~Cat()
{
    std::cout << "Cat Destructor is called" << std::endl;
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
    return *this;
}

void Cat::makeSound() const
{
    std::cout << "MUR MUR MUR" << std::endl;
}
