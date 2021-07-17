#include "codeWars.h"

//Enumeration to keep track of the direction iterating through the n * n grid
enum class dirs {
	right,
	left,
	up,
	down,
	none

};

dirs& operator++ (dirs& dir)
{
	switch (dir)
	{
	case dirs::right: return dir = dirs::down;
	case dirs::left: return dir = dirs::up;
	case dirs::up: return dir = dirs::right;
	case dirs::down: return dir = dirs::left;
	default: return dir = dirs::none;
	}
}

// For each direction iterate along each row or column and add each [row][col] value to the resulting array
void helper(const std::vector<std::vector<int>>& snail_map, std::vector<int>& arr, size_t& start, size_t& end, int& row, int& col, dirs& dir)
{
	if (start > end)
		std::swap(start, end);

	while (start <= end)
	{

		if (dir == dirs::right)
			++col;
		else if (dir == dirs::left)
			--col;
		else if (dir == dirs::up)
			--row;
		else
			++row;

		arr.push_back(snail_map[row][col]);

		++start;
	}
}

std::vector<int> snail(const std::vector<std::vector<int>>& snail_map)
{
	if (snail_map[0].size() == 1)
		return { snail_map[0][0] };

	std::vector<int> arr;
	dirs dir(dirs::right);
	int row = 0;
	int col = -1;

	//For each row or column along the route find the starting and ending indices and pass them into the helper function

	for (size_t n = snail_map.size(), curEnd = 0, numEnds = n * 2 - 2, offset = 0, start = 0, end = 0; curEnd < numEnds; ++curEnd)
	{
		//start and end will always be the same for every array
		if (curEnd == 0)
		{
			start = 0;
			end = n - 1;
		}
		//The last row  will go right to left for arrays with an even n, and left to right for array with an odd n.
		//Adjusting the row and column values isn't very pretty.
		else if (curEnd == numEnds - 1)
		{

			if (n % 2 == 0)
			{
				dir = dirs::left;
				++row;
				++col;
				start = n - 1 - offset;
				end = n - 1 - (offset + 1);
			}
			else
			{
				dir = dirs::right;
				--row;
				--col;
				start = n - 1 - (offset + 1);
				end = n - 1 - offset;
			}
		}
		else if (curEnd % 4 == 1)
		{
			++offset;
			start = offset;
			end = n - offset;
		}
		else if (curEnd % 4 == 2)
		{
			start = n - 1 - offset;
			end = offset - 1;
		}
		else if (curEnd % 4 == 3)
		{
			start = n - 1 - offset;
			end = offset;
		}
		else if (curEnd % 4 == 0)
		{
			start = offset;
			end = n - 1 - offset;
		}

		helper(snail_map, arr, start, end, row, col, dir);

		++dir;
	}

	return arr;
}