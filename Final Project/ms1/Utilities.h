/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date:14.11.2018
*****************************************/

#ifndef UTILITIES_H
#define UTILITIES_H
#include<fstream>
#include<string>
const unsigned int CODE_WIDTH = 5;
class Utilities
{

	size_t m_widthField; //specifying the length of the token extracted; used for display purpose 
	static char m_delimiter; // separates the tokens from a given std::string.

public:
	Utilities();
	void setFieldWidth(size_t);
	size_t getFieldWidth() const;
	const std::string extractToken(const std::string&, size_t&, bool&);
	static void setDelimiter(const char);
	const char getDelimiter() const; // defing getDelimiter function



};

#endif