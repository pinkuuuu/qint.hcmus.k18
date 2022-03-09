#include <iostream>
#include <conio.h>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "QInt.h"

using namespace std;

int main(int argc, char* argv[])
{
	ifstream fileInput(argv[1]);
	ofstream fileOutput(argv[2]);
	string line_info;
	int i = 1;
	while (!fileInput.eof())
	{
		getline(fileInput, line_info, '\n');
		if (line_info == "")
			break;
		QInt a;
		fileOutput << a.Action(line_info) << endl;
	}
	fileInput.close();
	fileOutput.close();
}