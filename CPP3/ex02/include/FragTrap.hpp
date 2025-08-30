/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 11:41:57 by yannis            #+#    #+#             */
/*   Updated: 2025/08/30 11:50:06 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
    
public:
    FragTrap( std::string const & name );
    FragTrap(FragTrap const & src);
    ~FragTrap( void );

    FragTrap& operator=(FragTrap const & rhs);
    
    void highFivesGuys( void );
};

#endif