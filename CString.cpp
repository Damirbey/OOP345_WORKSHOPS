/*
Name: Damirkhon Yodgorov

Student Id: 108364175

*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
#include"CString.h"


namespace w1
{
	//default constructor definition
	CString::CString() :number_of_characters{ 0 }
	{
		string = nullptr;
	}

	//definition for the constructor with the one  argument
	CString::CString(char *name) : number_of_characters{ 3 }
	{
			if (name != nullptr)
			{
				string = new char[number_of_characters];
				strncpy(string, name, number_of_characters);
				string[number_of_characters] = char(0);
				
			
			}
			else
				string = nullptr;
		


	}


	//definition for the display function

	void CString::display(std::ostream &os)const
	{
		static int counter = 0;
		os << counter << ": ";
		os << string <<std::endl;
		counter++;
	}


	//definition for the helper operator 
	std::ostream& operator<<(std::ostream &lhs, const CString&rhs)
	{
		rhs.display(lhs);		
		return lhs;
	}



}
