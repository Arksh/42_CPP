/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cagonzal <cagonzal@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 15:16:09 by cagonzal          #+#    #+#             */
/*   Updated: 2023/10/05 13:24:24 by cagonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

/**
 * @brief Constructor for the Account class.
 *
 * This constructor initializes an Account object with the given initial deposit amount.
 * It assigns an account index, increments the total number of accounts, and updates the total amount.
 * It also initializes the number of deposits and withdrawals.
 *
 * @param initial_deposit The initial deposit amount for the account.
 */
Account::Account(int initial_deposit ) : _amount(initial_deposit)
{
	_accountIndex = getNbAccounts();
	Account::_nbAccounts++;
	Account::_totalAmount += this->_amount;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";created"<<std::endl;
	return;
}

Account::Account(void)
{
	return;
}

/**
 * @brief Destructor for the Account class.
 *
 * This destructor is responsible for cleaning up resources associated with an Account object.
 * It displays information about the account's closure.
 */
Account::~Account( void )
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";amount:"<<this->checkAmount();
	std::cout<<";closed"<<std::endl;
	return;
}

/**
 * @brief Display information about all accounts.
 *
 * This static member function displays information about all accounts, including the total number of accounts,
 * the total amount held in all accounts, the total number of deposits, and the total number of withdrawals.
 */
void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout<<"accounts:"<<getNbAccounts();
	std::cout<<";total:"<<getTotalAmount();
	std::cout<<";deposits:"<<getNbDeposits();
	std::cout<<";withdrawals:"<<getNbWithdrawals()<<std::endl;
}

/**
 * @brief Display the current timestamp in a specific format.
 *
 * This static member function displays the current timestamp in the following format: [YYYYMMDD_HHMMSS]
 */
void	Account::_displayTimestamp( void )
{
	time_t now = time(0);
	tm *ltm = localtime(&now);
	std::cout<<"["<<1900+ltm->tm_year;
	std::cout<<std::setw(2) << std::setfill('0')<<1 + ltm->tm_mon;
	std::cout<<std::setw(2) << std::setfill('0')<<ltm->tm_mday<<"_";
	std::cout<<std::setw(2) << std::setfill('0')<<ltm->tm_hour;
	std::cout<<std::setw(2) << std::setfill('0')<<ltm->tm_min;
	std::cout<<std::setw(2) << std::setfill('0')<<ltm->tm_sec<<"] ";
}

/**
 * @brief Display the account's status information.
 *
 * This member function displays information about the account's index, current amount,
 * the number of deposits, and the number of withdrawals.
 */
void	Account::displayStatus( void ) const
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";deposits:"<<this->_nbDeposits;
	std::cout<<";withdrawals:"<<this->_nbWithdrawals<<std::endl;
}

/**
 * @brief Make a deposit into the account.
 *
 * This member function allows making a deposit into the account. It updates the account's
 * balance, total amount, and the number of deposits. It also displays deposit-related information.
 *
 * @param deposit The amount to deposit into the account.
 */
void	Account::makeDeposit( int deposit )
{
	Account::_displayTimestamp();
	_amount += deposit;
	Account::_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout<<"index:"<<this->_accountIndex;
	std::cout<<";p_amount:"<<this->_amount - deposit;
	std::cout<<";deposit:"<<deposit;
	std::cout<<";amount:"<<this->_amount;
	std::cout<<";nb_deposits:"<<this->_nbDeposits<<std::endl;
}

/**
 * @brief Make a withdrawal from the account.
 *
 * This member function allows making a withdrawal from the account. It checks if the withdrawal
 * amount is greater than the current balance. If the withdrawal is successful, it updates the account's
 * balance, total amount, and the number of withdrawals. It also displays withdrawal-related information.
 *
 * @param withdrawal The amount to withdraw from the account.
 * @return true if the withdrawal was successful, false if the withdrawal was refused due to insufficient funds.
 */
bool	Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout<<"index:"<<this->_accountIndex;
	if (this->checkAmount() < withdrawal)
	{
		std::cout<<";withdrawal:refused"<<std::endl;
		return (0);
	}
	std::cout<<";p_amount:"<<this->_amount;
	_amount -= withdrawal;
	std::cout<<";withdrawal:"<<withdrawal;
	std::cout<<";amount:"<<this->_amount;
	Account::_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout<<";nb_withdrawals:"<<this->_nbWithdrawals<<std::endl;
	return (1);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

//Metodos Get
int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}
