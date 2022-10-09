/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 20:49:12 by andy              #+#    #+#             */
/*   Updated: 2022/07/09 23:37:42 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
    MutantStack<T>() {}
    ~MutantStack<T>() {}
    MutantStack<T>& operator=(const MutantStack& other)
    {
        (void) other;
        return *this;
    }
    MutantStack<T>(const MutantStack& other) {*this = other;}
    
    typedef typename std::stack<T>::container_type::iterator iterator;
    iterator begin() { return this->std::stack<T>::c.begin(); }
    iterator end() { return this->std::stack<T>::c.end(); }
    
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;
    const_iterator cbegin() const { return this->std::stack<T>::c.begin(); }
    const_iterator cend() const { return this->std::stack<T>::c.end(); }

    typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
    reverse_iterator rbegin() { return this->std::stack<T>::c.rbegin(); }
    reverse_iterator rend() { return this->std::stack<T>::c.rend(); }

    typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;
    const_reverse_iterator rbegin() const { return this->std::stack<T>::c.rbegin(); }
    const_reverse_iterator rend() const { return this->std::stack<T>::c.rend(); }
};

#endif