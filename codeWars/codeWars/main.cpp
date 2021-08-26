// powers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
#include "RepresentAsSquares.h"

int main()
{
    auto result = RepresentAsSquares(11);
    for (auto i : result)
        std::cout << i << "\n";
}		
