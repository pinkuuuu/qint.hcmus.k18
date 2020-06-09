#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

string StrHexToBin(string hex)
{
    string temp;
    for (int i = 0; i < hex.length(); i++)
        switch (hex[i])
        {
        case '0':
            temp += "0000";
            break;
        case '1':
            temp += "0001";
            break;
        case '2':
            temp += "0010";
            break;
        case '3':
            temp += "0011";
            break;
        case '4':
            temp += "0100";
            break;
        case '5':
            temp += "0101";
            break;
        case '6':
            temp += "0110";
            break;
        case '7':
            temp += "0111";
            break;
        case '8':
            temp += "1000";
            break;
        case '9':
            temp += "1001";
            break;
        case 'A':
        case 'a':
            temp += "1010";
            break;
        case 'B':
        case 'b':
            temp += "1011";
            break;
        case 'C':
        case 'c':
            temp += "1100";
            break;
        case 'D':
        case 'd':
            temp += "1101";
            break;
        case 'E':
        case 'e':
            temp += "1110";
            break;
        case 'F':
        case 'f':
            temp += "1111";
            break;
        }
    return temp;
}

int main()
{
    string hex = "5AF3";
    string neww = StrHexToBin(hex);
    for (int i = 0; i <= neww.length(); i++)
    {
        cout << neww[i];
    }
    return 0;
    system("pause");
}
