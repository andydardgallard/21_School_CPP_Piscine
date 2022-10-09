/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 09:12:43 by andy              #+#    #+#             */
/*   Updated: 2022/06/20 11:43:54 by andy             ###   ########.fr       */
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

	Form(std::string name, const int grdToSgn, const int grdToExct);
	std::string getName() const;
	bool 		getIsSign() const;
	int			getGrdToSgn() const;
	int			getGrdToExct() const;
	void		beSigned(Bureaucrat &brcrt);
	
	class GradeTooHighException : public std::exception
	{
		const char *what() const throw();
	};
	
	class GradeTooLowException : public std::exception
	{
		const char *what() const throw();
	};
    
    private:
    const std::string	name;
    bool				isSigned;
	const int			grdToSgn;
	const int			grdToExct;
};

std::ostream &operator<<(std::ostream &out, const Form &clF);

#endif