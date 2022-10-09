/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 16:14:55 by andy              #+#    #+#             */
/*   Updated: 2022/07/07 16:33:52 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <algorithm>

class NotFoundException : public std::exception
{
    const char *what() const throw();
};

template <typename T>
typename T::iterator easyfind(T& container, const int itm)
{
    typename T::iterator it = std::find(container.begin(), container.end(), itm);
    if (it == container.end())
        throw NotFoundException();
    return it;    
}

#endif