/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 23:46:29 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 23:57:10 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
private:
    T*              _data;
    unsigned int    _size;

public:
    Array();
    Array(unsigned int n);
    Array(Array const& src);
    Array& operator=(Array const& rhs);
    ~Array();

    T& operator[](unsigned int index);
    T const& operator[](unsigned int index) const;

    unsigned int size() const;
};

#include "Array.tpp"

#endif