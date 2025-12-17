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

AForm::AForm(std::string const & name, int signGrade, int executeGrade)
    : _name(name), 
    _isSigned(false), 
    _signGrade(signGrade), 
    _executeGrade(executeGrade)
{
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
