/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 06:38:08 by andy              #+#    #+#             */
/*   Updated: 2022/06/11 00:11:56 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
    ScavTrap();
    ~ScavTrap();
	ScavTrap(const ScavTrap & other);
    ScavTrap &	operator=(const ScavTrap & other);

    ScavTrap(std::string name);
    void attack(const std::string& target);
    void guardGate();
};

#endif