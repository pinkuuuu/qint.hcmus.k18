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

//Hàm kiểm tra số lẻ
int OddsToOne(char src)
{
    switch (src)
    {
    case '1':
    case '3':
    case '5':
    case '7':
    case '9':
        return 1;
        break;
    default:
        return 0;
    }
}

//Hàm chia đôi giá trị trong chuỗi
string StrDivTwo(string src)
{
    int additive = 0;
    int next_additive = 0;
    for (int i = 0; i < src.length(); i++)
    {
        next_additive = OddsToOne(src[i]) * 5;              //gán biến nhớ tiếp theo, số lẻ thì bằng 5, chẵn thì 0
        src[i] = (((src[i] - '0') / 2) + additive) + '0';   //lấy chữ số thứ i chia 2 và cộng thêm biến nhớ
        additive = next_additive;
    }
    while (src[0] == '0')
    {
        src.erase(src.begin());     //xóa số 0 đầu dòng
    }
    return src;
}

string StrDecToBin(string src)
{
    string result = "";

    while (!src.empty())
    {
        result.push_back((src[src.length() - 1] - '0') % 2 + '0'); //chuyển số cuối sang bit
        src = StrDivTwo(src); //chia đôi giá trị trong chuỗi số
    }

    reverse(result.begin(), result.end()); //đảo ngược chuỗi
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