/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 19:35:30 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 20:20:36 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie* newZombie() {
    Zombie *zombie = new Zombie();
    return zombie;
}

Zombie* zombieHorde( int N, std::string name ) {
    Zombie *zombies = new Zombie[N];

    for (int i = 0; i < N; i++) {
        zombies[i].setName(name);
        zombies[i].announce();
    }
    return (zombies);
}