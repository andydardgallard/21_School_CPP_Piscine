/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 11:02:06 by andy              #+#    #+#             */
/*   Updated: 2022/06/21 14:22:24 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern
{
public:
    Intern();
    ~Intern();
    Intern(const Intern &);
    Intern &operator=(const Intern &);

    Form *MakeForm(std::string formName, std::string formTarget);
    class FormDoesNotExistException : public std::exception
    {
        const char *what() const throw();
    };
};

#endif
