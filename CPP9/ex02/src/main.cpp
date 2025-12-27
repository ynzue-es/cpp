#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
    /*
        Tests:

        # Basic
        ./PmergeMe 3 5 9 7 4

        # Single / small
        ./PmergeMe 42
        ./PmergeMe 2 1

        # Errors
        ./PmergeMe -1 2
        ./PmergeMe 1 2 2
        ./PmergeMe 1 a

        # Large input
        # Linux
        ./PmergeMe $(shuf -i 1-100000 -n 3000 | tr '\n' ' ')
        # macOS
        ./PmergeMe $(jot 3000 1 100000 | tr '\n' ' ')
    */
    PmergeMe::process(argc, argv);
    return 0;
}