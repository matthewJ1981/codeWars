#include "sumIntervals.h"

#include <map>

int sum_intervals(std::vector<std::pair<int, int>> intervals) {

    std::map<int, int> counted;

    for (const auto& interval : intervals)
    {
        for (int i = interval.first; i < interval.second; ++i)
        {
            counted[i] = 1;
        }
    }

    return counted.size();
}