/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 23:07:27 by andy              #+#    #+#             */
/*   Updated: 2022/07/03 14:25:46 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <class T>
class Array
{
private:
    unsigned int	size_arr;
	T*				arr;
public:
    Array() : size_arr(0), arr(nullptr)
    {
		std::cout << "Default Constructor is called" << std::endl;
    }
    
    ~Array()
    {
        std::cout << "Destructor is called" << std::endl;
		if (this->arr)
            delete[] this->arr;
    }
	
    Array(const Array& other)
	{
		std::cout << "Copy Constructor is called" << std::endl;
		*this = other;
	}
	
    Array& operator=(const Array& other)
	{
		std::cout << "Assignment operator is called" << std::endl;
		if (this == &other)
			return *this;
		// if (this->size_arr > 0)
		// 	delete[] this->arr;
		this->size_arr = other.size_arr;
		this->arr = new T[size_arr];
		for (unsigned int i = 0; i < size_arr; i++)
			this->arr[i] = other[i];
		return *this;
	}

    Array(const unsigned int n) : size_arr(n)
	{
		
		if (size_arr < 0)
			throw std::overflow_error("Index out of range");
		this->arr = new T[n];
		std::cout << "Constructor is called at " << n << " elements" << std::endl;
	}
	
	T	&operator[](unsigned int indx) const
	{
		if (indx >= this->size_arr)
			throw std::out_of_range("Index out of range");
		return this->arr[indx];
	}
	
	unsigned int Size()
	{
		return this->size_arr;
	}

	T*	getArrPntr()
	{
		return arr;
	}
	
	
	
};

#endif