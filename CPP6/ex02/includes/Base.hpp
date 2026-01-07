/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynzue-es <ynzue-es@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:10 by yannis            #+#    #+#             */
/*   Updated: 2026/01/07 09:04:27 by ynzue-es         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include <stdint.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iostream>
class Base {
    public:
        virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);

#endif
