/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:11:54 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/04 20:11:56 by dgallard         ###   ########.fr       */
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

	int					getRawBits(void) const;
	void				setRawBits(int const raw);
	float				toFloat(void) const;
	int					toInt(void) const;

	private:
	int					fixPntNum;
	static const int	bits = 8;
};

std::ostream & operator << (std::ostream &out, const Fixed &fixPntNum);

#endif