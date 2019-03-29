// Workshop 5 - Lambda Expression
// 345_w5.cpp
// Chris Szalwinski & Dr. Elliott Coleshill
// 2018-08-22


#include <iostream>
#include "Grades.h"
#include "Letter.h"
using namespace sict;

int main(int argc, char* argv[]) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++)
		std::cout << argv[i] << ' ';
	std::cout << std::endl;

	if (argc == 1) {
		std::cerr << "\n*** Insufficient number of arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 1;
	}
	else if (argc != 2) {
		std::cerr << "\n*** Too many arguments ***\n";
		std::cerr << "Usage: " << argv[0] << " fileName \n";
		return 2;
	}

	//Update the main functions as per the specifications here
	try {
		Grades grades(argv[1]);
		
		const char*(*letter)(double) = [](double numerGr) {

			if (numerGr >= 90) { return Convert(nine); }
			else if (numerGr >= 80) { return Convert(eight); }
			else if (numerGr >= 75) { return Convert(seven); }
			else if (numerGr >= 70) { return Convert(six); }
			else if (numerGr >= 65) { return Convert(five); }
			else if (numerGr >= 60) { return Convert(four); }
			else if (numerGr >= 55) { return Convert(three); }
			else if (numerGr >= 50) { return Convert(two); }
			else if (numerGr >= 0) { return Convert(one); }
			else
			{
				throw"Some error occurs!";
			}
		};

		grades.displayGrades(std::cout, letter);

	}
	catch (const char*msg)
	{
		std::cout << msg;
	}
	;
	return 0;
	
}