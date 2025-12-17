/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 23:54:18 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 00:28:59 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

class AForm;

class Intern
{
    private:
        
    public:
        Intern();
        Intern(Intern const & src);
        Intern & operator=(Intern const & rhs);
        ~Intern();

        AForm* makeForm(std::string name, std::string target);
};

#endif
