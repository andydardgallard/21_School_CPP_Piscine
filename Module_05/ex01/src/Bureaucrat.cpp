/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:36:17 by andy              #+#    #+#             */
/*   Updated: 2022/06/20 12:10:15 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default"), grade(150) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other): name(other.name)
{
    *this = other;
}

Bureaucrat & Bureaucrat::operator=(const Bureaucrat &other)
{
    if (this == &other)
        return *this;
    this->grade = other.grade;
    return *this;
}

Bureaucrat::Bureaucrat(const std::string name, int grade): name(name)
{
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
    grade--;
    if (grade < 1)
        throw GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    grade++;
    if (grade > 150)
        throw GradeTooLowException();
}

std::string Bureaucrat::getName() const {return name;}

int Bureaucrat::getGrade() const {return grade;}

void Bureaucrat::signForm(Form &frm)
{
    if (frm.getIsSign() == true)
        std::cout << name << " couldn’t sign " << frm.getName() << " because Form is already signed." << std::endl;
    else if (grade <= frm.getGrdToSgn())
    {
        frm.beSigned(*this);
        std::cout << name << " signed " << frm.getName() << std::endl;
    }
    else
        std::cout << name << " couldn’t sign " << frm.getName() << " because grade is too low." << std::endl;
        
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Grade is too high for:");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Grade is too low for:");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &cb)
{
    out << cb.getName() << " bureaucrat grade " << cb.getGrade() << std::endl;
    return out;
}
