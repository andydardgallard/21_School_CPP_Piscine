/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 22:40:12 by andy              #+#    #+#             */
/*   Updated: 2022/06/30 22:56:52 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Iter.hpp"
#include <iostream>

template <class T>
void print(T const &a)
{
	std::cout << a << std::endl;
}

int main()
{
    int			arr0[5] = {0, 1, 2, 3, 4};
    float		arr1[5] = {0.1, 1.1, 2.2, 3.3, 4.4};
	char		arr2[5] = {'q', 'w', 'e', 'r', 't'};
	std::string	arr3[5] = {"qw", "er", "ty", "ui", "op"};

	::iter(arr0, 3, &print);
	std::cout << std::endl;
	::iter(arr1, 4, &print);
	std::cout << std::endl;
    ::iter(arr2, 5, &print);
	std::cout << std::endl;
	::iter(arr3, 6, &print);
	
    return 0;
}