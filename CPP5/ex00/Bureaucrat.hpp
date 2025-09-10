/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 15:44:35 by yannis            #+#    #+#             */
/*   Updated: 2025/09/10 16:05:17 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Bureaucrat
{
    private:
        std::string const _name;
        int _grade;
        
    public:
        Bureaucrat(std::string const & name, int grade);
        ~Bureaucrat();
};
