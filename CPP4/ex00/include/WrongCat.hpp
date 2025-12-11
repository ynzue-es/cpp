/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 10:51:30 by ynzue-es          #+#    #+#             */
/*   Updated: 2025/12/11 10:51:32 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : public WrongAnimal
{
    private:  

    public:
        WrongCat();
        WrongCat(WrongCat const & src);
        ~WrongCat();

        WrongCat& operator=(WrongCat const & rhs);

        void makeSound( void ) const;
};

#endif