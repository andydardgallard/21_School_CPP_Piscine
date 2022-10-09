/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 19:44:08 by andy              #+#    #+#             */
/*   Updated: 2022/06/20 22:50:28 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() 
    :Form("ShrubberyForm", "Target", 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
    :Form("ShrubberyForm", other.getTarget(), 145, 137) {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &)
{
    return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    :Form("ShrubberyForm", target, 145, 137) {}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
    Form::execute(executor);
    if (executor.getGrade() < this->getGrdToExct())
    {
        std::ofstream out;
        out.open(this->getTarget() + "_shrubbery");
        if (!out)
            throw std::exception().what();
        out << "     *     " << std::endl
            << "    **o    " << std::endl
            << "   *o**o   " << std::endl
            << "  o***o**  " << std::endl
            << " ****o**** " << std::endl
            << "     |     " << std::endl;
        out.close();
    }
}
