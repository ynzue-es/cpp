/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:30:13 by yannis            #+#    #+#             */
/*   Updated: 2025/12/27 00:02:04 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/iter.hpp"

void increment(int & x) {
    x++;
}

void printInt(int const & x) {
    std::cout << x << std::endl;
}

int main()
{
    // ----- Test NON CONST -----
    int arr[] = {1, 2, 3};

    std::cout << "Non-const array :" << std::endl;
    iter(arr, 3, increment);

    std::cout << "After increment:" << std::endl;
    iter(arr, 3, printInt);

    std::cout << std::endl;

    // ----- Test CONST -----
    const int constArr[] = {10, 20, 30};

    std::cout << "Const array (print only):" << std::endl;
    iter(constArr, 3, printInt);

    // Don't work because try to increment CONST array
    //iter(constArr, 3, increment);

    return 0;
}