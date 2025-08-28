/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 09:41:26 by yannis            #+#    #+#             */
/*   Updated: 2025/08/28 11:23:38 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../include/Harl.class.hpp"

int main(int argc, char **argv) {
    if (argc != 2)
    {
        std::cout << "Usage : ./harlFilter {DEBUG, INFO, WARNING, ERROR}" << std::endl;
        return (1);
    }

    Harl harl;
    harl.complain(std::string(argv[1]));
}