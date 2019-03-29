/*************************************
 Name: Damirkhon Yodgorov 
 Student Id: 108364175
 Seneca email: dyodgorov@myseneca.ca
 Date: 2018-10-10
*************************************/
#include <iostream>
namespace sict
{
	/***************************************************************/
	//Enumerator declaration

	enum  Letter{one,two,three,four,five,six,seven,eight,nine}; 

	/**************************************************************/
	
	
	/*********************************************************/
	template <typename T>

	const char* Convert(const T& Letter)
	{
		const char* str=nullptr;
		switch (Letter)
		{
		case one:
			str = "F   ";
		    break;
		case two:
			str = "D   ";
			break;
		case three:
			str = "D+  ";
			break;
		case four:
			str = "C   ";
			break;
		case five:
			str = "C+  ";
			break;
		case six:
			str = "B   ";
			break;
		case seven:
			str = "B+  ";
			break;
		case eight:
			str = "A   ";
			break;
		case nine:
			str = "A+  ";
			break;
		default:
			str = "Not Valid";

		}
		
		return str;
	}

	

}

