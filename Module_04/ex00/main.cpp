/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 07:39:01 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 17:46:44 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <chrono>
#include <thread>

int	main()
{
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl; 
	std::cout << i->getType() << " " << std::endl; 
	i->makeSound(); //will output the cat sound! j->makeSound();
    meta->makeSound();
	j->makeSound();
	std::cout << meta->getType() << std::endl;
	
	delete meta;
	delete j;
	delete i;

	std::cout << std::endl << "---------" << std::endl;

	const WrongAnimal *wrong_meta = new WrongAnimal();
	const WrongAnimal *wrong_j = new WrongCat();
	std::cout << wrong_j->getType() << " " << std::endl;
	wrong_j->makeSound();
	std::cout << wrong_meta->getType() << " " << std::endl;
	wrong_meta->makeSound();

	delete wrong_j;
	delete wrong_meta;

	std::this_thread::sleep_for(std::chrono::seconds(100));
	
	return 0;
}
