/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:04:22 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:24:00 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include <iostream>

WrongAnimal::WrongAnimal() {
    std::cout << "WrongAnimal constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & src) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    *this = src;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & rhs) {
    std::cout << "WrongAnimal copy assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

void WrongAnimal::makeSound( void ) const {
    std::cout << "WrongAnimals can make lot of songs" << std::endl;
};

std::string WrongAnimal::getType() const{
    return _type;
}

void WrongAnimal::setType(std::string const & type) {
    _type = type;
}