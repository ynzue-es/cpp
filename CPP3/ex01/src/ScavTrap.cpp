/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:59:15 by yannis            #+#    #+#             */
/*   Updated: 2025/08/30 10:50:34 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap( std::string const & name ) : ClapTrap(name){
    std::cout << "ScavTrap constructor called" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = src;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        _name =         rhs._name;
        _hitPoints =    rhs._hitPoints;
        _energyPoints = rhs._energyPoints;
        _attackDamage = rhs._attackDamage;
    }
    return *this;
}

void ScavTrap::attack(const std::string& target) {
    if (_hitPoints <= 0 || _energyPoints <= 0) {
        std::cout << "ScavTrap " << _name << " cannot attack." << std::endl;
        return;
    }
    std::cout << "ScavTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!" << std::endl;
    _energyPoints--;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap is now in Gate keeper mode" << std::endl;
}