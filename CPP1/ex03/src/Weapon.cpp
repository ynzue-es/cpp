/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:42:28 by yannis            #+#    #+#             */
/*   Updated: 2025/12/04 11:20:14 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string const & type) : _type(type) {};
Weapon::~Weapon() {};

const std::string& Weapon::getType() const {
    return _type;
}

void Weapon::setType(std::string const & type) {
    _type = type;
}