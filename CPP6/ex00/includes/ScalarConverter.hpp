/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:10 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 19:19:55 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <string>
#include <limits>
#include <cmath>
#include <iostream>
#include <cctype>
#include <cstdlib>

enum e_type {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
};

class ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(ScalarConverter const & src);
        ScalarConverter & operator=(ScalarConverter const & rhs);
        ~ScalarConverter();

    public:
        static int detectType(std::string const & str);

        static void fromChar(char c);
        static void fromInt(int i);
        static void fromFloat(float f);
        static void fromDouble(double d);
        
        static void convert(std::string const & str);
};

#endif
