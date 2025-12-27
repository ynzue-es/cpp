#include "../includes/Span.hpp"

int main()
{
    std::cout << "===== BASIC TEST =====" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught (basic test)" << std::endl;
    }

    std::cout << "\n===== OUT OF RANGE TEST =====" << std::endl;
    try
    {
        Span sp(3);
        sp.addNumber(1);
        sp.addNumber(2);
        sp.addNumber(3);
        sp.addNumber(4); // throw
    } catch (std::exception &e) {
        std::cout << "Exception caught (capacity exceeded)" << std::endl;
    }

    std::cout << "\n===== NOT ENOUGH ELEMENTS TEST =====" << std::endl;
    try {
        Span sp(5);
        sp.addNumber(42);
        std::cout << sp.shortestSpan() << std::endl; // throw
    } catch (std::exception &e) {
        std::cout << "Exception caught (not enough elements)" << std::endl;
    }

    std::cout << "\n===== COPY TEST =====" << std::endl;
    try
    {
        Span sp1(5);
        sp1.addNumber(10);
        sp1.addNumber(20);
        Span sp2(sp1);
        sp2.addNumber(30);
        std::cout << "sp1 longest: " << sp1.longestSpan() << std::endl;
        std::cout << "sp2 longest: " << sp2.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught (copy test)" << std::endl;
    }

    std::cout << "\n===== RANGE TEST =====" << std::endl;
    try
    {
        std::vector<int> values;
        for (int i = 0; i < 100; ++i)
            values.push_back(i * 2);
        Span sp(100);
        sp.addRange(values.begin(), values.end());
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception caught (range test)" << std::endl;
    }

    std::cout << "\n===== BIG TEST (10 000 numbers) =====" << std::endl;
    try
    {
        Span sp(10000);
        for (int i = 0; i < 10000; ++i)
            sp.addNumber(i);
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span : " << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception caught (big test)" << std::endl;
    }
    return 0;
}