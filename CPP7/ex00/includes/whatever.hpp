/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:01:06 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 22:31:04 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T & a, T & b)
{
    T tmp = a;
    a = b;
    b = tmp;
}

template <typename T>
T const & max(T const & x, T const & y) {
    return (x>=y ? x : y);
}

template <typename T>
T const & min(T const & x, T const & y) {
    return (x<=y ? x : y);
}

#endif