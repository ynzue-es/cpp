/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:47:07 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 08:31:57 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <csignal>
#include <cstdlib>
#include "PhoneBook.hpp"

void signalHandler(int signum) {
    std::cout << "\nInterruption reçue (Ctrl+C). Fermeture du programme 👋" << std::endl;
    exit(signum);
}

int main()
{
    std::signal(SIGINT, signalHandler);

    PhoneBook phonebook;
    std::cout << "Welcome in your phonebook ☎️" << std::endl;

    while (true)
    {
        std::string input;
        std::cout << "Choose one command (ADD, SEARCH or EXIT) : ";

        if (!std::getline(std::cin, input)) {
            std::cout << "\nBye 👋" << std::endl;
            break;
        }

        if (input == "ADD") {
            phonebook.add();
        } else if (input == "SEARCH") {
            phonebook.search();
        } else if (input == "EXIT") {
            std::cout << "See you soon 👋" << std::endl;
            break;
        } else {
            std::cout << "Wrong input, retry ❌" << std::endl;
        }
    }
    
}