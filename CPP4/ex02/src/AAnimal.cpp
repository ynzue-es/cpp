/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:25:45 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:41:28 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"
#include <iostream>

AAnimal::AAnimal() {
    std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const & src) {
    std::cout << "Animal copy constructor called" << std::endl;
    *this = src;
}

AAnimal::~AAnimal() {
    std::cout << "Animal destructor called" << std::endl;
}

AAnimal& AAnimal::operator=(AAnimal const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

std::string AAnimal::getType() const{
    return _type;
}

void AAnimal::setType(std::string const & type) {
    _type = type;
}