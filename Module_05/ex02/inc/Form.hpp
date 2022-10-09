/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:12:43 by andy              #+#    #+#             */
/*   Updated: 2022/06/20 19:30:09 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    public:
	Form();
	~Form();
	Form(const Form &other);
	Form &operator=(const Form &other);

	Form(std::string name, std::string target, const int grdToSgn, const int grdToExct);
	std::string 	getName() const;
	std::string 	getTarget() const;
	bool 			getIsSign() const;
	int				getGrdToSgn() const;
	int				getGrdToExct() const;
	void			beSigned(Bureaucrat &brcrt);
	virtual void	execute(const Bureaucrat &executor) const = 0;
	
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};

	class FormNotSignedException : public std::exception
	{
		const char *what() const throw();
	};
    
    private:
    const std::string	name;
	const std::string	target;
	const int			grdToSgn;
	const int			grdToExct;
	bool				isSigned;
};

std::ostream &operator<<(std::ostream &out, const Form &clF);

#endif