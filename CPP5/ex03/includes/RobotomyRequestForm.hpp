/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 00:35:35 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 00:35:38 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : public AForm
{
    private:
        std::string _target;

    public:
        RobotomyRequestForm(std::string const & target);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        RobotomyRequestForm & operator=(RobotomyRequestForm const & rhs);
        virtual ~RobotomyRequestForm();

        virtual void execute(Bureaucrat const & executor) const;
};

#endif