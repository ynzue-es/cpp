/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 00:04:16 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 00:26:46 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm
{
    private:
        std::string const _name;
        bool _isSigned;
        int const _signGrade;
        int const _executeGrade;

    public:
        AForm(std::string const & name, int signGrade, int executeGrade);
        AForm(AForm const & src);
        AForm & operator=(AForm const & rhs);
        virtual ~AForm();

        std::string const & getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        virtual void execute(Bureaucrat const & executor) const = 0;

        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream & operator<<(std::ostream & o, AForm const & rhs);

#endif