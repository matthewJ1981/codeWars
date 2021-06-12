// powers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "codeWars.h" 

int main()
{
	
	std::cout << path_finder("......\n......\n......\n......\n......\n......") << "\n";
	std::cout << path_finder("......\n......\n......\n......\n.....W\n....W.") << "\n";
	std::cout << path_finder(".W.\n.W.\n...") << "\n";
	std::cout << path_finder(".W.\n.W.\nW..") << "\n";	
}
