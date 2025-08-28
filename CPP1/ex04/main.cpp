/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yannis <yannis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 08:20:11 by yannis            #+#    #+#             */
/*   Updated: 2025/08/28 09:34:54 by yannis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

void my_replace(std::string& line, size_t pos, size_t count, std::string const & str)
{
    if (pos > line.size())
        return;
    if (pos + count > line.size())
        count = line.size() - pos;
    line = line.substr(0, pos) + str + line.substr(pos + count);
}

int main(int argc, char** argv) {
    if (argc != 4)
    {
        std::cerr << "Usage : <filename> <s1> <s2>" << std::endl;
        return (1);
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "Can't open file !" << std::endl;
        return(1);
    }

    std::string filename = argv[1];
    size_t pos = filename.find_last_of('.');
    std::string new_filename;
    if (pos != std::string::npos)
        new_filename = filename.substr(0, pos) + ".replace";
    else
        new_filename = filename + ".replace";
    std::ofstream new_file(new_filename.c_str());
    if (!new_file) {
        std::cerr << "Impossible to create " << new_filename << std::endl;
        return 1;
    }

    std::string to_find = argv[2];
    std::string to_replace = argv[3];    
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = 0;
        while ((pos = line.find(to_find, pos)) != std::string::npos)
        {
            my_replace(line, pos, to_find.length(), to_replace);
            pos += to_replace.length();
        }
        new_file << line << '\n';        
    }

    file.close();
    new_file.close();
    return (0);
}