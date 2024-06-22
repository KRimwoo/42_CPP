#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>


class RPN {
    private:
        std::string _input;
        std::stack<int> _stack;

        void operate(char op);

    public:
        RPN();
        RPN(const std::string &input);
        RPN(const RPN &other);
        RPN &operator=(const RPN &other);
        ~RPN();

        void calculate();
        class Error : public std::exception {
            public:
                virtual const char *what() const throw();
        };
};


#endif