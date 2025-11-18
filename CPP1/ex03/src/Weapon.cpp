/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:42:28 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 22:30:04 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(std::string const & type) : _type(type) {};
Weapon::~Weapon() {};

std::string Weapon::getType() {
    return _type;
}

void Weapon::setType(std::string const & type) {
    _type = type;
}