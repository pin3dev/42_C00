/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:13:42 by ivbatist          #+#    #+#             */
/*   Updated: 2023/12/20 22:13:44 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <sstream>

//MÉTODO
Contacts&	Phonebook::getter_contact(int index)
{
	return (contact[index]);
}

//MAIN
void		add_contact(Phonebook *div, int &i)
{
	std::string dsecret;
	std::string	fname;
	std::string	sname;
	std::string	nname;
	std::string	pnumber;
	Contacts *cur;

	fname = get_data("First Name", ALPHAS);
	sname = get_data("Second Name", ALPHAS);
	nname = get_data("Nick Name", ALPHAS);
	pnumber = get_data("Phone Number", DIGITS);
	dsecret = get_data("Dark Secret", ALPHAS);

	cur = &div->getter_contact(i);
	cur->setterFname(fname);
	cur->setterSname(sname);
	cur->setterNname(nname);
	cur->setterPnumber(pnumber);
	cur->setterDsecret(dsecret);

	std::cout << GREEN "[Success]: Contact Added" RESET << std::endl;
	i++;
	if (i > 7)
		i = 0;
}

void	search_contact(Phonebook *div)
{
	std::string	input;
	Contacts cur;

	print_line_aligned("Index", "FirstName", "LastName", "NickName");
	for (int j = 0; j < 8; j++)
	{
		std::stringstream t;

		t << j;
		std::string index = t.str();
		cur = div->Phonebook::getter_contact(j);
		if (!ck_members_class(cur))
			break ;
		print_line_aligned((index), abr(cur.getterFname()), abr(cur.getterSname()), abr(cur.getterNname()));
	}
	std::cout << BKGRAY "[Advice]: Enter index of contact:" RESET " ";
	if (!std::getline(std::cin, input) || !isdigit(input[0]) 
		|| input.length() > 1 || input.empty() || my_atoi(input) > 7)
	{
		std::cout << RED "[Error]: Wrong command format. Try again..." RESET << std::endl;
		search_contact(div);
		return ;
	}
	cur = div->Phonebook::getter_contact((my_atoi(input)));
	if (ck_members_class(cur))
	{
		std::cout << GREEN "First Name : " << cur.getterFname() << std::endl;
		std::cout << "Last Name : " << cur.getterSname() << std::endl;
		std::cout << "Nick Name : " << cur.getterNname() << std::endl;
		std::cout << "Phone number : " << cur.getterPnumber() << std::endl;
		std::cout << "Dark Secret : " << cur.getterDsecret() + RESET << std::endl;
		return ;
	}
	std::cout << RED "[Error]: Contact not found. Try again..." RESET << std::endl;
	search_contact(div);
}
