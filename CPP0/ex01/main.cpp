/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:47:07 by yannis            #+#    #+#             */
/*   Updated: 2025/08/25 18:08:21 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Include/Contact.hpp" 
#include "Include/PhoneBook.hpp"



int main()
{
    PhoneBook phonebook;
    
    std::string input;

    std::cout << "Choose one command (ADD, SEARCH or EXIT) : ";
    std::getline(std::cin, input);

    if (input == "ADD") {
        phonebook.add();
    } else if (input == "SEARCH") {
        phonebook.search();
    } else if (input == "EXIT") {
        std::cout << "You quit this session ";
        exit(0);
    } else {
        std::cout << "Wrong input, retry.";
        std::getline(std::cin, input);
    }
     
}