/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:39:49 by andy              #+#    #+#             */
/*   Updated: 2022/06/21 14:18:55 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <chrono>
#include <thread>

int main()
{
    Intern a;
    std::string form_1 = "ShrubberyForm";
    std::string form_2 = "RobotomyForm";
    std::string form_3 = "PresidentialForm";
    std::string form_0 = "qwerty";
    
    try
    {
        std::cout << "-------------" << std::endl;
        Form *formToCrt_1 = a.MakeForm(form_1, "smth");
        std::cout << *formToCrt_1;

        std::cout << "-------------" << std::endl;
        Form *formToCrt_2 = a.MakeForm(form_2, "smth");
        std::cout << *formToCrt_2;

        std::cout << "-------------" << std::endl;
        Form *formToCrt_3 = a.MakeForm(form_3, "smth");
        std::cout << *formToCrt_3;

        std::cout << "-------------" << std::endl;
        Form *formToCrt_0 = a.MakeForm(form_0, "smth");
        std::cout << *formToCrt_0;
        
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << form_0 << std::endl;
    }
    
    // std::this_thread::sleep_for(std::chrono::seconds(100));
    return 0;
}
