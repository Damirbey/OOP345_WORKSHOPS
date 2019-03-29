/***************************************
Name: Damirkhon Yodgorov

Student Id: 108364175

Seneca email: dyodgorov@myseneca.ca

Date of completion: 2018-10-04

***************************************/

#ifndef W4_MESSAGE_H__
#define W4_MESSAGE_H__
#include <string>

#include <fstream>

namespace w4{


	class Message { // message class declaration
	
		std::string message;

		
		void gothrow(std::string buffer, char c); // function goes throw the passed string and inserts result into the message;
	public:
		Message(); // default constructor

		
		Message(std::ifstream& in, char c); // constructor with one parameter

		bool empty() const; // bool operator returns true if object is in safe empty state

		void display(std::ostream& ost) const; // displays contents of the message string to the user
	};

}

#endif