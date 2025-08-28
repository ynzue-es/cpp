/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:41:30 by yannis            #+#    #+#             */
/*   Updated: 2025/08/28 11:19:28 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.class.hpp"
#include <string>
#include <iostream>

Harl::Harl() {}
Harl::~Harl() {}

void Harl::_debug() {
    std::cout << "[ DEBUG ]\n"
              << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!\n";
}

void Harl::_info() {
    std::cout << "[ INFO ]\n"
              << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void Harl::_warning() {
    std::cout << "[ WARNING ]\n"
              << "I think I deserve to have some extra bacon for free. I've been coming for years whereas you started working here since last month.\n";
}

void Harl::_error() {
    std::cout << "[ ERROR ]\n"
              << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain( std::string level ) {
    const std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    size_t i = 0;

    while (i < 4)
    {
        if (level == levels[i])
            break;
        i++;
    }
    
    switch (i) {
        case 0:
            _debug();
            /* fall through */
        case 1:
            _info();
            /* fall through */
        case 2:
            _warning();
            /* fall through */
        case 3:
            _error();
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}