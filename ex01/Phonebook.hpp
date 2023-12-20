/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:13:54 by ivbatist          #+#    #+#             */
/*   Updated: 2023/12/20 22:13:56 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contacts.hpp"
#include <string>

#define ALPHAS	1
#define DIGITS	0
#define RESET    "\x1b[0m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define RED    "\x1b[1;31m"
#define CYAN    "\x1b[1;36m"
#define BKGRAY	"\x1b[47;90m"

class Phonebook
{
	private : 
		Contacts contact[8];
	public : 
		Contacts	&getter_contact(int i);
};

//MAIN
void	add_contact(Phonebook *div, int &i);
void	search_contact(Phonebook *div);

//UTILS
int		ck_members_class(Contacts &c);
void	print_line_aligned(std::string s1, std::string s2, std::string s3, std::string s4);
std::string		get_data(std::string msg, int type);
std::string  abr(std::string data);
int	my_atoi(std::string str);
bool		check_input_numb(std::string input, Phonebook *div);

#endif
