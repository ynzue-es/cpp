/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:46:48 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 15:38:28 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    randomChump("Yannis");
    
    Zombie *zombie1 = newZombie("Helias");
    zombie1->announce();
    delete zombie1;

    return (0);
}