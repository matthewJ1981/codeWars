#include "codeWars.h"
#include <cctype>
#include <stack>
#include <stdexcept>


#include <iostream>


//Helper function to assign precedence values to operators
int value(const char ch)
{
    switch (ch)
    {
        case '+':
        case '-':
            return 0;
        case '*':
        case '/':
            return 1;
        case '^':
            return 2;
        case '(':
        case ')':
            return 3;
        default:
            throw std::runtime_error("Invalid character");
    }
}

// Construct a function that, when given a string containing an expression in infix notation, will return an identical expression in postfix notation.
// The operators used will be +, -, *, /, and ^ with left-associativity of all operators but ^.
// The precedence of the operators (most important to least) are : 1) parentheses, 2) exponentiation, 3) times/divide, 4) plus/minus.
// The operands will be single-digit integers between 0 and 9, inclusive.
// Parentheses may be included in the input, and are guaranteed to be in correct pairs.

// to_postfix("2+7*5") // Should return "275*+"
// to_postfix("3*3/(7+1)") // Should return "33*71+/"
// to_postfix("5+(6-2)*9+3^(7-1)") // Should return "562-9*+371-^+"
// to_postfix("1^2^3") // Should return "123^^"
std::string to_postfix(std::string str)
{
    //Output
    std::string result = "";

    //Operator stack
    std::stack<char> operators;
    //Parse the string
    for (size_t i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        //Add character to the output if it is a digit
        if (isdigit(ch))
            result += ch;
        //Recurse the function to eliminate parenthesis
        else if (ch == '(')
        {
            result += to_postfix(str.substr(i + 1, str.length()));
            while (str[i] != ')')
                i++;
        }
        //Exit resursion on closing parenthesis
        else if (ch == ')')
            break;
        //Always push exponents for right association
        else if (ch == '^')
            operators.push(ch);
        else
        {
            //Push operator when stack is empty
            if (operators.empty())
                operators.push(ch);
            //If the current operators is of hugher precedence then push it onto the stack
            else if (value(ch) > value(operators.top()))
                operators.push(ch);
            //Pop all operators when the current operator is of lower or equal precedence than the oeprator on the top of the stack
            else
            {
                while (!operators.empty() && value(ch) <= value(operators.top()))
                {
                    result += operators.top();
                    operators.pop();
                }
                operators.push(ch);
            }
        }
    }
        
    //Pop and add all operators when the string has been fully parsed
    while(!operators.empty())
    {
        result += operators.top();
        operators.pop();
    }
    return result;
}