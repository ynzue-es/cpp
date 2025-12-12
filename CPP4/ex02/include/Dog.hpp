/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:34:04 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:44:22 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Dog : public AAnimal
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