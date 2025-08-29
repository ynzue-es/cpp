/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:35:16 by yannis            #+#    #+#             */
/*   Updated: 2025/08/29 13:38:58 by yannis           ###   ########.fr       */
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
        Fixed& operator=(Fixed const & rhs);
        ~Fixed( void );

        int  getRawBits( void ) const;
        void setRawBits( int const raw );

        int toInt( void ) const;
        float toFloat( void ) const;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif