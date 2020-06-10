#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

// Hàm NOT chuỗi nhị phân
string StrBinNOT(string src)
{
	string result = "";
	for (int i = 0; i < src.length(); i++)
		if (src[i] == '1') // Tìm bit 1 rồi đảo ngược
			result.push_back('0');
		else // Tìm bit 0 rồi đảo ngược
			result.push_back('1');
	return result;
}

// Hàm AND chuỗi nhị phân
string StrBinAND(string src1, string src2)
{
	string result = "";
	int temp = 0;
	for (int i = 0; i < src1.length(); i++)
	{
		temp = (src1[i] - '0') + (src2[i] - '0'); // cộng 2 bit của 2 chuỗi
		if (temp == 2)	// 2 bit 1 thì ra 1
			result.push_back('1');
		else // còn lại ra 0
			result.push_back('0');
	}
	return result;
}

// Hàm OR chuỗi nhị phân
string StrBinOR(string src1, string src2)
{
	string result = "";
	int temp = 0;
	for (int i = 0; i < src1.length(); i++) 
	{
		temp = (src1[i] - '0') + (src2[i] - '0'); // cộng 2 bit của 2 chuỗi
		if (temp == 0)	// 2 bit 0 thì ra 0
			result.push_back('0');
		else // còn lại ra 1
			result.push_back('1');
	}
	return result;
}

// Hàm XOR chuỗi nhị phân
string StrBinXOR(string src1, string src2)
{
	string result = "";
	int temp = 0;
	for (int i = 0; i < src1.length(); i++)
	{
		temp = (src1[i] - '0') + (src2[i] - '0'); // cộng 2 bit của 2 chuỗi
		if (temp == 1)	// 2 bit khác nhau thì ra 1
			result.push_back('1');
		else // giống nhau ra 0
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