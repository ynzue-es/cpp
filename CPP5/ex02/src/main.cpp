/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 01:51:03 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 01:00:08 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned>(std::time(NULL)));

    Bureaucrat boss("Alice", 1);
    Bureaucrat worker("Bob", 140);

    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Arthur Dent");

    std::cout << "[INFO] " << boss << std::endl;
    std::cout << "[INFO] " << worker << std::endl;

    std::cout << "\n=== Signing phase ===" << std::endl;
    worker.signForm(shrub);
    worker.signForm(robot);
    boss.signForm(robot);
    boss.signForm(pardon);

    std::cout << "\n=== Execution phase ===" << std::endl;
    worker.executeForm(shrub);
    boss.executeForm(shrub);
    boss.executeForm(robot);
    boss.executeForm(pardon);

    std::cout << "\n=== Not signed case ===" << std::endl;
    ShrubberyCreationForm unsignedForm("garden");
    boss.executeForm(unsignedForm);

    return 0;
}
