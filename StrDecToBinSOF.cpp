/*  
Here's how you do it. Start with an empty stack of binary digits. 
Then loop until the number is "0" (yes, that's still a string). 
If the last digit of the number is odd, push 1 on to the stack, otherwise push 0. 
Then divide the number by two and restart the loop.
Once the loop is finished (number is "0"), pop the digits off the stack one at a time and print them.

Set next_additive to 0.
    For every digit in number(starting at the left) :
        Set additive to next_additive.
        If the digit is odd, set next_additive to 5, else set it to 0.
        Divide the digit by two(truncating) then add additive.
    Remove leading zero if necessary(if it starts with 0 but is not just 0). */

#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

int OddsToOne(char src)
{
    switch (src)
    {
    case '1':
        return 1;
        break;
    case '3':
        return 1;
        break;
    case '5':
        return 1;
        break;
    case '7':
        return 1;
        break;
    case '9':
        return 1;
        break;
    default:
        return 0;
    }
}

string StrDivTwo(string src)
{
    int additive = 0;
    int next_additive = 0;
    for (int i = 0; i < src.length(); i++)
    {
        next_additive = OddsToOne(src[i]) * 5;
        src[i] = (((src[i] - '0') / 2) + additive) + '0';
        additive = next_additive;
    }
    while (src[0] == '0')
    {
        src.erase(src.begin());
    }
    return src;
}

string StrDecToBin(string src)
{
    string result = "";
    /*while (!src.empty())
    {
        result = OddsToOne((src[src.length() - 1] - '0')) + '0';
        src = StrDivTwo(src);
    }*/
    while (!src.empty())
    {
        result.push_back((src[src.length() - 1] - '0') % 2 + '0');
        src = StrDivTwo(src);
    }

    reverse(result.begin(), result.end());
    return result;
}


int main()
{
    string test = "1024";
    string converted = StrDecToBin(test);
    test = StrDivTwo(test);
    cout << converted << endl;
    cout << test << endl;
    system("pause");
    return 0;
}