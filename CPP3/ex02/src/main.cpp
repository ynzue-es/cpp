/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/30 09:02:47 by yannis            #+#    #+#             */
/*   Updated: 2025/08/30 11:56:57 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/ScavTrap.hpp"
#include "../include/FragTrap.hpp"
#include <iostream>

int main() {

    //test exo 00
    ClapTrap a("Alpha");
    ClapTrap b("Bravo");

    std::cout << std::endl;
    a.attack("Bravo");
    b.takeDamage(3);
    std::cout << std::endl;
    b.attack("Alpha");
    a.takeDamage(5);
    std::cout << std::endl;
    a.beRepaired(4);
    b.beRepaired(2);
    std::cout << std::endl;

    // test exo 01
    ScavTrap c("Charlie");
    c.takeDamage(10);
    
    c.attack("Random");
    c.guardGate();

    //test exo 02
    FragTrap d("Delta");
    d.highFivesGuys(); 

    return 0;
}