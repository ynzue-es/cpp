/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:02:09 by yannis            #+#    #+#             */
/*   Updated: 2025/08/30 09:20:56 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class ClapTrap
{
    private:
        std::string _name;
        int _hitPoints;
        int _energyPoints;
        int _attackDamage;
        
        
    public:
        ClapTrap( std::string const & name );
        ClapTrap( ClapTrap const & src);
        ~ClapTrap( void );

        ClapTrap& operator=(ClapTrap const & rhs);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};
