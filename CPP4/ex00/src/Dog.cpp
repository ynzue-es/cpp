/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:32:55 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 09:38:08 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog() : Animal() {
    std::cout << "Dog constructor called" << std::endl;
    setType("Dog");
}

Dog::Dog(Dog const & src) : Animal(src) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = src;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(Dog const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "Wouf" << std::endl;
};