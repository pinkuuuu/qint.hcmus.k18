#include <iostream>
#include <string.h>
#include <Windows.h>
using namespace std;

// Hàm sao chép chuỗi
string StrCopy(string src)
{
	string temp = "";
	for (int i = 0; i < src.length(); i++)
	{
		temp.push_back(src[i]);
	}
	return temp;
}

//Hàm dịch trái chuỗi n đơn vị
string StrBinSHL(string src, int n)
{
	string temp = StrCopy(src);
	string result = "";
	for (int i = 0; i < n; i++)	// dịch n lần
	{
		for (int j = 0; j < temp.length(); j++)
		{
			result.push_back(temp[j + 1]);	// dịch giá trị phải sang trái 1 đơn vị
		}
		result[result.length() - 1] = '0';	//thêm 0 vào cuối chuỗi cho đủ số bit ban đầu
		temp.clear();	//xóa source để sao chép kết quả
		temp = StrCopy(result);	// sao chép kết quả làm source cho lần lặp kế tiếp(nếu có)
		result.clear();	//xóa kết quả để lần lặp kế tiếp có thể gán kết quả vào biến
	}
	return temp;
}

/*string StrBinSHR(string src, int n)
{
	string temp = StrCopy(src);
	string result = "";
	for (int i = 0; i < n; i++)
	{
		for (int j = temp.length() - 1; j > 0; j--)
		{
			result.push_back(temp[j - 1]);
		}
		result[result] = '0';
		temp.clear();
		temp = StrCopy(result);
		result.clear();
	}
	return temp;
}*/

// Hàm dịch phải chuỗi n đơn vị
string StrBinSHR(string src, int n)
{
	//đảo ngược chuỗi, dịch trái chuỗi, đảo ngược chuỗi lần nữa sẽ là dịch phải chuỗi
	reverse(src.begin(), src.end());	//đảo ngược chuỗi nguồn
	string result = StrBinSHL(src, n);	//dịch trái chuỗi nguồn
	reverse(result.begin(), result.end());	//đảo ngược chuỗi kết quả
	return result;
}

int main()
{
	string bin1 = "1011000";
	string bin2 = "110000101";
	cout << StrBinSHL(bin1, 1) << endl;
	cout << StrBinSHR(bin1, 1) << endl;
	cout << StrBinSHL(bin2, 1) << endl;
	cout << StrBinSHR(bin2, 1) << endl;
	system("pause");
	return 0;
}