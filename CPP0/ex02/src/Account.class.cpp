/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 10:22:40 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 12:27:08 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ) 
: _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _accountIndex = _nbAccounts++;
    _totalAmount += initial_deposit;
    
    _displayTimestamp();
    std::cout 
        << "index:" << _accountIndex << ";" 
        << "amount:" << _amount << ";" 
        << "created" << std::endl;
}

Account::~Account( void ) {
    _displayTimestamp();
    std::cout 
        << "index:" << _accountIndex << ";" 
        << "amount:" << _amount << ";" 
        << "closed" << std::endl;
};

int	Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int	Account::getTotalAmount( void ) {
    return _totalAmount;
}

int	Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void Account::_displayTimestamp( void ) {
    char buffer[20];
    std::time_t now = std::time(NULL);
    std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", std::localtime(&now));
    std::cout << buffer << " ";
}

void Account::displayAccountsInfos( void ) {
    _displayTimestamp();
    std::cout 
        << "accounts:" << getNbAccounts() << ";"
        << "total:" << getTotalAmount() << ";"
        << "deposits:" << getNbDeposits() << ";"
        << "withdrawals:" << getNbWithdrawals() 
        << std::endl;
}

void Account::makeDeposit( int deposit ) {
    int p_amount = _amount;
    _amount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    _totalAmount += deposit;

    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "p_amount:" << p_amount << ";" 
        << "deposit:" << deposit << ";"
        << "amount:" << _amount << ";"
        << "nb_deposits:" << _nbDeposits
        << std::endl;
}

bool Account::makeWithdrawal( int withdrawal ) {
    int p_amount = _amount;
    
    if (withdrawal < _amount) {
        _amount -= withdrawal;
        _nbWithdrawals++;
        _totalNbWithdrawals++;
        _totalAmount -= withdrawal;

        _displayTimestamp();
        std::cout
            << "index:" << _accountIndex << ";"
            << "p_amount:" << p_amount << ";" 
            << "withdrawal:" << withdrawal << ";"
            << "amount:" << _amount << ";"
            << "nb_withdrawals:" << _nbWithdrawals
            << std::endl;
        return (true);
    }
    else {

        _displayTimestamp();
        std::cout
            << "index:" << _accountIndex << ";"
            << "p_amount:" << p_amount << ";" 
            << "withdrawal:refused"
            << std::endl;
    }
    return (false);
}

int	Account::checkAmount( void ) const {
    return _amount;
}

void Account::displayStatus( void ) const {
    _displayTimestamp();
    std::cout
        << "index:" << _accountIndex << ";"
        << "amount:" << _amount << ";" 
        << "deposits:" << _nbDeposits << ";"
        << "withdrawals:" << _nbWithdrawals
        << std::endl;
}