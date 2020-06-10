#include <string>
#include <vector>

using namespace std;

// Strict num1 - num2
string subtract(string num1, string num2)
{
	string result = "";
	string x; // For larger number
	string y; // For smaller number
	
	// Assign larger number to x
	// add '0's in front of smaller number and assign it to y
	if (num1.length() >= num2.length())
	{
		while (num2.length() < num1.length())
		{
			num2.insert(num2.begin(), '0');
		}
		x = num1; y = num2;
	}
	else
	{
		while (num2.length() > num1.length())
		{
			num1.insert(num1.begin(), '0');
		}
		x = num2; y = num1;
		result.push_back('-');
	}
	
	// Store result in reverse order
	vector<int> reverse_R(x.length(), 0);

	// To find position in reverse result 
	int idx = 0;

	//Go from right to left on larger number
	for (int i = x.length() - 1; i >= 0; i--)
	{
		int carry = 0;
		int sub = 0;
		if (x[i] < y[i] + reverse_R[idx])
		{
			sub = 10 - y[i] + reverse_R[idx] + x[i];
			carry = 1;
		}
		else sub = x[i] - y[i] + reverse_R[idx];
		reverse_R[idx] = sub;
		idx++;
		if (carry > 0) reverse_R[idx] += carry;
	}

	// Ignoring '0's on the right
	int i = reverse_R.size() - 1;
	while (i >= 0 && reverse_R[i] == 0) i--;

	if (i == -1) return "0";

	// Add result in the right order
	while (i >= 0)
	{
		result += to_string(reverse_R[i]);
	}
	return result;
}