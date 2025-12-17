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
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern() {}

Intern::Intern(Intern const & src) {
    (void)src;
}

Intern & Intern::operator=(Intern const & rhs) {
    (void)rhs;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::makeForm(std::string name, std::string target) {
    if (name == "shrubbery creation") {
        std::cout << "Intern creates " << name << std::endl;
        return new ShrubberyCreationForm(target);
    }
    if (name == "robotomy request") {
        std::cout << "Intern creates " << name << std::endl;
        return new RobotomyRequestForm(target);
    }
    if (name == "presidential pardon") {
        std::cout << "Intern creates " << name << std::endl;
        return new PresidentialPardonForm(target);
    }
    std::cout << "Intern can't create form \"" << name << "\"" << std::endl;
    return NULL;
}
