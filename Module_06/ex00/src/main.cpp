/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:03:48 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 16:08:45 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Convert.hpp"

int main(int argc, char*argv[])
{   
    Convert convertor;
    try
    {
        convertor.checkArg(argv[1], argc);
        
        try {convertor.toChar();}
        catch (const std::exception& e) {std::cerr << e.what() << '\n';}
        
        try {convertor.toInt();}
        catch (const std::exception& e) {std::cerr << e.what() << '\n';}

        try {convertor.toFloat();}
        catch (const std::exception& e) {std::cerr << e.what() << '\n';}

        try {convertor.toDouble();}
        catch (const std::exception& e) {std::cerr << e.what() << '\n';}
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    return 0;
}
