/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:10:12 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 16:09:06 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

class Convert
{
private:
    double		nmbr;
	std::string	str;
	bool		nan_flg;
public:
    Convert();
    ~Convert();
    Convert(const Convert& other);
    Convert&	operator=(const Convert& other);
    
    void		checkArg(char *str, int argc);
    void		toChar();
	void		toInt();
	void		toFloat();
	void		toDouble();
	double		get_nmbr();
	std::string get_str();

	class ImpossibleException : public std::exception
	{
		const char *what() const throw();
	};

	class NotDisplayableException : public std::exception
	{
		const char *what() const throw();
	};

	class WrongInputException : public std::exception
	{
		const char *what() const throw();
	};
};

#endif
