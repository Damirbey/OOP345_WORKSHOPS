/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 24.11.2018
*****************************************/
// I confirm that I am the only author of this file

//   and the content was created entirely by me.

#include"Utilities.h"
#include<iostream>
#include<string>
#include<functional>
#include<algorithm>
#include<locale>
#include<cctype>

char Utilities::m_delimiter = '\0';
// default constructor definition

Utilities::Utilities()
{
	m_widthField = 1;
}

//setFieldWidth function definition
void Utilities::setFieldWidth(size_t field_width)
{
	m_widthField = field_width;
}

//getFieldWidth function definition
size_t Utilities::getFieldWidth() const
{
	return this->m_widthField;
}
//extractToken function definition
const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{

	bool isValid = false;
	std::string token;
	try {
		for (int i = next_pos; i < 1000; i++) {
			if (str[0] == m_delimiter) {
				if (str[i + 1] == m_delimiter) {
					next_pos = i + 1;
					throw std::string(str + "<-- *** no token found before the delimiter ***");
				}
				else {
					m_widthField = str.size();
					throw std::string(str + " <-- *** no token found before the delimiter ***");
				}
			}
			if (str[i] == '\0') {
				token = str.substr(next_pos, i - next_pos);

				if (m_widthField < i - next_pos) {
					m_widthField = i - next_pos;
				}

				more = false;
				break;
			}
			else if (str[i] == m_delimiter) {
				token = str.substr(next_pos, i - next_pos);

				if (m_widthField < i - next_pos) {
					m_widthField = i - next_pos;
				}

				next_pos = i + 1;

				more = true;
				break;

			}
		}

		while (!isValid && !token.empty()) {
			if (token.at(0) == ' ') { token.erase(0, 1); }
			else if (token.back() == ' ') { token.erase(token.length() - 1, 1); }
			else { isValid = true; }
		}
	}
	catch (const std::string& msg) {
		std::cout << msg << std::endl;
		more = false;
	}
	return token;
}

//setDelimiter function definition 
void Utilities::setDelimiter(const char delimiter)
{

	Utilities::m_delimiter = delimiter;
}
//getDelimiter function definition 

const char Utilities::getDelimiter() const
{
	return this->m_delimiter;
}