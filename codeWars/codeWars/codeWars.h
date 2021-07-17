#pragma once
#include <string>
#include <vector>
int last_digit(const std::string&, const std::string&);

// Construct a function that, when given a string containing an expression in infix notation, will return an identical expression in postfix notation.
// The operators used will be +, -, *, /, and ^ with left-associativity of all operators but ^.
// The precedence of the operators (most important to least) are : 1) parentheses, 2) exponentiation, 3) times/divide, 4) plus/minus.
// The operands will be single-digit integers between 0 and 9, inclusive.
// Parentheses may be included in the input, and are guaranteed to be in correct pairs.

// to_postfix("2+7*5") // Should return "275*+"
// to_postfix("3*3/(7+1)") // Should return "33*71+/"
// to_postfix("5+(6-2)*9+3^(7-1)") // Should return "562-9*+371-^+"
// to_postfix("1^2^3") // Should return "123^^"
std::string infixToPostfix(std::string);

bool path_finder(std::string maze);

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map);