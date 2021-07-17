#include "bw_transform.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include "TimeAccumulator.h"
#include <map>
#include <list>
#include <set>

std::string rotate(std::string& str)
{
	size_t length = str.length();
	str = str[length - 1] + str.substr(0, length - 1);
	return str;
}

std::pair<std::string, int> encode(const std::string& s) {

	if (s == "")
		return { s, 0 };

	TimeAccumulator t;

	std::string str = s;
	//matrix of permutations, the first permutaiton is the original string
	std::set<std::string> matrix{ str };

	t.Mark("matrix");

	//There will be s.length() permutations, the first one (s) is already stored
	for (std::size_t i = 0; i < s.length() - 1; ++i)
		matrix.insert(rotate(str));

	t.Mark("permutations");

	//Find the index of the original string
	auto index = std::distance(matrix.begin(), std::find(matrix.begin(), matrix.end(), s));

	t.Mark("find");

	//Construct a return string that consists of the last chracter of each row
	str = "";
	for (const auto& s : matrix)
		str += s.back();

	t.Mark("result");
	t.Total();

	return { str, int(index) };
}

//find correct corresponding character from the last column of the matrix
size_t helper(std::vector<size_t>& T, size_t i, size_t n)
{
	if (i == 0)
		return T[n];

	else
		return T[helper(T, i - 1, n)];
}

std::string decode(const std::string& s, int n) {

	if (s == "")
		return s;

	TimeAccumulator t;

	//Store the alphabet used in the string with map containing the index of the last found occurence
	//of each letter in the first column on the matrix M
	std::map<char, int> alphabet;
	for (char c : s)
		alphabet.insert({ c, -1 });

	t.Mark("Alphabet");

	//Sorting the last column provide the first column of M
	std::string f = s;
	std::sort(f.begin(), f.end());

	t.Mark("f");

	//Develop a mapping from characters in the last column to characters in the first column
	//Update the alphabet map to keep track of last found indexes of each letter.
	//Add resulting index from the first column to a vector T
	std::vector<size_t> T;

	for (auto sIt = s.begin(); sIt != s.end(); ++sIt)
	{
		char sCh = *sIt;
		for (auto fIt = f.begin(); fIt != f.end(); ++fIt)
		{
			char fCh = *fIt;
			if (sCh == fCh)
			{
				int index = int(fIt - f.begin());
				if (index > alphabet[fCh])
				{
					alphabet[fCh] = index;
					T.push_back(index);
					break;
				}
			}
		}
	}

	//Use helper function to recursively search for the correct position of each character in the original string
	size_t length = s.length(); 
	std::string result(length - 1, '-');
	result += s[n];

	for (size_t i = 0; i < length - 1; ++i)
	{
		result[length - 2 - i] = s[helper(T, i, n)];
	}


	t.Mark("addsort");
	t.Total();

	return result;
}