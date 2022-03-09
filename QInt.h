#pragma once
#include <iostream>
#include <string>
#include "Tokenizer.h"

using namespace std;

class QInt
{
private:
	long long arrayBits1[2];
	long long arrayBits2[2];
	string typeinput;
	string typeoutput;
	string operation;
public:
	string Action(string input);
	void Div(string bin, long long arraybit[]);
	string ToString(long long a[]);
};