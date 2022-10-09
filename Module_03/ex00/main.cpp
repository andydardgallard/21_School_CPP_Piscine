/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 14:15:42 by dgallard          #+#    #+#             */
/*   Updated: 2022/06/09 06:06:52 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

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
    return 0;
}