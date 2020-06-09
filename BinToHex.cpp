#include <iostream>
#include <string>
using namespace std;

string BinToHex(string bin)
{
	string temp;
	string result = "";

	// Add '0's at beginning
	while (bin.size() % 4 != 0)
	{
		bin.insert(bin.begin(), '0');
	}

	int len = bin.length();
	for (int i = 0; i < len; i++)
	{
		temp.push_back(bin[i]);
		if (i % 4 == 3) // Pushed in 4 bit
		{
			if (temp == "0000") result.push_back('0');
			else if (temp == "0001") result.push_back('1');
			else if (temp == "0010") result.push_back('2');
			else if (temp == "0011") result.push_back('3');
			else if (temp == "0100") result.push_back('4');
			else if (temp == "0101") result.push_back('5');
			else if (temp == "0110") result.push_back('6');
			else if (temp == "0111") result.push_back('7');
			else if (temp == "1000") result.push_back('8');
			else if (temp == "1001") result.push_back('9');
			else if (temp == "1010") result.push_back('A');
			else if (temp == "1011") result.push_back('B');
			else if (temp == "1100") result.push_back('C');
			else if (temp == "1101") result.push_back('D');
			else if (temp == "1110") result.push_back('E');
			else if (temp == "1111") result.push_back('F');
			temp.clear();
		}
	}
	return result;
}

int main()
{
	string bin="1001010110110101";
	string result = BinToHex(bin);
	for (int i = 0; i < result.length(); i++)
	{
		cout << result[i];
	}
	return 0;
}