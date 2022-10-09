/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 18:53:36 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 20:24:11 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
    std::string ideas[100];
    
public:
    Brain();
    ~Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    
    std::string getIdea(int count);
    void setIdea(std::string idea, int count);
};

#endif