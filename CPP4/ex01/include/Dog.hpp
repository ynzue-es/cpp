/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:34:04 by yannis            #+#    #+#             */
/*   Updated: 2025/09/01 16:58:08 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public Animal
{
    private:
        Brain *_brain;

    public:
        Dog();
        Dog(Dog const & src);
        ~Dog();

        Dog& operator=(Dog const & rhs);

        void makeSound( void ) const;
};

#endif