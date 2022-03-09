#include "QInt.h"
#include <iostream>
#include <vector>

using namespace std;

string StrBinToDec(string bin);
string StrDecToBin(string src);

//Divide a 128 bits binary string into two 64 bits binary strings
void QInt::Div(string bin, long long arraybit[])
{
    string temp = bin;
    while (temp.length() < 128)
        temp = "0" + temp;
    string str1 = "";
    string str2 = "";
    for (int i = 0; i < 64; i++)
        str1 += temp[i];
    for (int i = 64; i < 128; i++)
        str2 += temp[i];
    long long inte1 = 0;
    long long inte2 = 0;
    long long Exp=1;
    for (int i = str1.length()-1; i >= 0; i--)
    {
        inte1 = inte1 + ((long long)str1[i] - 48) * Exp;
        inte2 = inte2 + ((long long)str2[i] - 48) * Exp;
        Exp *= 2;
    }
	arraybit[0] = inte1;
	arraybit[1] = inte2;
}

//QInt to string
string QInt::ToString(long long a[])
{
	string inte1 = to_string(a[0]);
	string inte2 = to_string(a[1]);
	string out = StrDecToBin(inte1) + StrDecToBin(inte2);
	return out;
}

string GenerateZero(string src)
{
	while (src.length() < 128)
	{
		src.insert(src.begin(), '0');
	}
	return src;
}

string DeleteZero(string src)
{
	while (src[0] == '0')
		src.erase(src.begin());
	return src;
}

//--------------------TOÁN TỬ TRÊN BIT--------------------
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

// Hàm NOT chuỗi nhị phân
string StrBinNOT(string src)
{
	src = GenerateZero(src);
	string result = "";
	for (int i = 0; i < src.length(); i++)
		if (src[i] == '1') // Tìm bit 1 rồi đảo ngược
			result.push_back('0');
		else // Tìm bit 0 rồi đảo ngược
			result.push_back('1');
	return result;
}

//Hàm dịch trái chuỗi n đơn vị
string StrBinSHL(string src, int n)
{
	string temp = src;
	string result = "";
	for (int i = 0; i < n; i++)    // dịch n lần
	{
		for (int j = 0; j < temp.length(); j++)
		{
			result.push_back(temp[j + 1]);    // dịch giá trị phải sang trái 1 đơn vị
		}

		result[result.length() - 1] = '0';    //thêm 0 vào cuối chuỗi cho đủ số bit ban đầu
		temp.clear();    //xóa source để sao chép kết quả
		temp = result;    // sao chép kết quả làm source cho lần lặp kế tiếp(nếu có)
		result.clear();    //xóa kết quả để lần lặp kế tiếp có thể gán kết quả vào biến
	}
	return temp;
}

// Hàm dịch phải chuỗi n đơn vị
string StrBinSHR(string src, int n)
{
	char sign = src[0];
	//đảo ngược chuỗi, dịch trái chuỗi, đảo ngược chuỗi lần nữa sẽ là dịch phải chuỗi
	reverse(src.begin(), src.end());	//đảo ngược chuỗi nguồn
	string result = StrBinSHL(src, n);	//dịch trái chuỗi nguồn
	reverse(result.begin(), result.end());	//đảo ngược chuỗi kết quả
	result[0] = sign;
	return result;
}

//rol
string StrBinROL(string src)
{
	char temp = src[0];
	string result = StrBinSHL(src, 1);
	result[result.length() - 1] = temp;
	return result;
}

//ror
string StrBinROR(string src)
{
	char temp = src[src.length() - 1];
	string result = StrBinSHR(src, 1);
	result[0] = temp;
	return result;
}


//--------------------PHÉP TÍNH--------------------
//Add Decimal
string addDec(string num1, string num2)
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

bool isSmaller(string str1, string str2)
{
	// Calculate lengths of both string 
	int n1 = str1.length(), n2 = str2.length();

	if (n1 < n2)
		return true;
	if (n2 < n1)
		return false;

	for (int i = 0; i < n1; i++)
		if (str1[i] < str2[i])
			return true;
		else if (str1[i] > str2[i])
			return false;

	return false;
}

//Subtract Decimal
string subtractDec(string num1, string num2)
{
	string result = "";
	string x; // For larger number
	string y; // For smaller number

	// Assign larger number to x
	// add '0's in front of smaller number and assign it to y
	if (isSmaller(num1, num2))
	{
		while (num2.length() > num1.length())
		{
			num1.insert(num1.begin(), '0');
		}

		x = num2; // larger
		y = num1;

		result.push_back('-');
	}
	else
	{
		while (num2.length() < num1.length())
		{
			num2.insert(num2.begin(), '0');
		}

		x = num1; // larger
		y = num2;
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
		if ((x[i] - '0') < ((y[i] - '0') + reverse_R[idx]))
		{
			sub = (10 - ((y[i] - '0') + reverse_R[idx])) + (x[i] - '0');
			carry = 1;
		}
		else sub = (x[i] - '0') - ((y[i] - '0') + reverse_R[idx]);
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
		result += to_string(reverse_R[i--]);
	}
	return result;
}

//Multiply Decimal
string multiplyDec(string num1, string num2)
{
	string temp1 = num1;
	string temp2 = num2;
	bool Negative = false;

	if (num1[0] == '-')
	{
		temp1.erase(temp1.begin());
		Negative = !Negative;
	}
	if (num2[0] == '-')
	{
		temp2.erase(temp2.begin());
		Negative = !Negative;
	}

	num1 = temp1;
	num2 = temp2;

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

	if (Negative)
	{
		s.insert(s.begin(), '-');
	}

	return s;
}

//Add Binary
string addBin(string bin1, string bin2)
{
	while (bin1.length() < 128)
		bin1 = "0" + bin1;
	while (bin2.length() < 128)
		bin2 = "0" + bin2;

	int carry = 0;
	vector<int> sum;
	int temp = 0;
	for (int i = 127; i >= 0; i--)
	{
		temp = ((bin1[i] - '0') ^ (bin2[i] - '0')) ^ carry;
		sum.push_back(temp);
		carry = ((bin1[i] - '0') & (bin2[i] - '0')) | (carry & ((bin1[i] - '0') ^ (bin2[i] - '0')));
	}

	int i = sum.size() - 1;
	string result = "";

	// Add result into string
	while (i >= 0)
	{
		result += to_string(sum[i--]);
	}

	return result;
}

string signed2(string bin)
{
	while (bin.length() < 128)
		bin = "0" + bin;
	// Find signed 1 of the binary string
	// add '1' to that to make signed 2
	string signed1 = StrBinNOT(bin);
	string WAN = "1";
	while (WAN.length() < 128)
		WAN = "0" + WAN;
	string signed2 = addBin(signed1, WAN);
	return signed2;
}

//Subtract Binary
string subtractBin(string bin1, string bin2)
{
	bin2 = signed2(bin2);
	return addBin(bin1, bin2);
}

//Divide Binary
string divideBinaryString(string QInt1, string QInt2)
{
	bool Negative = false;
	string num1 = StrBinToDec(QInt1);
	string num2 = StrBinToDec(QInt2);

	if (num1[0] == '-')
	{
		num1.erase(num1.begin());
		Negative = !Negative;
	}
	if (num2[0] == '-')
	{
		num2.erase(num2.begin());
		Negative = !Negative;
	}
	QInt1 = StrDecToBin(num1);
	QInt2 = StrDecToBin(num2);

	int k = 128;

	while (QInt1.length() < 128)
		QInt1 = "0" + QInt1;
	while (QInt2.length() < 128)
		QInt2 = "0" + QInt2;

	string A = "";
	string Q = QInt1;
	string DecQ = StrBinToDec(Q);

	if (DecQ[0] != '-') // xét Q > 0
	{
		while (A.length() < 128)
			A = "0" + A;
	}
	else if (DecQ[0] == '-') // xét Q < 0
	{
		while (A.length() < 128)
			A = "1" + A;
	}
	while (k > 0)
	{
		//shift left A,Q
		A = StrBinSHL(A, 1);
		A[127] = Q[0];
		Q = StrBinSHL(Q, 1);

		// A = A - M
		A = subtractBin(A, QInt2);
		string DecA = StrBinToDec(A);

		if (DecA[0] == '-')
		{
			Q[127] = '0';

			A = addBin(A, QInt2);
		}
		else
		{
			Q[127] = '1';
		}
		k -= 1;
	}
	string result = StrBinToDec(Q);
	if (Negative)
	{
		result.insert(result.begin(), '-');
	}
	return result;
}

//--------------------CHUYỂN ĐỔI HỆ SỐ--------------------
//16->2
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
	temp = GenerateZero(temp);
	return temp;
}

//2->16
string StrBinToHex(string bin)
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

//2->10
string StrBinToDec(string bin)
{
	bin = GenerateZero(bin);
	string base = "1"; // Base value

	int binLen = bin.length();

	string dec = "0";

	// Go for right to left on binary string
	for (int i = binLen - 1; i >= 0; i--)
	{
		// Bit = 1 add base to result
		if (bin[i] - 48 == 1)
		{
			if (i == 0)
			{
				dec = subtractDec(dec, base);
			}
			else
				dec = addDec(dec, base);
		}

		// Multiply base with 2
		base = multiplyDec(base, "2");
	}

	return dec;
}

//10->2
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
	bool Negative = false;
	if (src[0] == '-')
	{
		Negative = true;
		src.erase(src.begin());
	}

	while (!src.empty())
	{
		result.push_back((src[src.length() - 1] - '0') % 2 + '0'); //chuyển số cuối sang bit
		src = StrDivTwo(src); //chia đôi giá trị trong chuỗi số
	}

	reverse(result.begin(), result.end()); //đảo ngược chuỗi

	while (result.length() < 128)
		result = "0" + result;

	if (Negative)
		result = signed2(result);
	return result;
}

//Constructor
string QInt::Action(string input)
{
	string temp = "";
	string type;
	for (int i = 0; i < input.length(); i++)
	{
		if (input[i + 1] == 114 or input[i + 1] == 82)
		{
			type += input[i + 1];
			type += input[i + 2];
			type += input[i + 3];
			temp += input[i];
			temp += type;
			i += 4;
		}
		else if (input[i + 1] == 60 or input[i + 1] == 62)
		{
			type += input[i + 1];
			type += input[i + 2];
			temp += type;
			i += 3;
		}
		else if ((input[i + 1] == 42 or input[i + 1] == 43 or input[i + 1] == 45 or input[i + 1] == 47 or input[i + 1] == 38 or input[i + 1] == 124 or input[i + 1] == 94) and input[i] == 32 and input[i + 2] == 32)
		{
			type = input[i + 1];
			temp += type;
			i += 2;
		}
		else if (input[i + 1] == 126)
		{
			type = input[i + 1];
			temp += input[i];
			temp += input[i + 1];
			i += 2;
		}
		else temp += input[i];
	}

	vector<string> tokens = Tokenizer::Parse(temp, " ");

	if (tokens.size() == 2)
		this->typeinput = this->typeoutput = tokens[0];
	else
	{
		this->typeinput = tokens[0];
		this->typeoutput = tokens[1];
	}

	vector<string> data;
	data.push_back("0");
	if (type != "")
		data = Tokenizer::Parse(tokens[tokens.size() - 1], type);
	else
	{
		data.push_back(tokens[tokens.size() - 1]);
	}

	if (type == "<<" or type == ">>")
	{
		if (tokens[0] == "10")
			data[0] = StrDecToBin(data[0]);
		else if (tokens[0] == "16")
			data[0] = StrHexToBin(data[0]);
	}
	else if (tokens[0] == "10")
	{
		if (data[0] != "")
			data[0] = StrDecToBin(data[0]);
		if (data[1] != "")
			data[1] = StrDecToBin(data[1]);
	}
	else if (tokens[0] == "16")
	{
		if (data[0] != "")
			data[0] = StrHexToBin(data[0]);
		if (data[1] != "")
			data[1] = StrHexToBin(data[1]);
	}

	if (type[0] == 114 or type[0] == 126 or type[0] == 0)
		Div(data[1], this->arrayBits1);
	else
	{
		Div(data[0], this->arrayBits1);
		Div(data[1], this->arrayBits2);
	}
	this->operation = type;

	/*string bit1 = ToString(arrayBits1);
	string bit2 = ToString(arrayBits2);*/

	string bit1 = data[0];
	string bit2 = data[1];
	string result;

	if (type == "&")
		result = StrBinAND(bit1, bit2);
	else if (type == "|")
		result = StrBinOR(bit1, bit2);
	else if (type == "^")
		result = StrBinXOR(bit1, bit2);
	else if (type == "~")
		result = StrBinNOT(bit2);
	else if (type == "<<")
		result = StrBinSHL(bit1, stoi(bit2));
	else if (type == ">>")
		result = StrBinSHR(bit1, stoi(bit2));
	else if (type == "rol")
		result = StrBinROL(GenerateZero(bit2));
	else if (type == "ror")
		result = StrBinROR(GenerateZero(bit2));
	else if (type == "+")
		result = addBin(bit1, bit2);
	else if (type == "-")
		result = subtractBin(bit1, bit2);
	else if (type == "*")
		result = StrDecToBin(multiplyDec(StrBinToDec(bit1), StrBinToDec(bit2)));
	else if (type == "/")
		result = StrDecToBin(divideBinaryString(bit1, bit2));
	else if (type == "")
		result = bit2;

	result = DeleteZero(result);
	if (this->typeoutput == "10")
		result = StrBinToDec(result);
	else if (this->typeoutput == "16")
		result = StrBinToHex(result);
	return result;
}