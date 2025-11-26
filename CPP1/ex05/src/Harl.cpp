/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:27:25 by ynzue-es          #+#    #+#             */
/*   Updated: 2025/11/26 11:27:27 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include "Harl.hpp"
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
    const std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    void (Harl::*funcs[])() = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
    
    size_t n = sizeof(levels) / sizeof(levels[0]);
    for (size_t i = 0; i < n; i++)
    {
        if (level == levels[i]) {
            (this->*funcs[i])();
            return;
        }
    }
}

#endif