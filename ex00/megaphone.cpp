/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:12:53 by ivbatist          #+#    #+#             */
/*   Updated: 2023/12/20 22:12:55 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <sstream>

void toUpperCase(std::string& str) 
{
    for (size_t i = 0; i < str.length(); ++i)
        str[i] = std::toupper(str[i]);
}

int main(int ac, char** av) 
{
	if(ac > 1)
	{
		std::string str;
		for (int i = 1; i < ac; i++)
		{
			str = av[i];
			toUpperCase(str);
			std::cout << str;
			if(i != (ac - 1))
				std::cout << " ";
		}
		std::cout << std::endl;
		return(0);
	}
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    return 0;
}
