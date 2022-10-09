/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:11:26 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/04 20:11:28 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixPntNum = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	this->fixPntNum = other.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}

Fixed & Fixed::operator = (Fixed const &other)
{
	this->fixPntNum = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return(*this);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return(this->fixPntNum);
}

void Fixed::setRawBits(int const raw)
{
	this->fixPntNum = raw;
}
