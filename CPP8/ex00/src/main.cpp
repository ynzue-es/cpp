#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    try {
        std::vector<int>::iterator it = easyfind(v, 2);
        std::cout << "Found value: " << *it << std::endl;
    } catch (std::exception&) {
        std::cout << "Value not found" << std::endl;
    }

    return 0;
}