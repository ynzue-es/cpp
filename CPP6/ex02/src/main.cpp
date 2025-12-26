/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:45:56 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 19:32:39 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "../includes/Base.hpp"

int main()
{
    std::srand(std::time(NULL));
    Base* ptr = generate();
    std::cout << "Identify using pointer: ";
    identify(ptr);
    std::cout << "Identify using reference: ";
    identify(*ptr);
    delete ptr;
    return 0;
}
