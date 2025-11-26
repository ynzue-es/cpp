/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:36:32 by ynzue-es          #+#    #+#             */
/*   Updated: 2025/11/26 13:36:33 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"
#include <iostream>
#include <string>

HumanA::HumanA(std::string const & name, Weapon & weapon) : _name(name), _weapon(weapon) {}
HumanA::~HumanA() {}

void HumanA::attack() {
    std::cout << _name 
    << " attacks with their " 
    << _weapon.getType() << std::endl;
}