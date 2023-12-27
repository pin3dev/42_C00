/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:14:48 by ivbatist          #+#    #+#             */
/*   Updated: 2023/12/20 22:14:49 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "Phonebook.hpp"
#include <string>
#include <iomanip>
#include <cstdlib>
#include <iostream>

int		ck_members_class(Contact &c)
{
	if (c.getterFname().empty() || c.getterSname().empty()
		|| c.getterNname().empty() || c.getterPnumber().empty()
			|| c.getterDsecret().empty())
				return (0);
	return (1);
}

std::string  abr(std::string data)
{
	std::string abr;

	abr = data;
	if (data.length() >= 10)
		abr = data.substr(0, 9) + ".";
	return (abr);
}

void	print_line_aligned(std::string s1, std::string s2, std::string s3, std::string s4)
{
	std::cout << YELLOW "|" << std::setw(10) << s1
	<< "|" << std::setw(10) << s2
	<< "|" << std::setw(10) << s3
	<< "|" << std::setw(10) << s4
	<< "|" RESET << std::endl;
}

static int valid_cmd(std::string cmd, int type)
{
	if (cmd.empty())
		return 0;
	if (type == DIGITS)
	{
		if (cmd.length() < 9)
			return (0);
		for (int d = 0; cmd[d];) 
		{
			if (isdigit(cmd[d]))
				d++;
			else
				return (0);
		}
	}
	if (type == ALPHAS)
	{
		for (int c = 0; cmd[c];)
		{
			if (isalpha(cmd[c]))
				c++;
			else
				return (0);
		}
	}
	return (1);
}

std::string		get_data(std::string msg, int type)
{
	std::string data;
	std::cout << BKGRAY + msg << ":" RESET << std::endl;
	
	if (!getline(std::cin, data, '\n') || std::cin.eof())
		std::exit (1);

	if (!valid_cmd(data, type))
	{
		std::cerr << RED "\""<< data << "\"" << " is not a " << msg << " valid." RESET << std::endl; 
		std::cerr << RED "Try again..." RESET << std::endl;
		return(get_data(msg, type));
	}
	return (data);
}

int	my_atoi(std::string str)
{
	int numb;

	numb = std::atoi(str.c_str());
	return numb;
}
