/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:50:25 by yannis            #+#    #+#             */
/*   Updated: 2025/08/25 17:58:10 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>

Contact::Contact() {
    std::cout << "Contact create" << std::endl;
}

Contact::~Contact() {
    std::cout << "Contact create" << std::endl;
}

void Contact::setFirstName(const std::string& firstName) {
    _firstName = firstName;
}

void Contact::setLastName(const std::string& lastName) {
    _lastName = lastName;
}

void Contact::setNickName(const std::string& nickName) {
    _nickName = nickName;
}

void Contact::setPhoneNumber(const std::string& phoneNumber) {
    _phoneNumber = phoneNumber;
}

void Contact::setDarkestSecret(const std::string& darkestSecret) {
    _darkestSecret = darkestSecret;
}

std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickName() const {
    return _nickName;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}

