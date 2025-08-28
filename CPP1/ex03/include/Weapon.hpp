/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:44:21 by yannis            #+#    #+#             */
/*   Updated: 2025/08/28 07:52:07 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
#define WEAPON_H

#include <string>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(std::string const & type);
        ~Weapon();

        std::string getType();
        void setType(std::string const & type);
};

#endif