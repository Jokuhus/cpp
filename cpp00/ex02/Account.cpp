#include <iostream>
#include <ctime>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void )
{
	this->_accountIndex = 0;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
}

Account::Account( int initial_deposit )
{
	this->_accountIndex = this->_nbAccounts;
	this->_nbAccounts++;
	this->_amount += initial_deposit;
	this->_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << checkAmount() << ';'
			  << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << checkAmount() << ";closed" << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	result = std::time(nullptr);
	std::tm		*time = std::localtime(&result);
	int			year;
	int			month;
	int			day;
	int			hour;
	int			minute;
	int			second;

	year = 1900 + time->tm_year;
	month = 1 + time->tm_mon;
	day = time->tm_mday;
	hour = time->tm_hour;
	minute = time->tm_min;
	second = time->tm_sec;
	std::cout << '['
			  << std::setw(4) << year
			  << std::setw(2) << std::setfill('0') << month
			  << std::setw(2) << std::setfill('0') << day
			  << '_'
			  << std::setw(2) << std::setfill('0') << hour
			  << std::setw(2) << std::setfill('0') << minute
			  << std::setw(2) << std::setfill('0') << second
			  << "] ";
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << checkAmount() << ';';
	this->_amount += deposit;
	_totalAmount += deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "deposits:" << deposit << ';';
	std::cout << "amount:" << checkAmount() << ';';
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';';
	std::cout << "p_amount:" << checkAmount() << ';';
	if (checkAmount() < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << withdrawal << ';';
	std::cout << "amount:" << checkAmount() << ';';
	std::cout << "nb_withdrawal:" << this->_nbWithdrawals << std::endl;
	return (true);
}

int	Account::checkAmount( void ) const
{
	return (this->_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << checkAmount() << ';'
			  << "deposits:" << this->_nbDeposits << ';'
			  << "withdrawal:" << this->_nbWithdrawals << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ';'
			  << "total:" << getTotalAmount() << ';'
			  << "deposits:" << getNbDeposits() << ';'
			  << "withdrawals:" << getNbWithdrawals() << std::endl;
}
