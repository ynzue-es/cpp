/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:59:06 by yannis            #+#    #+#             */
/*   Updated: 2025/08/30 10:56:03 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
    
public:
    ScavTrap( std::string const & name );
    ScavTrap(ScavTrap const & src);
    ~ScavTrap( void );

    ScavTrap& operator=(ScavTrap const & rhs);

    void attack(const std::string& target);
    void guardGate();
};

#endif