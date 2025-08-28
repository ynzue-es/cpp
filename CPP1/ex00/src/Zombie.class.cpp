/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:46:46 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 21:23:55 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"
#include <iostream>

Zombie::Zombie(const std::string& name) {
    _name = name;
}

Zombie::~Zombie() {
    std::cout << _name << " is destroyed." << std::endl;
}

void Zombie::announce( void ) {
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}