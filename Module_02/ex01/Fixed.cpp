/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:11:47 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/04 20:11:49 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixPntNum = 0;
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int const fixPntNum)
{
	this->fixPntNum = (fixPntNum << Fixed::bits);
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const fixPntNum)
{
	this->fixPntNum = roundf(fixPntNum * (1 << Fixed::bits));
	std::cout << "Float constructor called" << std::endl;
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
	return(this->fixPntNum);
}

void Fixed::setRawBits(int const raw)
{
	this->fixPntNum = raw;
}

float Fixed::toFloat(void) const
{
	return((float)this->fixPntNum / (float)(1 << Fixed::bits));
}

int Fixed::toInt(void) const
{
	return(this->fixPntNum >> Fixed::bits);
}

std::ostream & operator <<(std::ostream &out, Fixed const &fixPntNum)
{
	out << fixPntNum.toFloat();
	return(out);
}
