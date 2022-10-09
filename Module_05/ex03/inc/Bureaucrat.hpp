/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 23:02:06 by andy              #+#    #+#             */
/*   Updated: 2022/06/20 19:18:48 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Form;

class Bureaucrat
{
    public:
	Bureaucrat();
	~Bureaucrat();
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);

	Bureaucrat(const std::string name, int grade);
	void incrementGrade();
	void decrementGrade();
	std::string getName() const;
	int getGrade() const;
	void signForm(Form &frm);
	void executeForm(const Form &form);

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
	int					grade;
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &cb);

#endif
