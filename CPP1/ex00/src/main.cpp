/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:46:48 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 21:24:03 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main() {
    randomChump("Zombie1");
    
    Zombie *zombie1 = newZombie("Zombie2");
    zombie1->announce();
    delete zombie1;

    return (0);
}