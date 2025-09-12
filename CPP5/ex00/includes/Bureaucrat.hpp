/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:44:35 by yannis            #+#    #+#             */
/*   Updated: 2025/09/12 11:36:05 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

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
        
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade is too high");
            }
    };
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw()
            {
                return ("Grade is too low");
            }
    };
};

std::ostream & operator<<(std::ostream & o,Bureaucrat const & rhs);
