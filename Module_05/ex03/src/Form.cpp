/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:35:35 by andy              #+#    #+#             */
/*   Updated: 2022/06/21 13:36:21 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("Name"), target("Target"), grdToSgn(150), grdToExct(150)
{
    isSigned = false;
}

Form::~Form() {}

Form::Form(const Form &other):
    name(other.name), target(other.target), grdToSgn(other.grdToSgn), grdToExct(other.grdToExct)
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::Form(const std::string name, const std::string target, const int grdToSgn, const int grdToExct):
    name(name), target(target), grdToSgn(grdToSgn), grdToExct(grdToExct)
{
    if (grdToSgn < 1 || grdToExct < 1)
        throw GradeTooHighException();
    else if (grdToSgn > 150 || grdToSgn > 150)
        throw GradeTooLowException();
}

std::string Form::getName() const {return name;}

std::string Form::getTarget() const {return target;}

bool Form::getIsSign() const {return isSigned;}

int Form::getGrdToSgn() const {return grdToSgn;}

int Form::getGrdToExct() const {return grdToExct;}

void Form::beSigned(Bureaucrat &brcrt)
{
    if (brcrt.getGrade() <= grdToSgn)
        isSigned = true;
    else
        throw GradeTooLowException();
    std::cout << brcrt.getName() << " signed " << this->getName() << std::endl;
}

void Form::execute(const Bureaucrat &executor) const
{
    if (this->isSigned == 0)
        throw FormNotSignedException();
    if (executor.getGrade() > this->getGrdToExct())
        throw GradeTooLowException();
    std::cout << executor.getName() << " executed " << this->getName() << std::endl;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high for Form:");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low for Form:");
}

const char*Form::FormNotSignedException::what() const throw()
{
    return ("Form isn't signed:");
}

std::ostream &operator<<(std::ostream &out, const Form &clF)
{
    out << "Form: " << clF.getName() << ", Grade to Sign: " << clF.getGrdToSgn()
        << ", Grade to Execute: " << clF.getGrdToExct() << ", status Signed: "
        << clF.getIsSign() << ", Target: " << clF.getTarget() << std::endl;
    return out;
}
