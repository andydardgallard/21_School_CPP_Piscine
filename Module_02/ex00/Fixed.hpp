/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgallard <dgallard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 20:11:34 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/04 20:11:36 by dgallard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
	Fixed();
	Fixed(const Fixed &other);
	~Fixed();
	Fixed & operator = (const Fixed &other);

	int					getRawBits(void) const;
	void				setRawBits(int const raw);

	private:
	int					fixPntNum;
	static const int	bits = 8;
};

#endif