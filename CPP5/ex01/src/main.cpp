/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 01:51:03 by yannis            #+#    #+#             */
/*   Updated: 2025/12/16 02:07:36 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include <iostream>

int main() {

    std::cout << "=== Normal cases ===" << std::endl;
    {
        std::cout << "[TEST] Create Bureaucrat and valid Form" << std::endl;
        Bureaucrat bob("Bob", 10);
        Form formA("FormA", 20, 30);

        std::cout << "[INFO] " << bob << std::endl;
        std::cout << "[INFO] " << formA << std::endl;

        std::cout << "[TEST] Bob signs FormA" << std::endl;
        bob.signForm(formA);
        std::cout << "[OK] " << formA << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Edge cases ===" << std::endl;
    {
        std::cout << "[TEST] Bureaucrat at signing limit" << std::endl;
        Bureaucrat alice("Alice", 50);
        Form formB("FormB", 50, 10);

        std::cout << "[INFO] " << alice << std::endl;
        std::cout << "[INFO] " << formB << std::endl;

        std::cout << "[TEST] Alice signs FormB (exact grade)" << std::endl;
        alice.signForm(formB);
        std::cout << "[OK] " << formB << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Failure cases ===" << std::endl;
    {
        std::cout << "[TEST] Bureaucrat grade too low to sign" << std::endl;
        Bureaucrat tom("Tom", 100);
        Form formC("FormC", 50, 10);

        std::cout << "[INFO] " << tom << std::endl;
        std::cout << "[INFO] " << formC << std::endl;

        tom.signForm(formC);
        std::cout << "[INFO] " << formC << std::endl;
    }
    std::cout << std::endl;

    std::cout << "=== Invalid cases ===" << std::endl;
    {
        std::cout << "[TEST] Create Form with grade too high" << std::endl;
        try {
            Form badForm1("BadForm1", 0, 10);
            std::cout << "[FAIL] No exception thrown" << std::endl;
        }
        catch (const Form::GradeTooHighException & e) {
            std::cerr << "[OK] Exception caught: " << e.what() << std::endl;
        }

        std::cout << "[TEST] Create Form with grade too low" << std::endl;
        try {
            Form badForm2("BadForm2", 10, 200);
            std::cout << "[FAIL] No exception thrown" << std::endl;
        }
        catch (const Form::GradeTooLowException & e) {
            std::cerr << "[OK] Exception caught: " << e.what() << std::endl;
        }
    }

    return 0;
}