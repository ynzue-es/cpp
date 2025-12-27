#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <sstream>
#include <stdexcept>
#include <cstdlib>

class RPN
{
    private:
        RPN();
        RPN(RPN const & src);
        RPN &operator=(RPN const & rhs);
        ~RPN();

    public:
        static int evaluate(std::string const & expr);
};

#endif