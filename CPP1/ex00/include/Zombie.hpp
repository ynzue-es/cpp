/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:47:01 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 15:33:30 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP
#include <string>

class Zombie {
    private:
        std::string _name;

    public:
        Zombie(const std::string& name);
        ~Zombie();

        void announce( void );
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif