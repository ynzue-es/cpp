#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <set>

class PmergeMe {
    private:

    public:
        PmergeMe();
        PmergeMe(PmergeMe const&);
        PmergeMe& operator=(PmergeMe const&);
        ~PmergeMe();

        static void process(int argc, char **argv);
};

#endif