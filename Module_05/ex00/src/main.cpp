/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:39:49 by andy              #+#    #+#             */
/*   Updated: 2022/06/19 01:07:26 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test(std::string name, int grade)
{
    try
    {
        Bureaucrat a(name, grade);
        std::cout << a.getName() << " " << a.getGrade() << std::endl;
        a.decrementGrade();
        std::cout << a.getName() << " " << a.getGrade() << std::endl;
        a.incrementGrade();
        a.incrementGrade();
        std::cout << a.getName() << " " << a.getGrade() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " " << name << std::endl;;
    }
    
}

int main()
{
    test("Andy", 150);
    std::cout << "-------------" << std::endl;
    test("dgallard", 1);
    std::cout << "-------------" << std::endl;
    test("adar", 100);
    std::cout << "-------------" << std::endl;
    test("L", 200);
    std::cout << "-------------" << std::endl;
    test("H", 0);
    
    return 0;
}
