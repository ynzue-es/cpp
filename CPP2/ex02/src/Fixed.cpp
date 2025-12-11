/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:35:35 by yannis            #+#    #+#             */
/*   Updated: 2025/12/09 11:50:19 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed( void ) : _rawBits(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed( int const n ) {
    std::cout << "Int constructor called" << std::endl;
    _rawBits = n << _fractionalBits;
}

Fixed::Fixed( float const f ) {
    std::cout << "Float constructor called" << std::endl;
    _rawBits = roundf(f * (1 << _fractionalBits));
}

Fixed::Fixed( Fixed const & src ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

// assignation
Fixed& Fixed::operator=(Fixed const & rhs) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->_rawBits = rhs.getRawBits();
    return (*this);
}

// comparaison
bool Fixed::operator>(Fixed const & rhs) const {
    return this->getRawBits() > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const & rhs) const {
    return this->getRawBits() < rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const & rhs) const {
    return this->getRawBits() <= rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const & rhs) const {
    return this->getRawBits() >= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const & rhs) const {
    return this->getRawBits() == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const & rhs) const {
    return this->getRawBits() != rhs.getRawBits();
}

int Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return _rawBits;
}

// arithmetique
Fixed Fixed::operator+(Fixed const & rhs) const {
    return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const & rhs) const {
    return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const & rhs) const {
    return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const & rhs) const {
    return Fixed(this->toFloat() / rhs.toFloat());
}

// incrémentation
Fixed& Fixed::operator++(){
    ++_rawBits;
    return *this;
}

Fixed& Fixed::operator--() {
    --_rawBits;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    _rawBits++;
    return tmp;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    _rawBits--;
    return (tmp);
}

void Fixed::setRawBits( int const raw ) {
    std::cout << "setRawBits member function called" << std::endl;
    _rawBits = raw;
}

int Fixed::toInt( void ) const {
    return _rawBits >> _fractionalBits;
}

float Fixed::toFloat( void ) const {
    return (float)_rawBits / (1 << _fractionalBits);
}

std::ostream & operator<<(std::ostream & o, Fixed const & rhs) {
    o << rhs.toFloat();
    return o;
}

Fixed& Fixed::min(Fixed & f1, Fixed & f2) {
    return (f1 < f2 ? f1 : f2);
}

Fixed& Fixed::max(Fixed & f1, Fixed & f2) {
    return (f1 > f2 ? f1 : f2);
}

Fixed const & Fixed::min(Fixed const & f1, Fixed const & f2) {
    return (f1 < f2 ? f1 : f2);
}

Fixed const & Fixed::max(Fixed const & f1, Fixed const & f2) {
    return (f1 > f2 ? f1 : f2);
}