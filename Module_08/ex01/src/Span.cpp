/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:26:55 by andy              #+#    #+#             */
/*   Updated: 2022/07/08 12:24:37 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() {N = 0;}

Span::~Span(){}

Span& Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->N = other.N;
        this->myVector = other.myVector;
    }
    return *this;
}

Span::Span(const Span& other) { *this = other; }

Span::Span(unsigned int N) { myVector.reserve(N); }

void Span::addNumber(int nmbr)
{
    if (myVector.size() < myVector.capacity())
        myVector.push_back(nmbr);
    else
        throw NoCapacityException();
}

void Span::addRangeNumbers(unsigned int N)
{
    if ((myVector.capacity() - myVector.size()) < N)
        throw NoCapacityException();
    std::vector<int> arr(N);
    std::srand(time(0));
    for (size_t i = 0; i < N; i++)
        arr[i] = std::rand() % 1000;
    std::vector<int>::iterator it = myVector.begin();
    myVector.insert(std::next(it, myVector.size()), arr.begin(), arr.end());
}

unsigned int Span::getSize() {return myVector.size();}

int Span::shortestSpan()
{
    if (myVector.size() <= 1)
        throw NotEnougthNumbersException();
    std::vector<int> tmp(myVector);
    std::sort(tmp.begin(), tmp.end());
    int min = longestSpan();
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        if ((tmp[i] - tmp[i - 1]) < min)
            min = tmp[i] - tmp[i - 1];
    }    
    return min;
}

int Span::longestSpan()
{
    if (myVector.size() <= 1)
        throw NotEnougthNumbersException();
    return (*std::max_element(myVector.begin(), myVector.end()) - 
            *std::min_element(myVector.begin(), myVector.end()));
}

int& Span::operator[](unsigned int nmbr)
{
    if (myVector.size() <= nmbr)
        throw NoCapacityException();
    return myVector[nmbr];
}

const char* Span::NoCapacityException::what() const throw()
{
    return ("No capacity");
}

const char* Span::NotEnougthNumbersException::what() const throw()
{
    return ("Not Enougth Numbers");
}
