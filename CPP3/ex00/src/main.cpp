/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:02:47 by yannis            #+#    #+#             */
/*   Updated: 2025/08/30 09:51:38 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include <iostream>

int main() {
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    std::cout << std::endl;
    a.attack("Bravo");   // Alpha attaque Bravo (juste un affichage)
    b.takeDamage(3);     // Bravo perd 3 HP
    std::cout << std::endl;
    b.attack("Alpha");   // Bravo attaque Alpha
    a.takeDamage(5);     // Alpha perd 5 HP
    std::cout << std::endl;
    a.beRepaired(4);     // Alpha se soigne de 4 HP
    b.beRepaired(2);     // Bravo se soigne de 2 HP
    std::cout << std::endl;
    // Pour tester la copie
    ClapTrap c(a);       // constructeur de copie
    ClapTrap d("Delta");
    d = b;               // opérateur d’affectation
    std::cout << std::endl;

    return 0;
}