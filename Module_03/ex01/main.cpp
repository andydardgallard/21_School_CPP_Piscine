/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:15:42 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/11 00:17:47 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main()
{
    ClapTrap one("_Andy_");
    for (int i = 0; i < 10; ++i)
    {  
        std::cout << i << " ---------" << std::endl;
		one.attack("_ENEMY_");
        one.takeDamage(3);
        one.beRepaired(2);
    }
    std::cout << std::endl << " ########################" << std::endl << std::endl;
    ScavTrap two("_dgallard_");
    for (int i = 0; i < 10; ++i)
    {  
        std::cout << i << " ---------" << std::endl;
		two.attack("_EVIL_");
        two.takeDamage(30);
        two.beRepaired(10);
        two.guardGate();
    }
    return 0;
}