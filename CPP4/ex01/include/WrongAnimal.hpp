/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 11:03:49 by yannis            #+#    #+#             */
/*   Updated: 2025/09/01 11:11:41 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_Animal_HPP
#define WRONG_Animal_HPP

#include <string>

class WrongAnimal
{
    protected:
        std::string _type;
        
    public:
        WrongAnimal();
        WrongAnimal(WrongAnimal const & src);
        WrongAnimal& operator=(WrongAnimal const & rhs);
        ~WrongAnimal();

        void makeSound( void ) const;

        std::string getType() const;
        void setType(std::string const & type);
};

#endif