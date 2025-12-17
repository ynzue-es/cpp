/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 00:36:08 by yannis            #+#    #+#             */
/*   Updated: 2025/12/18 00:36:10 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : public AForm
{
    private:
        std::string _target;

    public:
        PresidentialPardonForm(std::string const & target);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        PresidentialPardonForm & operator=(PresidentialPardonForm const & rhs);
        virtual ~PresidentialPardonForm();

        virtual void execute(Bureaucrat const & executor) const;
};

#endif