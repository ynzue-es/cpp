/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:17:10 by ynzue-es          #+#    #+#             */
/*   Updated: 2025/12/15 14:00:20 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Form::Form(std::string const & name, int signGrade, int executeGrade) 
    :   _name(name), 
        _isSigned(false), 
        _signGrade(signGrade), 
        _executeGrade(executeGrade) 
{
    if (signGrade < 1 || executeGrade < 1) throw Form::GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150) throw Form::GradeTooLowException();
}

Form::Form(Form const & src) 
    :   _name(src._name), 
        _isSigned(src._isSigned),
        _signGrade(src._signGrade),
        _executeGrade(src._executeGrade)
{}

Form & Form::operator=(Form const & rhs) {
    if (this != &rhs)
        *this = rhs;
    return *this;
}

Form::~Form() {}

std::string const Form::getName() const {
    std::cout << this->_name << std::endl;
}

bool const Form::getIsSigned() const {
    std::cout << this->_isSigned << std::endl;
}

int const Form::getSignGrade() const {
    std::cout << this->_signGrade << std::endl;
}

int const Form::getExecuteGrade() const {
    std::cout << this->_executeGrade << std::endl;
}

bool Form::beSigned(Bureaucrat const & bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade) {
        throw Form::GradeTooLowException();
        return false;
    }
    return true;
}

std::ostream & operator<<(std::ostream & o,Form const & rhs) {
    o << "Form informations : "
      << rhs.getName() 
      << rhs.getIsSigned()
      << rhs.getSignGrade() 
      << rhs.getExecuteGrade();
    return (o);
}