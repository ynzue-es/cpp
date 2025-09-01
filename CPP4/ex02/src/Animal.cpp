/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:25:45 by yannis            #+#    #+#             */
/*   Updated: 2025/09/01 20:41:41 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal constructor called" << std::endl;
}

// copie par construction
Animal::Animal(Animal const & src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}

// copy par affectation
Animal& Animal::operator=(Animal const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

std::string Animal::getType() const{
    return _type;
}

void Animal::setType(std::string const & type) {
    _type = type;
}