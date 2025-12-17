/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:44:37 by yannis            #+#    #+#             */
/*   Updated: 2025/12/16 01:43:14 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Form.hpp"
#include "../includes/Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

Bureaucrat::Bureaucrat(std::string const & name, int grade) : _name(name), _grade(grade) {
    if (grade < 1) throw Bureaucrat::GradeTooHighException();
    if (grade > 150) throw Bureaucrat::GradeTooLowException();
}
Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src._name), _grade(src._grade){}

Bureaucrat & Bureaucrat::operator=(Bureaucrat const & rhs) {
    if (&rhs != this) {
        _grade = rhs._grade;   
    }
    return(*this);
}

Bureaucrat::~Bureaucrat() {}

const std::string & Bureaucrat::getName() const {
    return (_name);
}

int Bureaucrat::getGrade() const {
    return (_grade);
}

void Bureaucrat::incrementGrade() {
    if ((_grade - 1) < 1)
        throw GradeTooHighException();
    _grade -= 1;
}

void Bureaucrat::decrementGrade() {
    if ((_grade + 1) > 150)
        throw GradeTooLowException();
    _grade += 1;
}

void Bureaucrat::signForm(Form & form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception & e) {
        std::cout << this->_name << " couldn't sign "
                  << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream & operator<<(std::ostream & o,Bureaucrat const & rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "."; 
    return (o);
}