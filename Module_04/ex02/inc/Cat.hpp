/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andy <andy@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 16:10:23 by andy              #+#    #+#             */
/*   Updated: 2022/06/16 20:25:51 by andy             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brains;
public:
    Cat();
	~Cat();
	Cat(const Cat &other);
	Cat &operator=(const Cat &other);

	void makeSound() const;
	std::string getIdea(int count) const;
	void setIdea(std::string idea, int count) const;
};

#endif
