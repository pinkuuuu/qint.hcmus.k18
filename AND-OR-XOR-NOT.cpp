#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

string StrBinNOT(string src)
{
	string result = "";
	for (int i = 0; i < src.length(); i++)
		if (src[i] == '1')
			result.push_back('0');
		else
			result.push_back('1');
	return result;
}

string StrBinAND(string src1, string src2)
{
	string result = "";
	int temp = 0;
	for (int i = 0; i < src1.length(); i++)
	{
		temp = (src1[i] - '0') + (src2[i] - '0');
		if (temp == 2)
			result.push_back('1');
		else
			result.push_back('0');
	}
	return result;
}

string StrBinOR(string src1, string src2)
{
	string result = "";
	int temp = 0;
	for (int i = 0; i < src1.length(); i++)
	{
		temp = (src1[i] - '0') + (src2[i] - '0');
		if (temp == 0)
			result.push_back('0');
		else
			result.push_back('1');
	}
	return result;
}

string StrBinXOR(string src1, string src2)
{
	string result = "";
	int temp = 0;
	for (int i = 0; i < src1.length(); i++)
	{
		temp = (src1[i] - '0') + (src2[i] - '0');
		if (temp == 1)
			result.push_back('1');
		else
			result.push_back('0');
	}
	return result;
}

int main()
{
	string bin1 = "1101";
	string bin2 = "0111";
	cout << StrBinAND(bin1, bin2) << endl;
	cout << StrBinOR(bin1, bin2) << endl;
	cout << StrBinXOR(bin1, bin2) << endl;
	cout << StrBinNOT(bin1) << endl;
	system("pause");
	return 0;
}