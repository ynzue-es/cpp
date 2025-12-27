#include "../includes/PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <set>
#include <ctime>

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const&) {}
PmergeMe& PmergeMe::operator=(PmergeMe const&) { return *this; }
PmergeMe::~PmergeMe() {}

template <typename Container>
static void insertionSort(Container &c, size_t left, size_t right)
{
    for (size_t i = left + 1; i <= right; ++i) {
        typename Container::value_type key = c[i];
        size_t j = i;
        while (j > left && c[j - 1] > key)
        {
            c[j] = c[j - 1];
            --j;
        }
        c[j] = key;
    }
}

template <typename Container>
static void merge(Container &c, size_t left, size_t mid, size_t right)
{
    Container tmp;
    size_t i = left;
    size_t j = mid + 1;
    while (i <= mid && j <= right)
    {
        if (c[i] <= c[j])
            tmp.push_back(c[i++]);
        else
            tmp.push_back(c[j++]);
    }
    while (i <= mid)
        tmp.push_back(c[i++]);
    while (j <= right)
        tmp.push_back(c[j++]);
    for (size_t k = 0; k < tmp.size(); ++k)
        c[left + k] = tmp[k];
}

template <typename Container>
static void mergeInsertSort(Container &c, size_t left, size_t right)
{
    if (right <= left)
        return;
    if (right - left <= 16) {
        insertionSort(c, left, right);
        return;
    }
    size_t mid = (left + right) / 2;
    mergeInsertSort(c, left, mid);
    mergeInsertSort(c, mid + 1, right);
    merge(c, left, mid, right);
}

void PmergeMe::process(int argc, char **argv)
{
    if (argc < 2) {
        std::cout << "Error" << std::endl;
        return;
    }
    std::vector<int> vec;
    std::deque<int>  deq;
    std::set<int>    seen;
    for (int i = 1; i < argc; ++i)
    {
        std::stringstream ss(argv[i]);
        int value;
        char c;
        if (!(ss >> value) || ss.get(c)) {
            std::cout << "Error" << std::endl;
            return;
        }
        if (value < 0 || seen.count(value)) {
            std::cout << "Error" << std::endl;
            return;
        }
        seen.insert(value);
        vec.push_back(value);
        deq.push_back(value);
    }
    std::cout << "Before: ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    clock_t startVec = clock();
    mergeInsertSort(vec, 0, vec.size() - 1);
    clock_t endVec = clock();
    clock_t startDeq = clock();
    mergeInsertSort(deq, 0, deq.size() - 1);
    clock_t endDeq = clock();
    std::cout << "After:  ";
    for (size_t i = 0; i < vec.size(); ++i)
        std::cout << vec[i] << " ";
    std::cout << std::endl;
    double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;
    double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;
    std::cout << "Time to process a range of " << vec.size()
              << " elements with std::vector : " << timeVec << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size()
              << " elements with std::deque  : " << timeDeq << " us" << std::endl;
}