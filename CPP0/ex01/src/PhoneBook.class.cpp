/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:49:54 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 09:22:04 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

PhoneBook::PhoneBook() : _countContacts(0) {};
PhoneBook::~PhoneBook() {};

static int check_phone_number(const std::string& input)
{
    if (input.length() != 10)
    {
        std::cout << "Phone Number is 10 numbers..." << std::endl;
        return (1);
    }
    for (int i = 0; i < (int)input.length(); i++)
    {
        if (input[i] < 48 || input[i] > 57)
        {
            std::cout << "You can put only numbers..." << std::endl;
            return (1);
        }
    }
    return (0);
}

static int check_name(const std::string& input)
{
    for (int i = 0; i < (int)input.length(); i++)
    {
        if ((input[i] < 'a' || input[i] > 'z') 
            && (input[i] < 'A' || input[i] > 'Z') 
            && input[i] != ' ')
        {
            std::cout << "You can put only letters..." << std::endl;
            return (1);
        }
    }
    return (0);
}

int PhoneBook::_filedInput(const std::string& fieldName, 
                            Contact& contact, 
                            void (Contact::*setter)(const std::string&)) 
{
    std::string input;
    std::cout << "Set " << fieldName << " : ";
    std::getline(std::cin, input);
    if (input.empty())
        std::cout << "Field can't be empty";
    else
    {
        if (fieldName == "first name" || fieldName == "last name")
        {
            if (check_name(input))
                return (1);
        }      
        if (fieldName == "phone number")
        {
            if (check_phone_number(input))
                return (1);
        }
        (contact.*setter)(input);
    }
    return (0);
}

void PhoneBook::add() {
    Contact contact;
    bool valid_phone_nb = false;
    bool valid_first_name = false;
    bool valid_last_name = false;
    static int older = 0;
    
    while (!valid_first_name)
    {
        if (_filedInput("first name", contact, &Contact::setFirstName))
            continue;
        valid_first_name = true;
    }
    while (!valid_last_name)
    {
        if (_filedInput("last name", contact, &Contact::setLastName))
            continue;
        valid_last_name = true;
    }
    _filedInput("nickname", contact, &Contact::setNickName);
    while (!valid_phone_nb)
    {
        if (_filedInput("phone number", contact, &Contact::setPhoneNumber))
            continue;
        valid_phone_nb = true;
    }
    _filedInput("darkest secret", contact, &Contact::setDarkestSecret);

    if (_countContacts < 8) {
        _contacts[_countContacts] = contact;
        _countContacts++;
    }
    else {
        std::cout << "Phonebook full, it will replace the older." << std::endl;
        _contacts[older] = contact;
        older = (older + 1) % 8;
    }
}

std::string formatColumn(const std::string& str, size_t width = 10) {
    if (str.length() > width) {
        return str.substr(0, width - 1) + ".";
    } else {
        return str;
    }
}

bool isNumber(const std::string& str) {
    if (str.empty())
        return false;

    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]))
            return false;
    }
    return true;
}

void PhoneBook::search()
{
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "|" << std::setw(10) << "Index"
                << "|" << std::setw(10) << "First Name"
                << "|" << std::setw(10) << "Last Name"
                << "|" << std::setw(10) << "Nickmame"
                << "|" << std::endl;
    std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;
    for (int i = 0; i < _countContacts; i++) {
        std::cout << "|" << std::setw(10) << i + 1
                << "|" << std::setw(10) << formatColumn(_contacts[i].getFirstName())
                << "|" << std::setw(10) << formatColumn(_contacts[i].getLastName())
                << "|" << std::setw(10) << formatColumn(_contacts[i].getNickName())
                << "|" << std::endl;
    }
    std::string input;
    if (_countContacts > 0)
    {
        std::cout << "Put user index to display : ";
        std::getline(std::cin, input);
    }
    else
    {
        std::cout << "Your phonebook is empty..." << std::endl;
        return;
    }
    if (!isNumber(input)) {
        std::cout << "❌ You can only put index..." << std::endl;
        return;
    }
    int index = std::atoi(input.c_str()) - 1;
    if (index < 0 || index >= _countContacts) {
        std::cout << "❌ This index don't exist..." << std::endl;
        return;
    }
    std::cout << "|" << std::setw(10) << index + 1
                << "|" << std::setw(10) << formatColumn(_contacts[index].getFirstName())
                << "|" << std::setw(10) << formatColumn(_contacts[index].getLastName())
                << "|" << std::setw(10) << formatColumn(_contacts[index].getNickName())
                << "|" << std::endl;
}