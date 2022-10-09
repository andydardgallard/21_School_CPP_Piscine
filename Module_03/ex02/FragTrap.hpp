/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 09:55:52 by andy              #+#    #+#             */
/*   Updated: 2022/06/11 10:18:34 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
public:
    FragTrap();
    ~FragTrap();
    FragTrap(const FragTrap& other);
    FragTrap& operator=(const FragTrap& other);

    FragTrap(std::string name);
    void highFivesGuys(void);
};

#endif