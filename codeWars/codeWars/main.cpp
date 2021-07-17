// powers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "codeWars.h" 

int main()
{
	std::vector<std::vector<int>> v;
	v = { {1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7} };
	v = { {1,2,3}, {8,9,4}, {7,6,5} };
	v = { {1,2}, {4,3} };
	v = { {1} };

	auto result = snail(v);

	for (auto i : result)
	{
		std::cout << i;
		if (i != result.back())
			std::cout << ", ";
	}

	std::cout << "\n";
		
}		
