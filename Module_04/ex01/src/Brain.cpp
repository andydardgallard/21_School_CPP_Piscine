/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:59:32 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 20:25:43 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor is called" << std::endl;
    for (size_t i = 0; i < 100; i++)
    {
        std::string str = "idea_" + std::to_string(i);
        this->ideas[i] = str;
    }
}

Brain::~Brain()
{
    std::cout << "Brain Destructor is called" << std::endl;
}

Brain::Brain(const Brain &other)
{
    *this = other;
    std::cout << "Brain Copy Constructor is called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain Assignment operator is called" << std::endl;
    if (this == &other)
        return *this;
    for (size_t i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
    return *this;
}

std::string Brain::getIdea(int count)
{
    return this->ideas[count];
}

void Brain::setIdea(std::string idea, int count)
{
    this->ideas[count] = idea;
}
