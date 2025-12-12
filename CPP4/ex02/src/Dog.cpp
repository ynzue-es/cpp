/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:32:55 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:44:49 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include <iostream>

Dog::Dog() : AAnimal() {
    std::cout << "Dog constructor called" << std::endl;
    setType("Dog");
    _brain = new Brain();
}

Dog::Dog(Dog const & src) : AAnimal(src), _brain(new Brain(*src._brain)) {
    std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}

Dog& Dog::operator=(Dog const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        AAnimal::operator=(rhs);
        Brain* newBrain = new Brain(*rhs._brain);
        delete _brain;
        _brain = newBrain;
    }
    return *this;
}

void Dog::makeSound( void ) const {
    std::cout << "Wouf" << std::endl;
};