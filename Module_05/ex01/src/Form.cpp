/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:35:35 by andy              #+#    #+#             */
/*   Updated: 2022/06/20 11:49:09 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("Default"), grdToSgn(150), grdToExct(150)
{
    isSigned = false;
}

Form::~Form() {}

Form::Form(const Form &other):
    name(other.name), grdToSgn(other.grdToSgn), grdToExct(other.grdToExct)
{
    *this = other;
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
        this->isSigned = other.isSigned;
    return *this;
}

Form::Form(const std::string name, const int grdToSgn, const int grdToExct):
    name(name), grdToSgn(grdToSgn), grdToExct(grdToExct)
{
    if (grdToSgn < 1 || grdToExct < 1)
        throw GradeTooHighException();
    else if (grdToSgn > 150 || grdToSgn > 150)
        throw GradeTooLowException();
}

std::string Form::getName() const {return name;}

bool Form::getIsSign() const {return isSigned;}

int Form::getGrdToSgn() const {return grdToSgn;}

int Form::getGrdToExct() const {return grdToExct;}

void Form::beSigned(Bureaucrat &brcrt)
{
    if (brcrt.getGrade() <= grdToSgn)
        isSigned = true;
    else
        throw GradeTooLowException();
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Grade is too high for Form:");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Grade is too low for Form:");
}

std::ostream &operator<<(std::ostream &out, const Form &clF)
{
    out << "Form: " << clF.getName() << ", Grade to Sign: " << clF.getGrdToSgn()
        << ", Grade to Execute: " << clF.getGrdToExct() << ", status Signed: "
        << clF.getIsSign() << std::endl;
    return out;
}
