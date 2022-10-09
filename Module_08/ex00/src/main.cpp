/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 15:38:14 by andy              #+#    #+#             */
/*   Updated: 2022/07/07 17:31:39 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

void test_vector()
{
    std::vector<int> vctr;
    vctr.push_back(24);
    vctr.push_back(4);
    vctr.push_back(1983);

    for (size_t i = 0; i < vctr.size(); i++)
    {
        std::cout << vctr[i] << std::endl;
    }
    std::cout << "RESULT: " << *(easyfind(vctr, 4)) << std::endl;

    try
    {
        std::cout << "RESULT: " << *(easyfind(vctr, 5)) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

void test_list()
{
    std::list<int> lst;
    lst.push_front(2);
    lst.push_back(4);
    lst.push_back(2016);

    for (std::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
    {
        std::cout << *i << std::endl;
    }
    std::cout << "RESULT: " << *(easyfind(lst, 2016)) << std::endl;

    try
    {
        std::cout << "RESULT: " << *(easyfind(lst, 5)) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}

int main()
{
    test_vector();
    std::cout << "-------------" << std::endl;
    test_list();
    return 0;
}