/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:44:40 by yannis            #+#    #+#             */
/*   Updated: 2025/12/16 02:10:22 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include <string>
#include <iostream>

int main() {

    std::cout << "=== Normal cases ===" << std::endl;
    {
        std::cout << "[TEST] Bernard, grade 10 -> increment 5 times" << std::endl;
        Bureaucrat b1("Bernard", 10);

        for (int i = 0; i < 5; i++)
            b1.incrementGrade();
        std::cout << "[OK] " << b1 << std::endl;

        for (int i = 0; i < 5; i++)
            b1.decrementGrade();
        std::cout << "[OK] " << b1 << std::endl;

        std::cout << "[TEST] Bernard -> decrement 5 times" << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Edge cases ===" << std::endl;
    {
        std::cout << "[TEST] Michel, grade 1 -> increment (should throw)" << std::endl;
        Bureaucrat b2("Michel", 1);
        try {
            b2.incrementGrade();
            std::cout << "[FAIL] No exception thrown" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "[OK] Exception caught: " << e.what() << std::endl;
        }
        std::cout << b2 << std::endl;

        std::cout << "[TEST] Arnaud, grade 150 -> decrement (should throw)" << std::endl;
        Bureaucrat b3("Arnaud", 150);
        try {
            b3.decrementGrade();
            std::cout << "[FAIL] No exception thrown" << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "[OK] Exception caught: " << e.what() << std::endl;
        }
        std::cout << b3 << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Invalid cases (constructor) ===" << std::endl;
    {
        std::cout << "[TEST] Create with grade 0" << std::endl;
        try {
            Bureaucrat b4("Jacques", 0);
            std::cout << "[FAIL] No exception thrown" << std::endl;
        }
        catch (const Bureaucrat::GradeTooHighException& e) {
            std::cerr << "[OK] Exception caught: " << e.what() << std::endl;
        }

        std::cout << "[TEST] Create with grade 200" << std::endl;
        try {
            Bureaucrat b5("Robert", 200);
            std::cout << "[FAIL] No exception thrown" << std::endl;
        }
        catch (const Bureaucrat::GradeTooLowException& e) {
            std::cerr << "[OK] Exception caught: " << e.what() << std::endl;
        }
    }

    return 0;
}