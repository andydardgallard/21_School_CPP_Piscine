/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:17:44 by andy              #+#    #+#             */
/*   Updated: 2022/06/30 22:39:39 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template <class T>
void iter(T* pArr, unsigned int len,  void (*f)(T const &a))
{
    for (unsigned int i = 0; i < len; i++)
        (*f)(pArr[i]);
}

#endif