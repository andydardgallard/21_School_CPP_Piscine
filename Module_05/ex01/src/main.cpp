/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:39:49 by andy              #+#    #+#             */
/*   Updated: 2022/06/20 12:22:06 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

void test(std::string formName, int gradeToSign, int gradeToExct, std::string brcrtName, int grade)
{
    try
    {
        std::cout << "-------------" << std::endl;
        Bureaucrat  brcrt(brcrtName, grade);
        Form        frm(formName, gradeToSign, gradeToExct);
        std::cout << brcrt;
        std::cout << frm;
        brcrt.signForm(frm);
        frm.beSigned(brcrt);
        std::cout << frm;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << " " << brcrtName << " " << formName << std::endl;
    }
}

int main()
{
    test("F_Andy", 150, 150, "Andy", 150);
    test("F_Andy", 100, 100, "Andy", 150);
    test("F_Andy", 0, 100, "Andy", 150);
    test("F_Andy", 100, -1, "Andy", 150);
    test("F_Andy", 100, 100, "Andy", 15);
    test("F_Andy", 100, 1, "Andy", 150);
    
    return 0;
}
