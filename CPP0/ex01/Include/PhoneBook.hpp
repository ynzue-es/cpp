/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:40:30 by yannis            #+#    #+#             */
/*   Updated: 2025/08/25 19:18:00 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

class PhoneBook
{
    private:
        Contact _contacts[8];
        int     _countContacts;
        
        void _filedInput(const std::string& fieldName, 
                        Contact& contact, 
                        void (Contact::*setter)(const std::string&));
    
    public:
        PhoneBook();
        ~PhoneBook();
        
        void add();
        void search();
};
