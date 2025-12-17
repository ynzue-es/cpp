/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 01:51:03 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 00:29:47 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Intern.hpp"
#include "../includes/AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned>(std::time(NULL)));

    Intern intern;
    Bureaucrat boss("Alice", 1);

    AForm* forms[4];
    forms[0] = intern.makeForm("shrubbery creation", "home");
    forms[1] = intern.makeForm("robotomy request", "Bender");
    forms[2] = intern.makeForm("presidential pardon", "Ford");
    forms[3] = intern.makeForm("unknown", "nobody");

    for (int i = 0; i < 4; ++i) {
        if (!forms[i])
            continue;
        boss.signForm(*forms[i]);
        boss.executeForm(*forms[i]);
    }

    for (int i = 0; i < 4; ++i)
        delete forms[i];

    return 0;
}
