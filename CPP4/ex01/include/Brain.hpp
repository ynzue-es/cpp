/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 16:30:34 by yannis            #+#    #+#             */
/*   Updated: 2025/09/01 17:45:20 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>

class Brain
{
    private:
        std::string *_ideas[100];

    public:
        Brain();
        Brain(Brain const & src);
        Brain& operator=(Brain const & rhs);
        ~Brain();
};

#endif