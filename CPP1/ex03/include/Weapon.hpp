/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 21:44:21 by yannis            #+#    #+#             */
/*   Updated: 2025/11/28 13:21:52 by ynzue-es         ###   ########.fr       */
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

        const std::string& getType() const;
        void setType(std::string const & type);
};

#endif