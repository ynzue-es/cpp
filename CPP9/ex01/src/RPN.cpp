#include "RPN.hpp"

RPN::RPN() {
}

RPN::RPN(RPN const & src) {
    *this = src;
}

RPN & RPN::operator=(RPN const & rhs) {
    (void) rhs;
    return *this;
}

RPN::~RPN() {
}

int RPN::evaluate(std::string const & expr) {
    std::stack<int> stack;
    std::stringstream ss(expr);
    std::string token;

    while (ss >> token)
    {
        if (token.size() == 1 && std::isdigit(token[0])) {
            stack.push(token[0] - '0');
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            if (stack.size() < 2)
                throw std::runtime_error("Error");
            int b = stack.top(); stack.pop();
            int a = stack.top(); stack.pop();
            if (token == "/" && b == 0)
                throw std::runtime_error("Error");
            int result;
            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else result = a / b;
            stack.push(result);
        } else {
            throw std::runtime_error("Error");
        }
    }
    if (stack.size() != 1)
        throw std::runtime_error("Error");
    return stack.top();
}