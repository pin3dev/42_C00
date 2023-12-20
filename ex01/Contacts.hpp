/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:13:34 by ivbatist          #+#    #+#             */
/*   Updated: 2023/12/20 22:13:36 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACTS_HPP
#define CONTACTS_HPP

#include <string>

class Contacts
{
	private :
		std::string Fname;
		std::string Sname;
		std::string Nname;
		std::string Pnumber;
		std::string Dsecret;
	public :
		std::string getterFname();
		std::string getterSname();
		std::string getterNname();
		std::string getterPnumber();
		std::string getterDsecret();

		void setterFname(std::string Fame);
		void setterSname(std::string Same);
		void setterNname(std::string Name);
		void setterPnumber(std::string phone);
		void setterDsecret(std::string secret);
};

#endif
