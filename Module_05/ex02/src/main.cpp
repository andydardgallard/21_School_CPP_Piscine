/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:39:49 by andy              #+#    #+#             */
/*   Updated: 2022/06/21 10:24:55 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void test(std::string brcrtName, int grade, std::string target)
{
    try
    {
        std::cout << "-------------" << std::endl;
        Bureaucrat  brcrt(brcrtName, grade);
        std::cout << brcrt;
        
        ShrubberyCreationForm a(target);
        std::cout << a;
        a.beSigned(brcrt);
        std::cout << a;
        a.execute(brcrt);
        std::cout << "+++" << std::endl;
        
        RobotomyRequestForm b(target);
        std::cout << b;
        b.beSigned(brcrt);
        std::cout << b;
        b.execute(brcrt);
        std::cout << "+++" << std::endl;
        
        PresidentialPardonForm c(target);
        std::cout << c;
        c.beSigned(brcrt);
        std::cout << c;
        c.execute(brcrt);
        std::cout << "+++" << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " " << brcrtName << " Grade: " << grade << std::endl;
    }
}

int main()
{
    test("Andy", 150, "Other");
    test("Andy", 140, "Other");
    test("Andy", 130, "Other");
    
    test("Andy", 150, "Other");
    test("Andy", 70, "Other");
    test("Andy", 40, "Other");

    test("Andy", 150, "Other");
    test("Andy", 20, "Other");
    test("Andy", 1, "Other");

    test("Andy", 200, "Other");
    test("Andy", 0, "Other");
    test("Andy", -40, "Other");
    
    return 0;
}
