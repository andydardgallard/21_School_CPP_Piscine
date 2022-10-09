/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:35:30 by andy              #+#    #+#             */
/*   Updated: 2022/06/21 14:14:06 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &) {}

Intern &Intern::operator=(const Intern &) {return *this;}

Form *Intern::MakeForm(std::string formName, std::string formTarget)
{
    std::string formNames[3] =
    {
        "ShrubberyForm",
        "RobotomyForm",
        "PresidentialForm"
    };
    int i = 0;
    for (; i < 3 && formName != formNames[i]; i++){}
    switch (i)
    {
    case 0:
        std::cout << "Intern creates " << formNames[0] << std::endl;
        return (new ShrubberyCreationForm(formTarget));
    case 1:
        std::cout << "Intern creates " << formNames[1] << std::endl;
        return (new RobotomyRequestForm(formTarget));
    case 2:
        std::cout << "Intern creates " << formNames[2] << std::endl;
        return (new PresidentialPardonForm(formTarget));
    default:
        throw FormDoesNotExistException();
    }
    return nullptr;
}

const char*Intern::FormDoesNotExistException::what() const throw()
{
    return ("Form does not exist: ");
}
