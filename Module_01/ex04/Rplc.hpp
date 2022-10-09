#ifndef RPLC_HPP
# define RPLC_HPP

# include <iostream>
# include <fstream>

class Rplc
{
private:
	std::string		line;
	std::string		str1;
	std::string		str2;
	std::string		new_line;
	std::ofstream	new_file;

	int				ft_write(std::ofstream *new_file);
	void			ft_rplc(std::size_t *found, std::string *new_line, std::string *line);
public:
	int				ft_replace(std::ifstream *file, std::string string1, std::string string2);
};

#endif
