/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:43:54 by yannis            #+#    #+#             */
/*   Updated: 2025/09/01 18:11:25 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"
#include <iostream>

Cat::Cat() : Animal() {
    std::cout << "Cat constructor called" << std::endl;
    setType("Cat");
    _brain = new Brain();
}

Cat::Cat(Cat const & src) : Animal(src), _brain(new Brain(*src._brain)) {
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
        Animal::operator=(rhs);
        Brain *newBrain = new Brain(*rhs._brain);
        delete _brain;
        _brain = newBrain;
    }
    return *this;
}

void Cat::makeSound( void ) const {
    std::cout << "Miaouw" << std::endl;
};