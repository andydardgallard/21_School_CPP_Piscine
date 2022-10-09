/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:14:54 by andy              #+#    #+#             */
/*   Updated: 2022/07/08 10:17:31 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
private:
    unsigned int N;
    std::vector<int> myVector;
public:
    Span();
    ~Span();
    Span(const Span& other);
    Span& operator=(const Span& other);

    Span(unsigned int N);
    void	addNumber(int nmbr);
    int		shortestSpan();
    int		longestSpan();
    void	addRangeNumbers(unsigned int N);
	unsigned int	getSize();
	int&	operator[](unsigned int nmbr);
    
    class NoCapacityException : public std::exception
    {
        const char*what() const throw();
    };

    class NotEnougthNumbersException : public std::exception
    {
        const char*what() const throw();
    };
};

#endif