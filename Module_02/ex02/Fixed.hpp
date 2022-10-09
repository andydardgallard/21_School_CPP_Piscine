/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:11:54 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/04 23:02:18 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
	Fixed();
	Fixed(int const fixPntNum);
	Fixed(float const fixPntNum);
	Fixed(const Fixed &other);
	~Fixed();
	Fixed & operator = (const Fixed &other);
	bool operator == (const Fixed &other) const;
	bool operator != (const Fixed &other) const;
	bool operator < (const Fixed &other) const;
	bool operator > (const Fixed &other) const;
	bool operator <= (const Fixed &other) const;
	bool operator >= (const Fixed &other) const;
	Fixed operator + (const Fixed &other);
	Fixed operator - (const Fixed &other);
	Fixed operator * (const Fixed &other);
	Fixed operator / (const Fixed &other);
	Fixed operator ++();
	Fixed operator --();
	Fixed operator ++(int);
	Fixed operator --(int value);
	
	static Fixed &min(Fixed &a, Fixed &b);
	static Fixed &max(Fixed &a, Fixed &b);
	static Fixed const &min(Fixed const &a, Fixed const &b);
	static Fixed const &max(Fixed const &a, Fixed const &b);
	

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	private:
	int					fixPntNum;
	static const int	bits = 8;
};

std::ostream & operator << (std::ostream &out, const Fixed &fixPntNum);
// Fixed const &min(Fixed const &a, Fixed const &b);
// Fixed const &max(Fixed const &a, Fixed const &b);
// Fixed &min(Fixed &a, Fixed &b);
// Fixed &max(Fixed &a, Fixed &b);
#endif