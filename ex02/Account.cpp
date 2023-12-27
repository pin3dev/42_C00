/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivbatist <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 22:15:01 by ivbatist          #+#    #+#             */
/*   Updated: 2023/12/20 22:15:03 by ivbatist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

//ATRIBUTOS ESTÁTICOS: Inicialização
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//MÉTODO CONSTRUCTOR PADRÃO:
Account::Account()
{
}

//MÉTODO CONSTRUCTOR: com lista de inicialização
Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts), _amount(initial_deposit),
	  _nbDeposits(0), _nbWithdrawals(0)
{
	//incremento de atributos estáticos
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;

	//impressão
	_displayTimestamp();
	std::cout << /* GRAY */ " index:" << this->_accountIndex
			  << ";amount:" << Account::checkAmount()
			  << ";created" /* RESET */ << std::endl;
}

//MÉTODO DESTRUCTOR
Account::~Account(void)
{
	//impressão
	_displayTimestamp();
	std::cout << /* GRAY */ " index:" << this->_accountIndex
			  << ";amount:" << Account::checkAmount()
			  << ";closed" /* RESET */ << std::endl;
}

//MÉTODO GETTER DE ATRIBUTOS ESTÁTICOS
int Account::getNbAccounts(void) 
{ 
	return (Account::_nbAccounts);
}
int Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}
int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}
int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
int Account::checkAmount(void) const
{
	return (this->_amount);
}

//MÉTODO SETTER
void Account::makeDeposit(int deposit)
{
	//início impressão
	_displayTimestamp();
	std::cout << /* GREEN */ " index:" << this->_accountIndex
			  << ";p_amount:" << Account::checkAmount();
			  /* << RESET; */
	//verificação de erro
	if (deposit > 0)
	{
		//incremento nos atributos do objetos
		this->_nbDeposits++;
		this->_amount += deposit;

		//incremento nos atributos estáticos
		Account::_totalNbDeposits++;
		Account::_totalAmount += deposit;

		//continuação de impressão
		std::cout << /* GREEN */ ";deposit:" << deposit
				  << ";amount:" << Account::checkAmount()
				  << ";nb_deposits:" << this->_nbDeposits
				  /* << RESET */ << std::endl;
	}
	else	//retorno error
		std::cout << /* GREEN */ ";deposit:refused" /* RESET */ << std::endl;
}

//MÉTODO SETTER
bool Account::makeWithdrawal(int withdrawal)
{
	//início de impressão
	_displayTimestamp();
	std::cout << /* RED */ " index:" << this->_accountIndex
			<< ";p_amount:" << Account::checkAmount();
			/*<< RESET ;*/
	//verificação de erro
	if (withdrawal <= 0 || this->_amount - withdrawal < 0)
	{
		std::cout << /* RED */ ";withdrawal:refused" /* RESET  */<< std::endl;
		return (false);
	}
	//verificação de erro
	else if (this->_amount - withdrawal >= 0)
	{
		//incremento em atributos do objetos
		this->_nbWithdrawals++;
		this->_amount -= withdrawal;

		//incremento em atributos estáticos
		Account::_totalNbWithdrawals++;
		Account::_totalAmount -= withdrawal;

		std::cout << /* RED */ ";withdrawal:" << withdrawal
				  << ";amount:" << Account::checkAmount()
				  << ";nb_withdrawals:" << this->_nbWithdrawals
				  /* << RESET */ << std::endl;
		return (true);
	}
	return (false);
}

//MÉTODO DISPLAYER (GETTER CONST)
void Account::displayAccountsInfos(void)
{
	//impressão de atributos estáticos
	_displayTimestamp();
	std::cout << /* CYAN */ " accounts:" << getNbAccounts()
			  << ";total:" << getTotalAmount()
			  << ";deposits:" << getNbDeposits()
			  << ";withdrawals:" << getNbWithdrawals() 
			  /* << RESET */ << std::endl;
}

void Account::displayStatus(void) const
{
	//impressão de atributos do objeto
	_displayTimestamp();
	std::cout << /* YELLOW */ " index:" << this->_accountIndex
			  << ";amount:" << Account::checkAmount()
			  << ";deposits:" << this->_nbDeposits
			  << ";withdrawals:" << this->_nbWithdrawals
			  /* << RESET */ << std::endl;
}


//MÉTODO PRIVADO: de uso interno
void Account::_displayTimestamp(void)
{
	time_t now = time(NULL);
	struct tm *time = localtime(&now);
	char buf[20];

	strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", time);
	std::cout << buf;
}
