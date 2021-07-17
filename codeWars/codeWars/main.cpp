// powers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <assert.h>
#include "bw_transform.h" 

int main()
{
	const std::string s{ "bananabar" };
	auto encoded = encode(s);
	auto decoded = decode(encoded.first, encoded.second);
	
	assert(s == decoded);

	assert("bananabar"== decode( "nnbbraaaa", 4 ));
	assert("Humble Bundle" == decode( "e emnllbduuHB", 2 ));
	assert("Mellow Yellow" == decode("ww MYeelllloo", 1 ));
	
	assert(decode("nnbbraaaa", 4) == "bananabar");
	assert(decode("e emnllbduuHB", 2) =="Humble Bundle");
	assert(decode("ww MYeelllloo", 1) =="Mellow Yellow");
}		
