#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

typedef struct  s_contacts
{
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string phone_num;
	std::string d_secret;
}               t_cont;

typedef struct 	s_book
{
	t_cont		contacts[8];
}				t_book;


#endif