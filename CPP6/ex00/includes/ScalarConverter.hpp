/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:10 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 15:21:30 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <limits>
#include <cmath>
#include <iostream>

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