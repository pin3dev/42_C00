#include "Contacts.hpp"

//IMPLEMENTAÇÃO DOS MÉTODOS SETTER
void Contacts::setterFname(std::string Fame)
{
	Fname = Fame;
}

void Contacts::setterSname(std::string Same)
{
	Sname = Same;
}

void Contacts::setterNname(std::string Name)
{
	Nname = Name;
}

void Contacts::setterPnumber(std::string phone)
{
	Pnumber = phone;
}

void Contacts::setterDsecret(std::string secret)
{
	Dsecret = secret;
}

//IMPLEMENTAÇÃO DOS MÉTODOS GETTER
std::string Contacts::getterFname()
{
	return (Fname);
}

std::string Contacts::getterSname()
{
	return (Sname);
}

std::string Contacts::getterNname()
{
	return (Nname);
}

std::string Contacts::getterPnumber()
{
	return (Pnumber);
}

std::string Contacts::getterDsecret()
{
	return (Dsecret);
}