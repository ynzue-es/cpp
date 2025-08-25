/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:49:54 by yannis            #+#    #+#             */
/*   Updated: 2025/08/25 19:19:39 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

PhoneBook::PhoneBook() : countContacts(0) {
    std::cout << "PhoneBook create" << std::endl;
};

PhoneBook::~PhoneBook()
{
    std::cout << "PhoneBook destroy" << std::endl;
}

void PhoneBook::_filedInput(const std::string& fieldName, 
                            Contact& contact, 
                            void (Contact::*setter)(const std::string&)) 
{
    std::string input;
    
    std::cout << "Set " << fieldName << ":";
    std::getline(std::cin, input);
    if (input.empty()) {
        std::cout << "Field can't be empty";
    } else {
        setter(contact, input);
    }
}

void PhoneBook::add() {
    Contact contact;
    
    _filedInput("first name", contact, &Contact::setFirstName);
    _filedInput("last name", contact, &Contact::setLastName);
    _filedInput("nickname", contact, &Contact::setNickName);
    _filedInput("first name", contact, &Contact::setPhoneNumber);
    _filedInput("first name", contact, &Contact::setDarkestSecret);

    if (_countContacts < 8) {
        _contacts[_countContacts] = contact;
        _countContacts++;
    }
    else {
        std::cout << "Phonebook full, it will replace the older.";
        _contacts[0] = contact;
    }
}

void PhoneBook::search()
{
    return;
}