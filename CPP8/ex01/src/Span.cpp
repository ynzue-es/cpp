#include "../includes/Span.hpp"

Span::Span(unsigned int N) : _N(N) {}

Span::Span(Span const & src) : _N(src._N), _numbers(src._numbers) {}

Span & Span::operator=(Span const & rhs)
{
    if (this != &rhs)
    {
        _N = rhs._N;
        _numbers = rhs._numbers;
    }
    return *this;
}

Span::~Span() {}

void Span::addNumber(int e)
{
    if (_numbers.size() >= _N)
        throw std::exception();
    _numbers.push_back(e);
}

int Span::shortestSpan() const
{
    if (_numbers.size() < 2)
        throw std::exception();
    std::vector<int> tmp = _numbers;
    std::sort(tmp.begin(), tmp.end());
    int shortest = INT_MAX;
    for (size_t i = 1; i < tmp.size(); ++i)
    {
        int diff = tmp[i] - tmp[i - 1];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}

int Span::longestSpan() const
{
    if (_numbers.size() < 2)
        throw std::exception();
    int min = *std::min_element(_numbers.begin(), _numbers.end());
    int max = *std::max_element(_numbers.begin(), _numbers.end());
    return max - min;
}