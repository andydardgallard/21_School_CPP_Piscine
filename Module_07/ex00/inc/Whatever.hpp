/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:58:56 by andy              #+#    #+#             */
/*   Updated: 2022/06/30 22:14:31 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template <class T>
void swap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <class T>
T& min(T& a, T& b)
{
    if (a < b)
        return a;
    return b;
}

template <class T>
T& max(T& a, T& b)
{
    if (a > b)
        return a;
    return b;
}

#endif