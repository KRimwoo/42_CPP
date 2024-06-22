#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(const std::string &input) : _input(input) {
    this->_input = input;
}

RPN::RPN(const RPN &other) {
    *this = other;
}

RPN &RPN::operator=(const RPN &other) {
    if (this != &other) {
        this->_input = other._input;
        this->_stack = other._stack;
    }
    return *this;
}

RPN::~RPN() {}

void RPN::operate(char op) {
    if (_stack.size() < 2)
        throw Error();
    long long second = static_cast<long long>(_stack.top());
    _stack.pop();
    long long first = static_cast<long long>(_stack.top());
    _stack.pop();
    long long result;
    switch (op) {
        case '+':
            result = first + second;
            break;
        case '-':
            result = first - second;
            break;
        case '*':
            result = first * second;
            break;
        case '/':
            if (second == 0)
                throw Error();
            result = first / second;
            break;
        default:
            throw Error();
    }
    if (result > 2147483647 || result < -2147483648)
        throw Error();
    _stack.push(static_cast<int>(result));
}

void RPN::calculate() {
    for (unsigned int idx = 0; idx < _input.length(); idx++) {
        if (idx % 2)
        {
            if (_input[idx] != ' ')
                throw Error();
        }
        else
        {
            if (isdigit(_input[idx]))
                _stack.push(_input[idx] - '0');
            else if (_input[idx] == '+' || _input[idx] == '-' || _input[idx] == '*' || _input[idx] == '/')
                operate(_input[idx]);
            else
                throw Error();
        }
    }
    if (_stack.size() != 1)
        throw Error();
    std::cout << _stack.top() << std::endl;
}

const char *RPN::Error::what() const throw() {
    return "Error";
}