/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:41:29 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:44:24 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"
#include <string>

class Cat : public AAnimal
{
    private:
        Brain *_brain;

    public:
        Cat();
        Cat(Cat const & src);
        ~Cat();

        Cat& operator=(Cat const & rhs);

        void makeSound( void ) const;
};

#endif