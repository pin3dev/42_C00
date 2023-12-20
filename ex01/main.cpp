#include "Phonebook.hpp"
#include "Contacts.hpp"
#include <iostream>
#include <string>

static void	print_menu()
{
	std::cout << "		" CYAN "      |  MENU  |       " RESET << std::endl;
	std::cout << "		" CYAN "-----------------------" RESET << std::endl;
	std::cout << "		" CYAN "| ADD | SEARCH | EXIT |" RESET << std::endl;
	std::cout << BKGRAY "[Advice]: Enter w/ command:" RESET " ";
}

static void	exec_menu(std::string &input, Phonebook &my, int &index)
{
	if (!input.compare("ADD"))
		add_contact(&my, index);
	if (!input.compare("SEARCH"))
		search_contact(&my);
}

int main(void)
{
	int			index;
	bool		status;
	Phonebook	my;
	std::string	input;
	
	index = 0;
	while (true)
	{
		status = false;
		print_menu();
		if (!std::getline(std::cin, input))
			return (false);
		if (!input.compare("EXIT"))
			return (false);
		if (!input.compare("ADD") || !input.compare("SEARCH"))
		{
			status = true;
			exec_menu(input, my, index);
		}
		if	(!status)
			std::cout << RED "[Error]: Command not found. Try again..." RESET << std::endl;
	}
	return (0);
}
