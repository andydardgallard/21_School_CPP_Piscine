/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:18:46 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 21:49:36 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization() {}

Serialization::~Serialization() {}

Serialization::Serialization(const Serialization& other) {*this = other;}

Serialization& Serialization::operator=(const Serialization& other)
{
    if (this == &other)
        return *this;
    return *this;
}

uintptr_t   Serialization::serialize(Data* ptr)
{
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*       Serialization::deserialize(uintptr_t raw)
{
    return(reinterpret_cast<Data*>(raw));
}
