/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:25:47 by yannis            #+#    #+#             */
/*   Updated: 2025/09/01 20:39:54 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
    protected:
        std::string _type;
        
    public:
        Animal();
        Animal(Animal const & src);
        Animal& operator=(Animal const & rhs);
        virtual ~Animal();

        virtual void makeSound( void ) const = 0;

        std::string getType() const;
        void setType(std::string const & type);
};

#endif