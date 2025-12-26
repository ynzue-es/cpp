/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:45:56 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 15:28:31 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

int main(int argc, char **argv) {
    
    // ./convert a
    // ./convert 42
    // ./convert 4.2
    // ./convert 4.2f
    // ./convert nan
    // ./convert nanf
    // ./convert +inf
    // ./convert -inff
    // ./convert 2147483648
    // ./convert .
    // ./convert 4f
    // ./convert ++444

    if (argc != 2)
    {
        std::cout << "Usage: ./convert <str>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}