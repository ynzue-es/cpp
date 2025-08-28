/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:42:23 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 22:56:54 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"
#include <iostream>
#include <string>

HumanB::HumanB(std::string const & name) : _name(name), _weapon(NULL) {};
HumanB::~HumanB() {};

void HumanB::attack() {
    if (_weapon)
        std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
    else
        std::cout << _name << " has no weapon" << std::endl;
}

void HumanB::setWeapon(Weapon & weapon) {
    _weapon = &weapon;
}