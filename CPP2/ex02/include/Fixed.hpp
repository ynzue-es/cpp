/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:35:16 by yannis            #+#    #+#             */
/*   Updated: 2025/08/29 16:20:36 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

// cette classe permet de créer un float à partir d'int
class Fixed
{
    private:

        int                 _rawBits;
        static const int    _fractionalBits = 8; 
        
    public:
        Fixed( void );
        Fixed( int const n );
        Fixed( float const f );
        Fixed( Fixed const & src );
        ~Fixed( void );
        
        // affectation
        Fixed& operator=(Fixed const & rhs);
        
        // comparaison
        bool operator>(Fixed const & rhs) const;
        bool operator<(Fixed const & rhs) const;
        bool operator<=(Fixed const & rhs) const;
        bool operator>=(Fixed const & rhs) const;
        bool operator==(Fixed const & rhs) const;
        bool operator!=(Fixed const & rhs) const;
        
        // incrémentation
        Fixed& operator++();
        Fixed operator++(int);
        Fixed& operator--();
        Fixed operator--(int);

        int  getRawBits( void ) const;
        void setRawBits( int const raw );
        int toInt( void ) const;
        float toFloat( void ) const;

        static Fixed& min(Fixed & f1, Fixed & f2);
        static Fixed& max(Fixed & f1, Fixed & f2);
        static Fixed& min(Fixed const & f1, Fixed const & f2);
        static Fixed& max(Fixed const & f1, Fixed const & f2);
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif