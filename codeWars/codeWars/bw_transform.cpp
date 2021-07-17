#include "bw_transform.h"

#include <iostream>
#include <vector>

std::pair<std::string, int> encode(const std::string& s) {

	std::vector<std::string> matrix;
	std::string str = s;
	std::rotate(str.rbegin(), str.rbegin() + 1, str.rend());
	std::cout << str;
	return { "", 0 };
}

std::string decode(const std::string& s, int n) {
	return "";
}