/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:29:19 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:37:52 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/Brain.hpp"
#include <iostream>

int main()
{
    const Animal* animals[4];

    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Dog();
    animals[3] = new Cat();

    for (int i = 0; i < 4; i++) {
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; i++)
        delete animals[i];

    Dog dog1;
    {
        Dog dog2 = dog1;
    }

    Dog dog3;
    dog3 = dog1;

    return 0;
}