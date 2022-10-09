/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 09:50:00 by andy              #+#    #+#             */
/*   Updated: 2022/06/21 10:09:00 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
    : Form("PresidentialForm", "Default", 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)
    : Form("PresidentialForm", other.getTarget(), 25, 5) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &)
{
    return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target)
    : Form("PresidentialForm", target, 25, 5) {}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
    Form::execute(executor);
    if (executor.getGrade() < this->getGrdToExct())
        std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
