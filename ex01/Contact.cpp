/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:13:26 by ivbatist          #+#    #+#             */
/*   Updated: 2023/12/20 22:13:28 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <string>

//IMPLEMENTAÇÃO DOS MÉTODOS SETTER
void Contact::setterFname(std::string Fame)
{
	Fname = Fame;
}

void Contact::setterSname(std::string Same)
{
	Sname = Same;
}

void Contact::setterNname(std::string Name)
{
	Nname = Name;
}

void Contact::setterPnumber(std::string phone)
{
	Pnumber = phone;
}

void Contact::setterDsecret(std::string secret)
{
	Dsecret = secret;
}

//IMPLEMENTAÇÃO DOS MÉTODOS GETTER
std::string Contact::getterFname()
{
	return (Fname);
}

std::string Contact::getterSname()
{
	return (Sname);
}

std::string Contact::getterNname()
{
	return (Nname);
}

std::string Contact::getterPnumber()
{
	return (Pnumber);
}

std::string Contact::getterDsecret()
{
	return (Dsecret);
}
