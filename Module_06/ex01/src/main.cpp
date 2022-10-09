/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 21:24:20 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 22:02:32 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int	main()
{
	Data data;
	data.name = "dgallard";
	data.score = 42.0f;
	data.rank = 'A';
	Data* dataPntr = &data;
	
	std::cout << "Original" << std::endl;
	std::cout << "pntr:  " << dataPntr << std::endl;
	std::cout << "Name:  " << data.name << std::endl;
	std::cout << "Score: " << data.score << std::endl;
	std::cout << "Rank:  " << data.rank << std::endl;
	std::cout << std::endl;
	
	uintptr_t		rePntr;
	Serialization	srlztr;
	rePntr = srlztr.serialize(&data);
	
	std::cout << "rePntr: 0x" << std::hex << rePntr << std::endl;
	std::cout << std::endl;

	dataPntr = srlztr.deserialize(rePntr);
	std::cout << "Deserialized" << std::endl;
	std::cout << "pntr:  " << dataPntr << std::endl;
	std::cout << "Name:  " << dataPntr->name << std::endl;
	std::cout << "Score: " << dataPntr->score << std::endl;
	std::cout << "Rank:  " << dataPntr->rank << std::endl;
	
	return 0;
}