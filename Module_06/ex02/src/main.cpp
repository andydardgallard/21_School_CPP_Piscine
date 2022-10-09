/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:04:15 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 23:57:22 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "RealType.hpp"
#include <chrono>
#include <thread>

int main()
{
    RealType rlTp;
    Base* bs_pntr = rlTp.generate();
    rlTp.identify(bs_pntr);
    rlTp.identify(*bs_pntr);
    
    delete bs_pntr;
    // std::this_thread::sleep_for(std::chrono::seconds(100));
    return 0;
}