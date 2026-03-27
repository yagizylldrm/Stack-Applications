#ifndef INFIXTOPOSTFIX
#define INFIXTOPOSTFIX

#include "Stack.h"

#include <string>

class InfixToPostfix
{
private:
    std::string infix;
    std::string postfix;

    bool isOperator(char c) { return (c == '+' || c == '-' || c == '*' || c == '/'); }

    bool precedence(char op1, char op2)
    {
        if ((op1 == '*' || op1 == '/') && (op2 == '+' || op2 == '-')) return true;
        else if ((op1 == '+' || op1 == '-') && (op2 == '*' || op2 == '/')) return false;
        else if (op1 == op2 || ((op1 == '*' || op1 == '/') && (op2 == '*' || op2 == '/')) || ((op1 == '+' || op1 == '-') && (op2 == '+' || op2 == '-'))) return true;
        else if (op1 == '(') return false;
        else return false;
    }

public:
    void setInfix(std::string s) { infix = s; }

    std::string getPostfix() { return postfix; }

    std::string getInfix() { return infix; }

    void showInfix() const { std::cout << postfix << std::endl; }

    void showPostfix() const { std::cout << postfix << std::endl; }

    /** Application 1: Binary to Decimal Conversion **/
    int convertBinaryToInt(char binString[])
    {
        Stack<int> s;
        int res = 0;

        // my implementation
        for (int i = 0; binString[i] != '\0'; i++) { s.push(binString[i] - '0'); }

        int weight = 0;
        int top_var;
        while (!s.isEmpty())
        {
            top_var = s.top();
            s.pop();
            res += top_var * pow(2, weight++);
        }

        return res;
    }

    /** Application 2: Infix to Postfix Conversion **/
    void convertToPostfix()
    {
        postfix = "";
        Stack<char> s;

        char c;
        for (int i = 0; i < infix.length(); i++)
        {
            c = infix.at(i);
            if (isalnum(c)) postfix += c;

            else if (c == '(') s.push(c);
            else if (c == ')')
            {
                while (!s.isEmpty() && s.top() != '(')
                {
                    postfix += s.top();
                    s.pop();
                }
                if (!s.isEmpty()) s.pop();
            }
            else if (isOperator(c))
            {
                while (!s.isEmpty() && s.top() != '(' && precedence(s.top(), c))
                {
                    postfix += s.top();
                    s.pop();
                }
                s.push(c);
            }
        }

        while (!s.isEmpty())
        {
            if (s.top() != '(') postfix += s.top();
            s.pop();
        }
    }

    /** Application 3: Postfix Calculator **/
    int postfixCalculator()
    {
        Stack<int> s;

        char c;
        for (int i = 0; i < postfix.length(); i++)
        {
            c = postfix.at(i);
            if (std::isdigit(c)) s.push(c - '0');
            else if (isOperator(c))
            {
                int val2 = s.top();
                s.pop();
                int val1 = s.top();
                s.pop();

                switch (c)
                {
                    case '+':
                    {
                        s.push(val1 + val2);
                        break;
                    }
                    case '-':
                    {
                        s.push(val1 - val2);
                        break;
                    }
                    case '*':
                    {
                        s.push(val1 * val2);
                        break;
                    }
                    case '/':
                    {
                        if (val2 == 0) throw std::logic_error("Cannot divide by 0");
                        s.push(val1 / val2);
                        break;
                    }
                }
            }
        }

        return s.top();
    }
};

#endif /* INFIXTOPOSTFIX */
