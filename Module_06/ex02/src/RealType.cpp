/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:32:11 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 23:54:47 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RealType.hpp"

RealType::RealType() {}

RealType::~RealType() {}

RealType::RealType(const RealType& other) {*this = other;}

RealType& RealType::operator=(const RealType& other)
{
	if (this == &other)
		return *this;
	return *this;
}

Base*	RealType::generate(void)
{
	std::srand(time(0));
	switch (rand() % 3)
	{
	case 0:
		return (new A);
	case 1:
		return (new B);
	case 2:
		return (new C);
	default:
		std::cerr << "Genaration inhabitans failed" << std::endl;
		return (nullptr);
	}
}

void	RealType::identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "Identified A* class" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "Identified B* class" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "Identified C* class" << std::endl;
	else
		std::cout << "Unidentified class" << std::endl;
}

void	RealType::identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		std::cout << "Identified A& class" << std::endl;
	}
	catch(const std::exception& e) {}
	
	try
	{
		B b = dynamic_cast<B&>(p);
		std::cout << "Identified B& class" << std::endl;
	}
	catch(const std::exception& e) {}

	try
	{
		C c = dynamic_cast<C&>(p);
		std::cout << "Identified C& class" << std::endl;
	}
	catch(const std::exception& e) {}
}
