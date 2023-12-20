
#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"

int main(void)
{

	//DEFINIÇÕES_____________________________________________________________
	//																		\/

	//DEFINIÇÃO DO TIPO CONTAINER ACCOUNTS_T
	typedef std::vector<Account::t> accounts_t;
	
	//DEFINIÇÃO DO TIPO CONTAINER INTS_T
	typedef std::vector<int> ints_t;
	
	//DEFINIÇÃO DO TIPO PAIR ACC_INT_T: 
	/*	par de iteradores de container tipo accounts_t e ints_t	*/
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	
	//CRIAÇÕES E ATRIBUIÇÕES_____________________________________________________________
	//																					\/

	//CRIAÇÃO DE ARRAY DE INTS AMOUNT[]:
	/*	Usado como parâmetro para constructor Account(int)	*/
	int const amounts[] = {42, 54, 957, 432, 1234, 0, 754, 16576};

	/*	Cálculo de quantos elementos size_t há  no array de ints amount[]	*/
	size_t const amounts_size(sizeof(amounts) / sizeof(int));
	
	//CRIAÇÃO DO CONTAINER ACCOUNTS DO TIPO ACCOUNTS_T &&
	//INICIALIZAÇÃO DOS OBJETOS ACCOUNTS_T DENTRO DO CONTAINER COM
	/*	Todos os valores presentes no array int amounts[] são passados 
	como parâmetro para o constuctor de instaciamento do objeto		*/
	accounts_t accounts(amounts, amounts + amounts_size);

	/*	[	PRIMEIRO OUTPUT		] -> constructor Account(int): 
		OUTPUT *(Account_t) -> [timestamp] index:_;amount:_;created 	*/
	
	//CRIAÇÃO DE ITERADORES PARA CONTAINER TIPO ACCOUNTS_T
	/*	Criado dois iteradores com o primeiro e 
	ultimo objeto do container accounts		*/
	accounts_t::iterator acc_begin = accounts.begin();
	accounts_t::iterator acc_end = accounts.end();

	//CRIAÇÃO DE ARRAY DE INTS D[]:
	/*	Usado como parâmetro para a construção 
	do container deposits do tipo ints_t	*/
	int const d[] = {5, 765, 564, 2, 87, 23, 9, 20};
	
	/*	Cálculo de quantos elementos size_t há  no array de ints d[]	*/
	size_t const d_size(sizeof(d) / sizeof(int));
	
	//CRIAÇÃO DO CONTAINER DEPOSITS DO TIPO INTS_T &&
	/*	Todos os valores presentes no array int d[] são passados 
	como atribuição para os inteiros que compõem o container	*/
	ints_t deposits(d, d + d_size);

	//CRIAÇÃO DE ITERADORES PARA CONTAINER TIPO INTS_T
	/*	Criado dois iteradores com o primeiro e 
	ultimo objeto do container deposits		*/
	ints_t::iterator dep_begin = deposits.begin();
	ints_t::iterator dep_end = deposits.end();

	//CRIAÇÃO DE ARRAY DE INTS W[]:
	/*	Usado como parâmetro para a construção 
	do container withdrawals do tipo ints_t	*/
	int const w[] = {321, 34, 657, 4, 76, 275, 657, 7654};
	
	/*	Cálculo de quantos elementos size_t há  no array de ints w[]	*/
	size_t const w_size(sizeof(w) / sizeof(int));

	//CRIAÇÃO DO CONTAINER WITHDRAWALS DO TIPO INTS_T &&
	/*	Todos os valores presentes no array int w[] são passados 
	como atribuição para os inteiros que compõem o container	*/
	ints_t withdrawals(w, w + w_size);

	//CRIAÇÃO DE ITERADORES PARA CONTAINER TIPO INTS_T
	/*	Criado dois iteradores com o primeiro e 
	ultimo objeto do container withdrawals		*/
	ints_t::iterator wit_begin = withdrawals.begin();
	ints_t::iterator wit_end = withdrawals.end();

	//EXECUÇÃO:_____________________________________________________________
	//																		\/

	/*	[	SEGUNDO OUTPUT	] -> método estático displayAccountsInfos(): 
		OUTPUT *(1) -> [timestamp]  accounts:_;total:_;deposits:0;withdrawals:0;
	
	Acessa aos atributos inerentes/estáticos da classe e 
	retorna uma cópia deles	*/
	Account::displayAccountsInfos();

	//TRANSFORMAÇÃO DO MÉTODO GETTER CONST DISPLAYSTATUS() EM FUNÇÃO GERAL
	/*	[	TERCEIRO OUTPUT		] -> O método displayStatus() é transformado em função geral por mem_fun_ref() 
		para ser aplicada em aos objetos/instâncias do container accounts
		do tipo accounts_t, pela função for_each() 
		em um range de acc_begin->até->acc_end, 
		mesmo que accounts[0]->até->account[end]	
		OUTPUT *(Accounts_t) -> [timestamp] index:_;amount:_;deposits:0;withdrawals:0;		*/
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	//CRIAÇÃO DE PAIR TIPO ACC_INT_T PAR ITERAÇÃO ATRAVÉS DE 2 CONTAINERS DE TIPOS DIFERENTES
	/*	O loop itera paralelamente entre o inicio e o fim de dois containers
		o primeiro de tipo accounts_t e o segundo tipo ints_t
		acessando o método makeDeposit() do objeto atual do primeiro container
		e atribuindo o valor de int, apontado no segundo container, como parâmetro do método	*/
	for (acc_int_t it(acc_begin, dep_begin);
		 it.first != acc_end && it.second != dep_end;
		 ++(it.first), ++(it.second))
	{
		(*(it.first)).makeDeposit(*(it.second));
		/*	[	QUARTO OUTPUT	] -> método makeDeposit(int): 
			OUTPUT *(1 para cada loop) -> [timestamp] index:_;p_amount:_;deposit:*(it.second);amount:_;nb_deposits:1 	*/
	}

	/*	[	QUINTO OUTPUT	] -> método estático displayAccountsInfos(): 
		OUTPUT *(1) -> [timestamp]  accounts:_;total:_;deposits:_;withdrawals:0;	*/
	Account::displayAccountsInfos();

	/*	[	SEXTO OUTPUT	] -> O método displayStatus() 
		OUTPUT *(Accounts_t) -> [timestamp] index:_;amount:_;deposits:_;withdrawals:0;		*/
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	//CRIAÇÃO DE PAIR TIPO ACC_INT_T PAR ITERAÇÃO ATRAVÉS DE 2 CONTAINERS DE TIPOS DIFERENTES
	/*	O loop itera paralelamente entre o inicio e o fim de dois containers
		o primeiro de tipo accounts_t e o segundo tipo ints_t
		acessando o método makeWithdrawal() do objeto atual do primeiro container
		e atribuindo o valor de int, apontado no segundo container, como parâmetro do método	*/
	for (acc_int_t it(acc_begin, wit_begin);
		 it.first != acc_end && it.second != wit_end;
		 ++(it.first), ++(it.second))
	{
		(*(it.first)).makeWithdrawal(*(it.second));
		/*	[	SÉTIMO OUTPUT	] -> método makeWithdrawal(int): 
			OUTPUT *(1 para cada loop) -> [timestamp] [19920104_091532] index:_;amount:_;deposits:_;withdrawals:_ 	*/
	}

	/*	[	OITAVO OUTPUT	] -> método estático displayAccountsInfos(): 
		OUTPUT *(1) -> [timestamp]  accounts:_;total:_;deposits:_;withdrawals:_;	*/
	Account::displayAccountsInfos();

	/*	[	NONO OUTPUT	] -> O método displayStatus() 
		OUTPUT *(Accounts_t) -> [timestamp] index:_;amount:_;deposits:_;withdrawals:_;		*/
	std::for_each(acc_begin, acc_end, std::mem_fun_ref(&Account::displayStatus));

	/*	[	DÉCIMO OUTPUT	] -> O método destructor ~Account(void) 
		OUTPUT *(Accounts_t) -> [timestamp] index:_;amount:_;closed;		*/
	return 0;
}
