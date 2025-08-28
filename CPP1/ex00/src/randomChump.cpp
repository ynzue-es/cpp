/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 14:59:39 by yannis            #+#    #+#             */
/*   Updated: 2025/08/27 21:23:45 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"
#include <string>
#include <iostream>

void randomChump( std::string name ) {
    Zombie zombie(name);
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}