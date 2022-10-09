#include "Rplc.hpp"

int main(int argc, char **argv)
{
	Rplc			fncts;
	std::ifstream	file;
	
	if (argc != 4)
	{
		std::perror("Wrong quantity of agruments\n");
		return (1);
	}
	file.open(argv[1]);
	if (!file.is_open())
	{
		std::perror("Cannot open input file\n");
		return (1);
	}
	int res = fncts.ft_replace(&file, argv[2], argv[3]);
	if (res)
		std::perror("Cannot open output file\n");
	file.close();
	return (0);
}