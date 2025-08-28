/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:44:27 by yannis            #+#    #+#             */
/*   Updated: 2025/08/28 07:49:24 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
#define HUMAN_A_HPP

#include "Weapon.hpp"
#include <string>

class HumanA
{
    private:
        std::string _name;
        Weapon& _weapon;
        
    public:
        HumanA(std::string const & name, Weapon & weapon);
        ~HumanA();

        void attack();
};

#endif