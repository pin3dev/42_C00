/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:13:34 by ivbatist          #+#    #+#             */
/*   Updated: 2023/12/20 22:13:36 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

class Contact
{
	//RESTRIÇÃO DE MEMBROS
	private :
		//ATRIBUTOS
		std::string Fname;
		std::string Sname;
		std::string Nname;
		std::string Pnumber;
		std::string Dsecret;
	public :
		//MÉTODOS GETTERS
		std::string getterFname();
		std::string getterSname();
		std::string getterNname();
		std::string getterPnumber();
		std::string getterDsecret();
		//MÉTODOS SETTERS
		void setterFname(std::string Fame);
		void setterSname(std::string Same);
		void setterNname(std::string Name);
		void setterPnumber(std::string phone);
		void setterDsecret(std::string secret);
};

#endif
