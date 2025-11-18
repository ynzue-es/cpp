/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:50:03 by yannis            #+#    #+#             */
/*   Updated: 2025/08/28 10:30:39 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
