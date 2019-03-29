/*
Name: Damirkhon Yodgorov

Student Id: 108364175

*/
#ifndef _W1_CSTRING_H
#define _W1_CSTRING_H
#include<iostream>

namespace w1
{
	extern const int MAX;
	class CString
	{
		const int number_of_characters;  //constant definition for the number of characters to be stored by the object
		char *string;
		

	public:
		CString();
		CString(char*);// constructor to store first MAX characters of the string
		void display(std::ostream &os)const;

	};

	std::ostream & operator<<(std::ostream &lhs, const CString &rhs);

}

#endif