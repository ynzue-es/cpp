#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <climits>
#include <exception>
#include <iterator>
#include <iostream>

class Span
{
private:
    unsigned int        _N;
    std::vector<int>    _numbers;

public:
    Span(unsigned int N);
    Span(Span const & src);
    Span & operator=(Span const & rhs);
    ~Span();

    void addNumber(int e);

    template <typename Iterator>
    void addRange(Iterator first, Iterator last)
    {
        if (_numbers.size() + std::distance(first, last) > _N)
            throw std::exception();
        _numbers.insert(_numbers.end(), first, last);
    }

    int shortestSpan() const;
    int longestSpan() const;
};

#endif