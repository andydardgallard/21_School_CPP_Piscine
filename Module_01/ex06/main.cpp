#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl Cmpln;
	if (argc != 2)
	{
		std::perror("Wrong quantity of arguments\n");
		return (1);
	}
	Cmpln.complain(argv[1]);
	return (0);
}
