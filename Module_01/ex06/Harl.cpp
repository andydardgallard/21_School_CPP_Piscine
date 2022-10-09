#include "Harl.hpp"

void	Harl::debug(void)
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout <<
		"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do!"
		<< std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout <<
		"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout <<
		"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]" << std::endl;
	std::cout <<
		"This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void	Harl::dflt(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

void	Harl::complain(std::string level)
{
	int		num;
	enum	msg {DEBUG, INFO, WARNING, ERROR};
	void	(Harl::*f[5])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::dflt};
	
	std::string	names[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (num = 0; num < 4; ++num)
	{
		if (names[num] == level)
			break;
	}	
	switch (num)
	{
	case DEBUG:
		(this->*f[0])();
		break;
	case INFO:
		(this->*f[1])();
		break;
	case WARNING:
		(this->*f[2])();
		break;
	case ERROR:
		(this->*f[3])();
		break;
	default:
		(this->*f[4])();
		break;
	}
}
