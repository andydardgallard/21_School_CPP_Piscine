#include "phonebook.hpp"

class Contact
{
	private:
		t_book	pbook;
		enum	fields {f_name, l_name, nick, phone, secret};

		std::string	ft_make_displ_field(std::string str)
		{
			std::string	tmp;
			if(str.length() <= 10)
			{
				for (int i = 0; i <= 10 - (int)str.length(); i++)
					tmp.append(" ", 0, i);
				tmp.append(str, 0, str.length());
			}
			else
			{
					tmp.append(str, 0, 9);
					tmp.append(".", 0, 1);
			}
			return (tmp);
		}

	public:
		void	fill_f_name(std::string str, int c_field, int *person)
		{
			switch (c_field)
			{
				case f_name:
					pbook.contacts[*person].first_name = str;
					break;
				case l_name:
					pbook.contacts[*person].last_name = str;
					break;
				case nick:
					pbook.contacts[*person].nickname = str;
					break;
				case phone:
					pbook.contacts[*person].phone_num = str;
					break;
				case secret:
					pbook.contacts[*person].d_secret = str;
					break;
			}
		}

		void	ft_display_book()
		{
			for (int i = 1; i < 9; i++)
			{
				std::string tmp;
				tmp.append(ft_make_displ_field(std::to_string(i)), 0, ft_make_displ_field(std::to_string(i)).length());
				tmp.append("|", 0, 1);
				tmp.append(ft_make_displ_field(pbook.contacts[i - 1].first_name), 0, ft_make_displ_field(pbook.contacts[i - 1].first_name).length());
				tmp.append("|", 0, 1);
				tmp.append(ft_make_displ_field(pbook.contacts[i - 1].last_name), 0, ft_make_displ_field(pbook.contacts[i - 1].last_name).length());
				tmp.append("|", 0, 1);
				tmp.append(ft_make_displ_field(pbook.contacts[i - 1].nickname), 0, ft_make_displ_field(pbook.contacts[i - 1].nickname).length());
				std::cout << tmp << std::endl;
			}
		}

		void	ft_displ_srch_rslts(int i)
		{
			std::cout << pbook.contacts[i - 1].first_name << std::endl;
			std::cout << pbook.contacts[i - 1].last_name << std::endl;
			std::cout << pbook.contacts[i - 1].nickname << std::endl;
			std::cout << pbook.contacts[i - 1].phone_num << std::endl;
			std::cout << pbook.contacts[i - 1].d_secret << std::endl;
		}

};

class PhoneBook
{
	private:
		int		c_field;

		void	ft_spaces(std::string *str)
		{
			size_t strBegin = (*str).find_first_not_of(' ');   // del spaces before string
			if (strBegin != 0)
				(*str).erase(0, strBegin);
			size_t strEnd = (*str).find_last_not_of(' ');		// del spaces after string
			if(strEnd != std::string::npos)
				(*str).erase(strEnd + 1);
		}

		void	ft_read_field(std::string *input, std::string f_name, int c_field, int *person)
		{
			std::cout << ">> insert " << f_name << " > ";
			std::getline(std::cin, *input);
			ft_spaces(input);
			while ((*input).empty())
			{
				std::cout << ">> insert " << f_name << " > ";
				std::getline(std::cin, *input);
				ft_spaces(input);
			}
			cont.fill_f_name(*input, c_field, person);
		}

		void	ft_check_index(std::string *str)
		{
			int i = std::atoi((*str).c_str());
			if (i < 1 || i > 8)
			{
				std::cout << "Wrong index. Insert index from 1 to 8." << std::endl;
				(*str).clear();
			}
			else
				cont.ft_displ_srch_rslts(i);
		}

	public:
		Contact		cont;
		std::string input;
		
		void	read_input(int *person)
		{	
			c_field = 0;
			ft_read_field(&input, "First Name", c_field++, person);
			ft_read_field(&input, "Last Name", c_field++, person);
			ft_read_field(&input, "Nickname", c_field++, person);
			ft_read_field(&input, "Phone Number", c_field++, person);
			ft_read_field(&input, "Darcest Secret", c_field++, person);
			*person = *person >= 7 ? 0 : *person += 1;
		}

		void	ft_displ_srch()
		{
			std::cout << ">> insert idex to display > ";
			std::getline(std::cin, input);
			ft_spaces(&input);
			ft_check_index(&input);
			while (input.empty())
			{
				std::cout << ">> insert idex to display > ";
				std::getline(std::cin, input);
				ft_spaces(&input);
				ft_check_index(&input);
			}
		}
};

int	main()
{
	int			person;
	PhoneBook	book;
	std::string input;
	
	person = 0;
	while (input != "EXIT")
	{
		std::cout << "> insert command > ";
		std::getline(std::cin, input);
		if (input == "ADD")
			book.read_input(&person);
		if (input == "SEARCH")
		{
			book.cont.ft_display_book();
			book.ft_displ_srch();
		}
	}
	return (0);
}