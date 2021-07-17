#include "bw_transform.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include "TimeAccumulator.h"

std::pair<std::string, int> encode(const std::string& s) {

	TimeAccumulator t;

	//string to hold permutations
	std::string str = s;

	std::cerr << "str: " << t.Mark() << "\n";

	//matrix of permutations, the first permutaiton is the original string
	std::vector<std::string> matrix{ str };
	//There will be s.length() permutations, the first one (s) is already stored

	std::cerr << "matrix: " << t.Mark() << "\n";

	for (std::size_t i = 0; i < s.length() - 1; ++i)
	{
		//Get the last permutation
		str = matrix.at(i);
		//Get the next permutation
		std::rotate(str.rbegin(), str.rbegin() + 1, str.rend());
		//Store the next permutation
		matrix.push_back(str);
	}

	//## Debug
	//for (const auto& s : matrix)
	//	std::cerr << s << "\n";
	//std::cerr << "\n";
	//Debug

	//Sort matrix by row
	std::sort(matrix.begin(), matrix.end());
	//Find the index of the original string
	auto index = std::find(matrix.begin(), matrix.end(), s) - matrix.begin();

	//## Debug
	//std::cerr << index << "\n\n";
	//
	//for (const auto& s : matrix)
	//	std::cerr << s << "\n";
	//std::cerr << "\n";
	//##

	//Construct a return string that consists of the last chracter of each row
	str = "";
	for (const auto& s : matrix)
		str += s.back();

	//## Debug
	//std::cerr << str << "\n";
	//##

	return { str, int(index) };
}

std::string decode(const std::string& s, int n) {
	
	//construct a matrix of s.length() empty strings
	std::vector<std::string> matrix{ s.length() };

	//Insert character j of s into the beginning of string j and sort s.length() times 
	for (size_t i = 0; i < s.length(); ++i)
	{
		for (size_t j = 0; j < matrix.size(); ++j)
		{
			matrix[j].insert(matrix[j].begin(), s.at(j));
		}

		std::sort(matrix.begin(), matrix.end());
	}

	//## Debug
	//for (const auto& s : matrix)
	//	std::cerr << s << "\n";
	//std::cerr << "\n";
	//Debug

	return matrix.at(n);
}