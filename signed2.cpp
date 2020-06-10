#include <string>

using namespace std;

string signed2(string bin)
{
	// Find signed 1 of the binary string
	// add '1' to that to make signed 2
	string signed1 = StrBinNOT(bin);
	string signed2 = add(signed1, "1");
	return signed2
}