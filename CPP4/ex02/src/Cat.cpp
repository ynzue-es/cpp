/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:43:54 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:44:38 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat() : AAnimal() {
    std::cout << "Cat constructor called" << std::endl;
    setType("Cat");
    _brain = new Brain();
}

Cat::Cat(Cat const & src) : AAnimal(src), _brain(new Brain(*src._brain)) {
    std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

Cat& Cat::operator=(Cat const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        AAnimal::operator=(rhs);
        Brain *newBrain = new Brain(*rhs._brain);
        delete _brain;
        _brain = newBrain;
    }
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "Miaouw" << std::endl;
};