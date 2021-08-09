#include "lcs.h"

std::pair <std::string, long long> lcs(std::string str1, std::string str2)
{
	//Remember starting positions of substrings where a match was found
	std::stack<unsigned long long> last1;
	std::stack<unsigned long long> last2;

	//Current positions in both strings
	unsigned long long pos1 = 0;
	unsigned long long pos2 = 0;

	//Current sub sequence
	unsigned long long len = 0;
	std::string res = "";

	//Longest sub sequence
	unsigned long long max = 0;
	std::string maxRes = "";

	//Starting positions of entire strings
	last1.push(0);
	last2.push(0);

	//Iterate over string 1. This will happen many times depending on starting positions found.
	bool iterateStr1 = true;
	while (iterateStr1)
	{
		//Iterate over string 2.  This will also happen many times depending on starting positions found
		bool iterateStr2 = true;
		while (iterateStr2)
		{
			//Found an in order match
			if (str1[pos1] == str2[pos2])
			{
				//Add to the current subsequence
				++len;
				res += str1[pos1];

				//Add position of character after the match to the starting positions of searchable substrings
				last1.push(pos1 + 1);
				last2.push(pos2 + 1);

				//Set the position of the string 2 iteration to the start of the next substring
				pos2 = last2.top();
				iterateStr2 = false;
			}
			else
			{
				//If no match, continue along string 2 
				++pos2;

				//If reaching the end of string 2 set the current position to the start of the last substring
				//to continue searching for more values from string 1
				if (pos2 == str2.length())
				{
					pos2 = last2.top();
					iterateStr2 = false;
				}
			}

		}

		//Check the next value from string 1
		++pos1;

		//Reached the end of string 1
		if (pos1 == str1.length())
		{
			//Update max sub sequence if needed
			if (len >= max)
			{
				max = len;
				maxRes = res;
			}

			//The next substring will ignore the last found match
			res = res.substr(0, res.length() - 1);
			--len;

			//If the last match was the end of either string simply remove it
			if (last1.top() == str1.length() || last2.top() == str2.length())
			{
				last1.pop();
				last2.pop();
				--len;
				res = res.substr(0, res.length() - 1);
			}

			//Set the position in string one to the start of the last found substring and then remove that starting position
			pos1 = last1.top();
			last1.pop();

			//If there is something to search for a match, set the starting position of string 2 to the previous previous starting position
			//Else we have searched the entiriety of string 1
			if (last1.size() > 0)
			{
				last2.pop();
				pos2 = last2.top();
			}
			else
				iterateStr1 = false;
		}
	}

	return { maxRes, max };
}
