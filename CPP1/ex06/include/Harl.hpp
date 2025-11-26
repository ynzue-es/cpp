/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:27:46 by ynzue-es          #+#    #+#             */
/*   Updated: 2025/11/26 11:27:48 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl
{
    private:
        void _debug( void );
        void _info( void );
        void _warning( void );
        void _error( void );
        
    public:
        Harl();
        ~Harl();

        void complain( std::string level );
};

#endif