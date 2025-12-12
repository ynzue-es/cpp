/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:29:19 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:19:43 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"
#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>

int main()
{
    const Animal* animal = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();
    animal->makeSound();

    const WrongAnimal* animalFake = new WrongAnimal();
    const WrongAnimal* catFake = new WrongCat();
    std::cout << i->getType() << " " << std::endl;
    catFake->makeSound();
    animalFake->makeSound();

    delete animal;
    delete j;
    delete i;

    delete animalFake;
    delete catFake;
    
    return 0;
}