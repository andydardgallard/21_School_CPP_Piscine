#include "Rplc.hpp"

int		Rplc::ft_write(std::ofstream *new_file)
{
	(*new_file).open("replaced_file.txt", std::ios_base::app);
	if (!(*new_file).is_open())
		return (1);
	(*new_file) << line << std::endl;
	(*new_file).close();
	return(0);
}

void	Rplc::ft_rplc(std::size_t *found, std::string *new_line, std::string *line)
{
	(*new_line).append(*line, 0, *found);
	(*new_line).append(str2);
	(*new_line).append(*line, (*found) + str1.length(), (*line).length());
	*line = *new_line;
}

int	Rplc::ft_replace(std::ifstream *file, std::string string1, std::string string2)
{
	str1 = string1;
	str2 = string2;
	std::remove("replaced_file.txt");
	while(getline(*file, line))
	{
		new_line.erase();
		std::size_t found = line.find(str1);
		if (found != std::string::npos)
		{
			ft_rplc(&found, &new_line, &line);
			while (found < line.length())
			{
				line = new_line;
				new_line.erase();
				found = line.find(str1.c_str(), found + 1, str1.length());
				if (found != std::string::npos)
					ft_rplc(&found, &new_line, &line);
			}
		}	
		if (ft_write(&new_file))
			return (1);
	}
	return (0);
}
