/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 21:10:02 by andy              #+#    #+#             */
/*   Updated: 2022/07/09 23:47:18 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <list>

void test_stack()
{
    MutantStack<int> ms;
    MutantStack<int> ms_2 = ms;
    MutantStack<int> ms_3(ms);
    ms.push(0);
    ms.push(1);
    ms.push(2);
    
    std::cout << "iterator" << std::endl;
    MutantStack<int>::iterator it = ms.begin();
    MutantStack<int>::iterator ite = ms.end();
    ++it;
    --it;
    *it = 999;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << "const_iterator" << std::endl;
    MutantStack<int>::const_iterator cit = ms.cbegin();
    MutantStack<int>::const_iterator cite = ms.cend();
    ++cit;
    --cit;
    // *cit = 999;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    std::cout << std::endl;

    std::cout << "reverse_iterator" << std::endl;
    MutantStack<int>::reverse_iterator rit = ms.rbegin();
    MutantStack<int>::reverse_iterator rite = ms.rend();
    ++rit;
    --rit;
    *rit = 888;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    std::cout << std::endl;

    std::cout << "const_reverse_iterator" << std::endl;
    MutantStack<int>::const_reverse_iterator crit = ms.rbegin();
    MutantStack<int>::const_reverse_iterator crite = ms.rend();
    ++crit;
    --crit;
    // *crit = 888;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        ++crit;
    }
    std::cout << std::endl;
}

void test_list()
{
    std::list<int> ms;
    ms.push_back(0);
    ms.push_back(1);
    ms.push_back(2);
    
    std::cout << "iterator" << std::endl;
    std::list<int>::iterator it = ms.begin();
    std::list<int>::iterator ite = ms.end();
    ++it;
    --it;
    *it = 999;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << "const_iterator" << std::endl;
    std::list<int>::const_iterator cit = ms.cbegin();
    std::list<int>::const_iterator cite = ms.cend();
    ++cit;
    --cit;
    // *cit = 999;
    while (cit != cite)
    {
        std::cout << *cit << std::endl;
        ++cit;
    }
    std::cout << std::endl;

    std::cout << "reverse_iterator" << std::endl;
    std::list<int>::reverse_iterator rit = ms.rbegin();
    std::list<int>::reverse_iterator rite = ms.rend();
    ++rit;
    --rit;
    *rit = 888;
    while (rit != rite)
    {
        std::cout << *rit << std::endl;
        ++rit;
    }
    std::cout << std::endl;

    std::cout << "const_reverse_iterator" << std::endl;
    std::list<int>::const_reverse_iterator crit = ms.rbegin();
    std::list<int>::const_reverse_iterator crite = ms.rend();
    ++crit;
    --crit;
    // *crit = 888;
    while (crit != crite)
    {
        std::cout << *crit << std::endl;
        ++crit;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "Stack" << std::endl;
    test_stack();
    std::cout << "#############" << std::endl;
    std::cout << "List" << std::endl;
    test_list();
    
    return 0;
}