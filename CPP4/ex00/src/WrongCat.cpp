/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:05:20 by yannis            #+#    #+#             */
/*   Updated: 2025/09/01 16:40:58 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include <iostream>

WrongCat::WrongCat() : WrongAnimal() {
    std::cout << "WrongCat constructor called" << std::endl;
    setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(src) {
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = src;
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat& WrongCat::operator=(WrongCat const & rhs) {
    std::cout << "WrongAnimal copy constructor called" << std::endl;
    if (this != &rhs)
        _type = rhs._type;
    return *this;
}

void WrongCat::makeSound( void ) const {
    std::cout << "Fake Miaouuuuw" << std::endl;
};