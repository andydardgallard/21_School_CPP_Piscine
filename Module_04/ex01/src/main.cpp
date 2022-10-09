/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 07:39:01 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 21:05:51 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"
#include <chrono>
#include <thread>

int	main()
{
	std::cout << "----Genesys----" << std::endl;
	const Animal	*meta[10];
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " -------" << std::endl;
		if (i % 2)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
		if (meta[i] == NULL)
		{
			std::cerr << "Allocation for " << meta[i]->getType() << " is failed" << std::endl;
			delete meta[i];
			exit(1);
		}
	}
	std::cout << std::endl;

	std::cout << "----Testing----" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << std::endl;
		std::cout << "Animal _type: " << meta[i]->getType() << std::endl;
		meta[i]->makeSound();
		std::cout << std::endl;
	}
	std::cout << std::endl;

	std::cout << "----Destructing----" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << i << " -------" << std::endl;
		delete(meta[i]);
	}
		
	std::cout << std::endl << std::endl;
	std::cout << "showing that the copy constructor creates a deep copy" << std::endl;
	std::cout << std::endl;

	std::cout << "----Constructing----" << std::endl;
	Dog *a = new Dog();
	// Cat *a = new Cat();
	if (a == NULL)
	{
		std::cerr << "Allocation for " << a->getType() << " is failed" << std::endl;
		delete a;
		exit(1);
	}
	for (size_t count = 0; count < 5; count++)
		std::cout << count << " " << a->getIdea(count) << std::endl;
	a->setIdea("QWERTY", 2);
	std::cout << std::endl;
	for (size_t count = 0; count < 5; count++)
		std::cout << count << " " << a->getIdea(count) << std::endl;
	
	std::cout << std::endl;
	std::cout << "----Constructing----" << std::endl;
	Dog *b = new Dog(*a);
	// Cat *b = new Cat(*a);
	if (b == NULL)
	{
		std::cerr << "Allocation for " << b->getType() << " is failed" << std::endl;
		delete b;
		exit(1);
	}
	for (size_t count = 0; count < 5; count++)
		std::cout << count << " " << b->getIdea(count) << std::endl;
	b->setIdea("ASDFGH", 3);
	std::cout << std::endl;
	for (size_t count = 0; count < 5; count++)
		std::cout << count << " " << b->getIdea(count) << std::endl;
	
	std::cout << "----Destructing----" << std::endl;
	delete b;
	std::cout << "-------------------" << std::endl;
	delete a;

	// std::this_thread::sleep_for(std::chrono::seconds(100));
	return 0;
	
	
}
