#include <iostream>
#include <string>
#include <vector>
using namespace std;

string multiply(string num1, string num2)
{
	int len1 = num1.length();
	int len2 = num2.length();
	
	// Keep result number in reverse order
	vector<int> result(len1 + len2, 0);

	// Below two indexes to find positions in result
	int idx_n1 = 0;
	int idx_n2 = 0;

	// Go from right to left in num1
	for (int i = len1 - 1; i >= 0; i--)
	{
		int n1 = num1[i] - 48; // Last digit of num1
		int carry = 0;
		
		// To shift position to left after every multiplication
		// of a digit of num2
		idx_n2 = 0;

		// Go from right to left in num2
		for (int j = len2 - 1; j >= 0; j--)
		{
			int n2 = num2[j] - 48; // Last digit of num2

			// Multiply with current digit of first number
			// and add result to previously stored result
			// at current position
			int sum = n1 * n2 + result[idx_n1 + idx_n2] + carry;

			carry = sum / 10;

			// Store result
			result[idx_n1 + idx_n2] = sum % 10;

			// Shift position to left after every
			// multiplication of a digit of num2
			idx_n2++;
		}

		if (carry > 0)
		{
			result[idx_n1 + idx_n2] += carry;
		}

		// Shift position to left after every
		// multiplication of a digit of num1
		idx_n1++;
	}

	int i = result.size() - 1;

	// Ignoring '0's on the right
	while (i >= 0 && result[i] == 0) i--;
	if (i == -1) return "";

	// Add result into string
	string s = "";
	while (i >= 0)
	{
		s += to_string(result[i--]);
	}

	return s;
} 

string add(string num1, string num2)
{
	int len1 = num1.length();
	int len2 = num2.length();
	int len;

	// Find larger length between num1 and num2
	// and add "0"s in front of number with smaller length
	if (len1 >= len2)
	{
		len = len1;
		while (num1.length() > num2.length())
		{
			num2.insert(num2.begin(), '0');
		}
	}
	else
	{
		len = len2;
		while (num1.length() < num2.length())
		{
			num1.insert(num1.begin(), '0');
		}
	}

	// Store result in reverse order
	vector<int> result(len1 + len2, 0);

	// Below index to find positions in result
	int idx = 0;
	
	// Go right to left on larger length
	for (int i = len - 1; i >= 0; i--)
	{
		int carry = 0;
		int n1 = num1[i] - 48;
		int n2 = num2[i] - 48;

		int sum = n1 + n2 + result[idx];
		carry = sum / 10;
		result[idx] = sum % 10;
		idx++;
		if (carry > 0)
		{
			result[idx] += carry;
		}
	}

	int i = result.size() - 1;

	// Ignoring "0"s on the right
	while (i >= 0 && result[i] == 0) i--;
	if (i == -1) return "";

	// Add result into string
	string s = "";
	while (i >= 0)
	{
		s += to_string(result[i--]);
	}
	
	return s;
}

string BinToDec(string bin)
{
	string base = "1"; // Base value

	int binLen = bin.length();
	
	string dec = "0";

	// Go for right to left on binary string
	for (int i = binLen - 1; i >= 0; i--)
	{
		// Bit = 1 add base to result
		if (bin[i] - 48 == 1)
		{
			dec = add(dec, base);
		}

		// Multiply base with 2
		base = multiply(base, "2");
	}

	return dec;
}

int main()
{
	string bin = "111101000001000000000000000101000111011001010010010000000000111";
	string result = BinToDec(bin);
	int len = result.length();
	for (int i = 0; i < len; i++)
	{
		cout << result[i];
	}
	return 0;
}