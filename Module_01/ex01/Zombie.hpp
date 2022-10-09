#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
private:
    int			n;
	std::string	name;
public:
    Zombie();
    ~Zombie();
    void    set(int n, std::string name);
    void    annonce(void);
};

Zombie*		zombieHorde(int N, std::string name);

#endif