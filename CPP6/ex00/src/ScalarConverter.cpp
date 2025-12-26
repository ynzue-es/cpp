/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:38:42 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 15:25:38 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::ScalarConverter(ScalarConverter const &src) {
    (void)src;
}
ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &src) {
    (void)src;
	return *this;
}
ScalarConverter::~ScalarConverter() {}

enum e_type {
    TYPE_CHAR,
    TYPE_INT,
    TYPE_FLOAT,
    TYPE_DOUBLE,
    TYPE_INVALID
};

int ScalarConverter::detectType(std::string const & str)
{
    size_t i = 0;
    bool dot = false;
    bool digit = false;

    if (str == "nan" || str == "+inf" || str == "-inf")
        return TYPE_DOUBLE;
    if (str == "nanf" || str == "+inff" || str == "-inff")
        return TYPE_FLOAT;

    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return TYPE_CHAR;
    if (str[i] == '+' || str[i] == '-')
        i++;
    if (i >= str.length())
        return TYPE_INVALID;

    for (; i < str.length(); i++)
    {
        if (std::isdigit(str[i]))
            digit = true;
        else if (str[i] == '.')
        {
            if (dot)
                return TYPE_INVALID;
            dot = true;
        }
        else if (str[i] == 'f' && i == str.length() - 1 && dot)
            return TYPE_FLOAT;
        else
            return TYPE_INVALID;
    }
    if (!digit)
        return TYPE_INVALID;
    if (dot)
        return TYPE_DOUBLE;
    return TYPE_INT;
}

void ScalarConverter::fromChar(char c) {
    std::cout << "char: ";
    if (!std::isprint(c))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << c << "'\n";
    std::cout << "int: " << static_cast<int>(c) << "\n";
    std::cout << "float: " << static_cast<float>(c) << ".0f\n";
    std::cout << "double: " << static_cast<double>(c) << ".0\n";
}

void ScalarConverter::fromInt(int i)
{
    std::cout << "char: ";
    if (i < 0 || i > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(i)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(i) << "'\n";

    std::cout << "int: " << i << "\n";
    std::cout << "float: " << static_cast<float>(i) << ".0f\n";
    std::cout << "double: " << static_cast<double>(i) << ".0\n";
}

void ScalarConverter::fromFloat(float f)
{
    std::cout << "char: ";
    if (std::isnan(f) || std::isinf(f) || f < 0 || f > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(f)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(f) << "'\n";

    std::cout << "int: ";
    if (std::isnan(f) || std::isinf(f)
        || f < std::numeric_limits<int>::min()
        || f > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(f) << "\n";

    std::cout << "float: " << f;
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "f\n";

    std::cout << "double: " << static_cast<double>(f);
    if (f == static_cast<int>(f))
        std::cout << ".0";
    std::cout << "\n";
}

void ScalarConverter::fromDouble(double d)
{
    std::cout << "char: ";
    if (std::isnan(d) || std::isinf(d) || d < 0 || d > 127)
        std::cout << "impossible\n";
    else if (!std::isprint(static_cast<char>(d)))
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << static_cast<char>(d) << "'\n";

    std::cout << "int: ";
    if (std::isnan(d) || std::isinf(d)
        || d < std::numeric_limits<int>::min()
        || d > std::numeric_limits<int>::max())
        std::cout << "impossible\n";
    else
        std::cout << static_cast<int>(d) << "\n";

    std::cout << "float: " << static_cast<float>(d);
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << "f\n";

    std::cout << "double: " << d;
    if (d == static_cast<int>(d))
        std::cout << ".0";
    std::cout << "\n";
}

void ScalarConverter::convert(std::string const & str)
{
    int type = detectType(str);

    switch (type)
    {
        case TYPE_CHAR:
        {
            char c = str[0];
            fromChar(c);
            break;
        }
        case TYPE_INT:
        {
            long l = std::strtol(str.c_str(), NULL, 10);
            if (l < std::numeric_limits<int>::min() ||
                l > std::numeric_limits<int>::max())
            {
                std::cout << "char: impossible\n";
                std::cout << "int: impossible\n";
                std::cout << "float: impossible\n";
                std::cout << "double: impossible\n";
                return;
            }
            fromInt(static_cast<int>(l));
            break;
        }
        case TYPE_FLOAT:
        {
            float f = std::strtof(str.c_str(), NULL);
            fromFloat(f);
            break;
        }
        case TYPE_DOUBLE:
        {
            double d = std::strtod(str.c_str(), NULL);
            fromDouble(d);
            break;
        }
        default:
            std::cout << "Invalid literal\n";
    }
}