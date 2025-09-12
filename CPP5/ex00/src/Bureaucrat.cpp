/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:44:37 by yannis            #+#    #+#             */
/*   Updated: 2025/09/12 10:49:12 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <iostream>

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

std::ostream & operator<<(std::ostream & o,Bureaucrat const & rhs) {
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << "."; 
    return (o);
}