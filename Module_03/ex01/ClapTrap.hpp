/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 12:44:18 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/11 00:11:09 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap(const ClapTrap &other);
		~ClapTrap();
		ClapTrap & operator = (const ClapTrap &other);

		ClapTrap(const std::string& name);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string 			_name;
		int			         	_hit_pnts;
		unsigned int			_enrgy_pnts;
		unsigned int			_attck_dmg;
};

#endif