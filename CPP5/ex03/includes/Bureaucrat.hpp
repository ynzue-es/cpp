/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:44:35 by yannis            #+#    #+#             */
/*   Updated: 2025/12/16 01:54:17 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>

class Form;

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
        
    public:
        Bureaucrat(std::string const & name, int grade);
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat & operator=(Bureaucrat const & rhs);
        ~Bureaucrat();
        
        const std::string & getName() const;
        int getGrade() const;
        
        void incrementGrade();
        void decrementGrade();

        void signForm(Form & form);
        
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

std::ostream & operator<<(std::ostream & o,Bureaucrat const & rhs);

#endif