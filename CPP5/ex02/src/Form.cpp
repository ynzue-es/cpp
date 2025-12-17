/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:17:10 by ynzue-es          #+#    #+#             */
/*   Updated: 2025/12/16 01:58:11 by yannis           ###   ########.fr       */
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
        this->_isSigned = rhs._isSigned;
    return *this;
}

Form::~Form() {}

std::string const & Form::getName() const {
    return this->_name;
}

bool Form::getIsSigned() const {
    return this->_isSigned;
}

int Form::getSignGrade() const {
    return this->_signGrade;
}

int Form::getExecuteGrade() const {
    return this->_executeGrade;
}

void Form::beSigned(Bureaucrat const & bureaucrat) {
    if (bureaucrat.getGrade() > this->_signGrade)
        throw Form::GradeTooLowException();
    this->_isSigned = true;
}

std::ostream & operator<<(std::ostream & o, Form const & rhs) {
    o << "Form \"" << rhs.getName() << "\""
      << ", signed: " << (rhs.getIsSigned() ? "yes" : "no")
      << ", sign grade: " << rhs.getSignGrade()
      << ", execute grade: " << rhs.getExecuteGrade();
    return o;
}