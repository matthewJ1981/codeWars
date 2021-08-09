#include "subArrays.h"
#include <deque>
#include <iostream>

void Insert(std::deque<int>& d, int arr[], int i)
{
	bool inserting = true;
	while (inserting)
	{
		if (!d.empty() && arr[d.back()] < arr[i])
			d.pop_back();
		else
			inserting = false;
	}

	d.push_back(i);

}

void PrintMaxSubArrays(int arr[], int n, int k)
{
	std::deque<int> d;
	for (int i = 0; i < k; ++i)
		Insert(d, arr, i);

	for (int i = k; i < n; ++i)
	{
		std::cout << arr[d.front()];
		while (!d.empty() && d.front() <= i - k)
			d.pop_front();

		Insert(d, arr, i);
	}

	std::cout << arr[d.front()];

}