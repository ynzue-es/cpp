/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 19:35:16 by yannis            #+#    #+#             */
/*   Updated: 2025/12/09 09:11:32 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

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