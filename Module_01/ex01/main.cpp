#include "Zombie.hpp"

int		main()
{
	int i, n = 10;
	
	Zombie	*horde = zombieHorde(n, "dgallard");
	for(i = 0; i < n; ++i)
		horde[i].annonce();
	delete [] horde;
	return 0;
}