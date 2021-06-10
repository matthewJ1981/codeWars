// powers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "codeWars.h" 

int main()
{
    // to_postfix("2+7*5") // Should return "275*+"
// to_postfix("3*3/(7+1)") // Should return "33*71+/"
// to_postfix("5+(6-2)*9+3^(7-1)") // Should return "562-9*+371-^+"
// to_postfix("1^2^3") // Should return "123^^"
    /*std::cout << infixToPostfix("2+7*5") << "\n";
    std::cout << infixToPostfix("3*3/(7+1)") << "\n";*/
    std::cout << infixToPostfix("5+(6-2)*9+3^(7-1)") << "\n";
    std::cout << infixToPostfix("1^2^3") << "\n";
}
