/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 17:32:47 by andy              #+#    #+#             */
/*   Updated: 2022/07/08 12:33:47 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void test(unsigned int N, unsigned int rng)
{
    Span mySpan(N);
    std::cout << "Add first item " << std::endl;
    try 
    {
        mySpan.addNumber(10);
        std::cout << mySpan[0] << std::endl;  
    }
    catch(const std::exception& e) {std::cerr << e.what() << '\n';}
    std::cout << std::endl;
    
    std::cout << "Add second item " << std::endl;
    try 
    {
        mySpan.addNumber(999); 
        std::cout << mySpan[1] << std::endl;
    }
    catch(const std::exception& e) {std::cerr << e.what() << '\n';}
    std::cout << std::endl;
    
    std::cout << "Check operator [] " << std::endl;
    try {std::cout << mySpan[2] << std::endl;}
    catch(const std::exception& e) {std::cerr << e.what() << '\n';}
    std::cout << std::endl;

    std::cout << "Add range of items " << std::endl;
    try {mySpan.addRangeNumbers(rng);}
    catch(const std::exception& e) {std::cerr << e.what() << '\n';}
    for (size_t i = 0; i < mySpan.getSize(); i++)
        std::cout << mySpan[i] << std::endl;
    std::cout << std::endl;
    
    std::cout << "Shortest span " << std::endl;
    try {std::cout << mySpan.shortestSpan() << std::endl;}
    catch(const std::exception& e) {std::cerr << e.what() << '\n';}
    std::cout << std::endl;

    std::cout << "Longest span " << std::endl;
    try {std::cout << mySpan.longestSpan() << std::endl;}
    catch(const std::exception& e) {std::cerr << e.what() << '\n';}
    std::cout << std::endl;
}

int main()
{
    test(10, 4);
    std::cout << "############" << std::endl;
    std::cout << std::endl;
    test(0, 4);
    std::cout << "############" << std::endl;
    std::cout << std::endl;
    test(1, 5);
    std::cout << "############" << std::endl;
    std::cout << std::endl;
    test(10000000, 1000000);
    std::cout << "############" << std::endl;
    std::cout << std::endl;

    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
    
    return 0;
}