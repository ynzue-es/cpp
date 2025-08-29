/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:35:35 by yannis            #+#    #+#             */
/*   Updated: 2025/08/29 13:15:06 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>

Fixed::Fixed( void ) {
    std::cout << "Default constructor called" << std::endl;
    _rawBits = 0;
    return;
}

Fixed::Fixed( Fixed const & src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
    return;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
    return;
}

Fixed& Fixed::operator=(Fixed const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_rawBits = rhs.getRawBits();
    return (*this);
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}