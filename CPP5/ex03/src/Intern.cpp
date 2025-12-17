/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:54:45 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 00:28:25 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Intern.hpp"

Intern::Intern() {}

Intern::Intern(Intern const & src) {}

Intern & Intern::operator=(Intern const & rhs) {
    if (this != &rhs) {
        *this = rhs; 
    }
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target) {
    std::cout << "Intern creates " << name << std::endl;
}