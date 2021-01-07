#include "codeWars.h"
#include <cmath>

int last_digit(const std::string& str1, const std::string& str2)
{
    //Only the last digit of str1 matters
    auto x = int(str1[str1.length() - 1] - '0');

    //switch on x for length of repeating last digit
    int len = 0;

    switch (x)
    {
    case 0:
    case 1:
    case 5:
    case 6: len = 1; break;
    case 4:
    case 9: len = 2; break;
    case 2:
    case 3:
    case 7:
    case 8: len = 4; break;
    }

    //max length of repeating last digit is 4 so only interested in the last two digits of string 2
    //and take the modulo of the length of the repeat
    std::string temp;
    if (str2.length() > 1)
        temp = str2.substr(str2.length() - 2, 2);
    else
        temp = str2.substr(0, 1);

    auto y = int(std::stoi(temp)) % len;

    //only want y to be 0 is the input was 0, else set it to the length of the repeat
    if (y == 0 && temp != "0")
        y = len;

    //return the last digit of x ^ y
    temp = std::to_string(int(std::pow(x, y)));
    return  int(temp[temp.length() - 1] - '0');
}