#pragma once
#include <vector>
#include <string>

using namespace std;

class Tokenizer
{
public:
	static vector<string> Parse(string line, string seperator);
};

