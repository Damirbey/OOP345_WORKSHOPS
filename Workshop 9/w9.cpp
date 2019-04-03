// Workshop 9 - Multi-Threading
// w9.cpp
/************************************
Name: Damirkhon Yodgorov
Student Id : 108364175
Seneca e-mail: dyodgorov@myseneca.ca
Completion Date: 14.11.2018
*************************************/
#include <iostream>
#include <fstream>
#include <string>
#include "SecureData.h"
#include "SecureData.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Command Line: " << argv[0];
	for (int i = 1; i < argc; i++)
		cout << " " << argv[i];
	cout << endl << endl;

	if (argc != 4)
	{
		cerr << endl << "***Incorrect number of arguments***" << endl;
	
		return 1;
	}

	char key = argv[3][0];

	try {
		w9::SecureData sd(argv[1], key, &cout);
		sd.backup(argv[2]);

		sd.restore(argv[2], key);
		cout << sd << std::endl;

	}
	catch (const std::string& msg) {
		cout << msg << std::endl;
	}
	system("pause");
	return 0;
}
