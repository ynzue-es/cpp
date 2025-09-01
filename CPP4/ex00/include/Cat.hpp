/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:41:29 by yannis            #+#    #+#             */
/*   Updated: 2025/09/01 10:32:56 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include <string>

class Cat : public Animal
{
    private:  

    public:
        Cat();
        Cat(Cat const & src);
        ~Cat();

        Cat& operator=(Cat const & rhs);

        void makeSound( void ) const;
};

#endif