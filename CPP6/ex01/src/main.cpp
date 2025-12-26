/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 18:45:56 by yannis            #+#    #+#             */
/*   Updated: 2025/12/26 16:41:57 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/Serializer.hpp"

int main()
{
    Data data;
    data.number = 42;
    data.text = "Hello 42";

    Data* original = &data;
    uintptr_t raw = Serializer::serialize(original);
    Data* restored = Serializer::deserialize(raw);

    std::cout << "Original pointer : " << original << std::endl;
    std::cout << "Restored pointer : " << restored << std::endl;

    if (original == restored)
        std::cout << "Serialization works" << std::endl;
    else
        std::cout << "Serialization failed" << std::endl;
    return 0;
}