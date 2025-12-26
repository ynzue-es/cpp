/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:30:13 by yannis            #+#    #+#             */
/*   Updated: 2025/12/27 00:07:45 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Array.hpp"

int main()
{
    std::cout << "----- Default constructor -----" << std::endl;
    Array<int> empty;
    std::cout << "Size: " << empty.size() << std::endl;

    std::cout << "\n----- Constructor with size -----" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < a.size(); ++i)
        a[i] = i * 10;

    for (unsigned int i = 0; i < a.size(); ++i)
        std::cout << "a[" << i << "] = " << a[i] << std::endl;

    std::cout << "\n----- Out of bounds test -----" << std::endl;
    try {
        std::cout << a[10] << std::endl;
    } catch (std::exception& e) {
        std::cout << "Exception caught!" << std::endl;
    }

    std::cout << "\n----- Copy constructor (deep copy) -----" << std::endl;
    Array<int> b(a);
    b[0] = 999;

    std::cout << "a[0] = " << a[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "\n----- Assignment operator -----" << std::endl;
    Array<int> c;
    c = a;
    c[1] = 888;

    std::cout << "a[1] = " << a[1] << std::endl;
    std::cout << "c[1] = " << c[1] << std::endl;

    std::cout << "\n----- Const array access -----" << std::endl;
    const Array<int> constArr(a);
    std::cout << "constArr[2] = " << constArr[2] << std::endl;

    // Don't work because CONST array
    // constArr[2] = 42;

    std::cout << "\n----- Array<std::string> -----" << std::endl;
    Array<std::string> s(3);
    s[0] = "Hello";
    s[1] = "CPP";
    s[2] = "Templates";

    for (unsigned int i = 0; i < s.size(); ++i)
        std::cout << s[i] << std::endl;

    return 0;
}