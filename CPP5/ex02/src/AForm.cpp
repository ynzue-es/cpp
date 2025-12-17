/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 00:03:26 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 00:22:03 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"
#include <stdexcept>

AForm::AForm(std::string const & name, int signGrade, int executeGrade)
    : _name(name), 
    _isSigned(false), 
    _signGrade(signGrade), 
    _executeGrade(executeGrade)
{
    if (signGrade < 1 || executeGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(AForm const & src)
    : _name(src._name),
      _isSigned(src._isSigned),
      _signGrade(src._signGrade),
      _executeGrade(src._executeGrade)
{
}

AForm & AForm::operator=(AForm const & rhs)
{
    if (this != &rhs)
        _isSigned = rhs._isSigned;
    return *this;
}

AForm::~AForm() {}

std::string const & AForm::getName() const { return _name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getSignGrade() const { return _signGrade; }
int AForm::getExecuteGrade() const { return _executeGrade; }

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() > _signGrade)
        throw GradeTooLowException();
    _isSigned = true;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::NotSignedException::what() const throw() {
    return "Form is not signed";
}

std::ostream & operator<<(std::ostream & o, AForm const & rhs)
{
    o << "Form \"" << rhs.getName() << "\""
      << ", signed: " << (rhs.getIsSigned() ? "yes" : "no")
      << ", sign grade: " << rhs.getSignGrade()
      << ", execute grade: " << rhs.getExecuteGrade();
    return o;
}
