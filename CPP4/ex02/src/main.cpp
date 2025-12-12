/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:29:19 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:42:41 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Brain.hpp"
#include <iostream>

int main()
{
    //AAnimal a; impossible !!!
    
    const AAnimal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++)
        animals[i]->makeSound();

    for (int i = 0; i < 4; i++)
        delete animals[i];

    Dog basic;
    {
        Dog tmp = basic;
    }

    return 0;
}