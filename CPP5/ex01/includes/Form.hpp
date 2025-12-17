/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:19:12 by ynzue-es          #+#    #+#             */
/*   Updated: 2025/12/16 01:53:16 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        std::string const _name;
        bool _isSigned;
        int const _signGrade;
        int const _executeGrade;
       
    public:
        Form(std::string const & name, int signGrade, int executeGrade);
        Form(Form const & src);
        Form & operator=(Form const & rhs);
        ~Form();

        std::string const & getName() const;
        bool getIsSigned() const;
        int getSignGrade() const;
        int getExecuteGrade() const;

        void beSigned(Bureaucrat const & bureaucrat);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & o,Form const & rhs);

#endif