#include "Zombie.hpp"

int main()
{
	Zombie *asd = newZombie("dgallard");
	asd->announce();
	delete (asd);

	randomChump("andy");
	
	Zombie qwe("Foo");
	qwe.announce();
    return (0);
}