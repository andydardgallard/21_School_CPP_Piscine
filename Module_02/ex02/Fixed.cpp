/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:11:47 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/04 23:03:00 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
    this->fixPntNum = 0;
}

Fixed::Fixed(int const fixPntNum)
{
	this->fixPntNum = (fixPntNum << Fixed::bits);
}

Fixed::Fixed(float const fixPntNum)
{
	this->fixPntNum = roundf(fixPntNum * (1 << Fixed::bits));
}

Fixed::Fixed(Fixed const &other)
{
	this->fixPntNum = other.getRawBits();
}

Fixed & Fixed::operator = (Fixed const &other)
{
	this->fixPntNum = other.getRawBits();
	return(*this);
}

Fixed::~Fixed(){}

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

bool Fixed::operator == (const Fixed &other) const
{
	return(this->fixPntNum == other.fixPntNum);
}

bool Fixed::operator != (const Fixed &other) const
{
	return(this->fixPntNum != other.fixPntNum);
}

bool Fixed::operator < (const Fixed &other) const
{
	return(this->fixPntNum < other.fixPntNum);
}

bool Fixed::operator > (const Fixed &other) const
{
	return(this->fixPntNum > other.fixPntNum);
}

bool Fixed::operator <= (const Fixed &other) const
{
	return(this->fixPntNum <= other.fixPntNum);
}

bool Fixed::operator >= (const Fixed &other) const
{
	return(this->fixPntNum >= other.fixPntNum);
}

Fixed Fixed::operator + (const Fixed &other)
{
	Fixed temp;
	temp.fixPntNum = this->fixPntNum + other.fixPntNum;
	return (temp);	
}

Fixed Fixed::operator - (const Fixed &other)
{
	Fixed temp;
	temp.fixPntNum = this->fixPntNum - other.fixPntNum;
	return (temp);	
}

Fixed Fixed::operator * (const Fixed &other)
{
	Fixed temp;
	temp.fixPntNum = (this->fixPntNum * other.fixPntNum) / (1 << Fixed::bits);
	
	return (temp);	
}

Fixed Fixed::operator / (const Fixed &other)
{
	Fixed temp;
	temp.fixPntNum = (this->fixPntNum * (1 << Fixed::bits)) / other.fixPntNum;
	return (temp);	
}

Fixed Fixed::operator ++()
{
	this->fixPntNum += 1;
	return *this;
}

Fixed Fixed::operator --()
{
	this->fixPntNum -= 1;
	return *this;
}

Fixed Fixed::operator ++(int)
{
	Fixed temp(*this);
	this->fixPntNum += 1;
	return temp;
}

Fixed Fixed::operator --(int)
{
	Fixed temp(*this);
	this->fixPntNum -= 1;
	return temp;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a > b)
		return (b);
	return (a);
}

Fixed const &min(Fixed const &a, Fixed const &b)
{
	return (Fixed::min(a, b));
}

Fixed &min(Fixed &a, Fixed &b)
{
	return (Fixed::min(a, b));
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

Fixed const &max(Fixed const &a, Fixed const &b)
{
	return (Fixed::max(a, b));
}

Fixed &max(Fixed &a, Fixed &b)
{
	return (Fixed::max(a, b));
}
