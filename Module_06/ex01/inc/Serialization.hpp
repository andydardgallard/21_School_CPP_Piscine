/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:17:40 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 22:02:18 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>

typedef struct	Data
{
    std::string		name;
	float			score;
	char			rank;
}               Data;

class Serialization
{
public:
    Serialization();
    ~Serialization();
    Serialization(const Serialization& other);
    Serialization&	operator=(const Serialization& other);

	uintptr_t		serialize(Data* ptr);
	Data*			deserialize(uintptr_t raw);
};

#endif