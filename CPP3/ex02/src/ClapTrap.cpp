/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:02:23 by yannis            #+#    #+#             */
/*   Updated: 2025/08/30 09:50:18 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap( std::string const & name ) 
: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(10) {
    std::cout << "ClapTrap constructor called" << std::endl;
};

ClapTrap::ClapTrap( ClapTrap const & src) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = src;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
};

ClapTrap& ClapTrap::operator=(ClapTrap const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->_name =         rhs._name;
        this->_hitPoints =    rhs._hitPoints;
        this->_energyPoints = rhs._energyPoints;
        this->_attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot attack." << std::endl;
        return;
    }
    std::cout << "ClapTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (_hitPoints <= 0) {
        std::cout << "ClapTrap " << _name << " is already destroyed." << std::endl;
        return;
    }
    _hitPoints -= amount;
    if (_hitPoints < 0) 
        _hitPoints = 0;
    std::cout << "ClapTrap " << _name 
              << " took " << amount 
              << " points of damage! HP left: " << _hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ClapTrap " << _name << " cannot repair itself." << std::endl;
        return;
    }
    _hitPoints += amount;
    _energyPoints--;
    std::cout << "ClapTrap " << _name 
              << " repaired itself for " << amount 
              << " HP! Total HP: " << _hitPoints << std::endl;
}