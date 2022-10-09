/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 10:16:14 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 16:10:25 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert()
{
	nmbr = 0;
	nan_flg = false;
}

Convert::~Convert() {}

Convert::Convert(const Convert& other) {*this = other;}

Convert& Convert::operator=(const Convert& other)
{
    if(this != &other)
        return *this;
    this->nmbr = other.nmbr;
	this->str = other.str;
	this->nan_flg = other.nan_flg;
    return *this;
}

void    Convert::checkArg(char *str, int argc)
{
	try
	{
		if (argc != 2)
			throw WrongInputException();
		std::string s(str);
		this->str = s;
		if (s.length() == 1)
		{
			if (isdigit(s[0]))
				this->nmbr = std::stod(s);
			else
				this->nmbr = static_cast<double>(str[0]);
		}
		else
		{
			int c_dgts = 0;
			int c_chrs = 0;
			int c_pnts = 0;
			int c_mns = 0;
			for (size_t i = 0; i < s.length(); i++)
			{
				if (isdigit(static_cast<int>(s[i])))
					c_dgts++;
				else if (s[i] == '.')
					c_pnts++;
				else if (s[i] == '-' && !i)
					c_mns++;
				else
					c_chrs++;
			}
			if (c_dgts && c_pnts == 1 && c_chrs == 1 && str[s.length() - 1] == 'f')
				this->nmbr = std::stod(s);
			else if (c_dgts && c_pnts == 1 && !c_chrs)
				this->nmbr = std::stod(s);
			else if (!c_chrs && c_pnts <= 1)
				this->nmbr = std::stod(s);
			else if (s == "nan")
				nan_flg = true;
			else if (s == "inf")
				this->nmbr = std::numeric_limits<double>::infinity();
			else if (s == "-inf")
				this->nmbr = -std::numeric_limits<double>::infinity();
			else
				throw WrongInputException();
		}
	}
	catch(const std::exception& e) {throw WrongInputException();}	
}

double  Convert::get_nmbr() {return this->nmbr;}

std::string Convert::get_str() {return this->str;}

void    Convert::toChar()
{
	std::cout << "Char:   ";
	if (isascii(nmbr) && !nan_flg)
	{
		if (isprint(nmbr))
			std::cout << "'" << static_cast<char>(nmbr) << "'" << std::endl;
		else
			throw NotDisplayableException();
	}
	else
		throw ImpossibleException();
}

void	Convert::toInt()
{
	std::cout << "Int:    ";
	if (nan_flg)
		std::cout << "nan" << std::endl;
	else if (nmbr > std::numeric_limits<int>::max() || nmbr < std::numeric_limits<int>::min())
		throw ImpossibleException();
	else
		std::cout << static_cast<int>(nmbr) << std::endl;
}

void	Convert::toFloat()
{
	std::cout << "Float:  ";

	if (nan_flg)
		std::cout << "nanf" << std::endl;
	else if (nmbr > std::numeric_limits<float>::max() || nmbr < std::numeric_limits<float>::min())
		throw ImpossibleException();
	else
		std::cout << static_cast<float>(nmbr) << ".0f" << std::endl;
}

void	Convert::toDouble()
{
	std::cout << "Double: ";
	if (nan_flg)
		std::cout << "nan" << std::endl;
	else if (nmbr == std::numeric_limits<double>::infinity())
        std::cout << "inf" << std::endl;
	else if (nmbr == -std::numeric_limits<double>::infinity())
        std::cout << "-inf" << std::endl;
	else if (nmbr > std::numeric_limits<double>::max() || nmbr < std::numeric_limits<double>::min())
		throw ImpossibleException();
	 else
        std::cout << static_cast<double>(nmbr) << ".0f" << std::endl;
}

const char *Convert::ImpossibleException::what() const throw()
{
	return ("impossible");
}

const char *Convert::NotDisplayableException::what() const throw()
{
	return ("not displayable");
}

const char *Convert::WrongInputException::what() const throw()
{
	return ("Wrong Input");
}
