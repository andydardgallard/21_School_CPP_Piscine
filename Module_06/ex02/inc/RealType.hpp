/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RealType.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 22:27:38 by andy              #+#    #+#             */
/*   Updated: 2022/06/29 23:39:44 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REALTYPE_HPP
# define REALTYPE_HPP

# include <iostream>
# include "Base.hpp"
# include "A.hpp"
# include "B.hpp"
# include "C.hpp"

class Base;

class RealType
{
public:
    RealType();
    ~RealType();
    RealType(const RealType& other);
    RealType& operator=(const RealType& other);

    Base*	generate(void);
    void	identify(Base* p);
    void	identify(Base& p);
};

#endif