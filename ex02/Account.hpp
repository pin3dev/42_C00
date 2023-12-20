#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

/* #define RESET    "\x1b[0m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define GRAY  "\x1b[37m"
#define RED    "\x1b[1;31m"
#define CYAN    "\x1b[1;36m"
#define BKGRAY	"\x1b[47;90m" */

class Account
{
	public:
		//ATRIBUTOS PÚBLICOS GERAIS (ALIAS)
		typedef Account t;

		//MÉTODOS PÚBLICOS (CONSTRUCTOR & DESTRUCTOR)
		Account(int initial_deposit);
		~Account(void);

		//MÉTODOS ESTÁTICOS PÚBLICOS (GETTERS)
		static int getNbAccounts(void);
		static int getTotalAmount(void);
		static int getNbDeposits(void);
		static int getNbWithdrawals(void);
		static void displayAccountsInfos(void);

		//MÉTODOS GERAIS (SETTERS)
		void makeDeposit(int deposit);
		bool makeWithdrawal(int withdrawal);
		//MÉTODOS GERAIS (GETTERS)
		int checkAmount(void) const;
		void displayStatus(void) const;

	private:
		//MÉTODOS ESTÁTICOS PRIVADOS (MANUTENÇÃO ATRIBUTOS STATICS)
		static void _displayTimestamp(void);

		//ATRIBUTOS PRIVADOS ESTÁTICOS (CLASSE)
		static int _nbAccounts;
		static int _totalAmount;
		static int _totalNbDeposits;
		static int _totalNbWithdrawals;

		//ATRIBUTOS PRIVADOS GERAIS (OBJETO)
		int _accountIndex;
		int _amount;
		int _nbDeposits;
		int _nbWithdrawals;

		Account(void);
};

#endif
