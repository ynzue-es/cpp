/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:49:54 by yannis            #+#    #+#             */
/*   Updated: 2025/07/26 20:16:33 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>

PhoneBook::PhoneBook()
{
    std::cout << "PhoneBook create" << std::endl;
};

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook destroy" << std::endl;
}
