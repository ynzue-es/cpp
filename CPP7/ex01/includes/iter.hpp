/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 22:37:24 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 22:53:15 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(T* array, size_t const length, void (*func)(T&))
{
    if (!array || !func)
        return;
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

template <typename T>
void iter(T const* array, size_t const length, void (*func)(T const&))
{
    if (!array || !func)
        return;
    for (size_t i = 0; i < length; ++i)
        func(array[i]);
}

#endif