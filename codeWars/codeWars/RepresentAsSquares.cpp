#include "RepresentAsSquares.h"

bool recurse(std::vector<long long>& result, long long n, long long rem)
{
    // If remaining amount is zero then the original value can be represented
    // as a sum of squares.
    // If the remaining amount is less than 0, try the next lower square in 
    // the previous calling function
    // else this iteration may end up being succesful so continue
    // subtracting each successive lower square
    if (rem == 0)
        return true;
    else if (rem < 0 || n == 0)
        return false;
    else
    {
        // Subtract each square from the remaining amount 
        for (long long i = n; i > 0; --i)
        {
            // If the call returns true return up the call stack adding the
            // squares that resulted in succesfully representing the intital value
            if (recurse(result, i - 1, rem - i * i))
            {
                result.push_back(i);
                return true;
            }
        }

        return false;
    }
}

std::vector<long long> RepresentAsSquares(long long n)
{

    std::vector<long long> result{};

    // Try subtracting squares from n - 1 to 1, 
    // adding a succesful iteration to the result vector
    recurse(result, n - 1, n * n);

    return result;
}
