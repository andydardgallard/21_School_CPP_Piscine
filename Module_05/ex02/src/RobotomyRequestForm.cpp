/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 23:06:14 by andy              #+#    #+#             */
/*   Updated: 2022/06/21 10:05:46 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
    :Form("RobotomyForm", "Default", 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)
    :Form("RobotomyForm", other.getTarget(), 72, 45) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &)
{
    return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target)
    :Form("RobotomyForm", target, 72, 45) {}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
    Form::execute(executor);
    if (executor.getGrade() < this->getGrdToExct())
    {
        std::srand(time(0));
        if (std::rand() % 2)
            std::cout << "Robotomy makes some drilling noises" << std::endl;
        else
            std::cout << "Robotomy failed" << std::endl;
    }
}
