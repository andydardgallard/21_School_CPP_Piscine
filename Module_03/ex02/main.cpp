/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:15:42 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/11 10:26:33 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

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
    std::cout << std::endl << " ########################" << std::endl << std::endl;
    FragTrap three("_adar_");
    for (int i = 0; i < 10; ++i)
    {  
        std::cout << i << " ---------" << std::endl;
		three.attack("_HIMSELF_");
        three.takeDamage(40);
        three.beRepaired(15);
        three.highFivesGuys();
    }
    return 0;
}