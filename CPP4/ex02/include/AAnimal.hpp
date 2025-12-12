/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 09:25:47 by yannis            #+#    #+#             */
/*   Updated: 2025/12/12 10:09:13 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <string>

class AAnimal
{
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal(AAnimal const & src);
        AAnimal& operator=(AAnimal const & rhs);
        virtual ~AAnimal();

        virtual void makeSound() const = 0;

        std::string getType() const;
        void setType(std::string const & type);
};

#endif