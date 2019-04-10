/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 14.11.2018
*****************************************/
#include<iomanip>
#include<string>
#include<iostream>
#include"Item.h"
#include"Utilities.h"


// custom constructor definition 
Item::Item(std::string &str) 
{
	std::string line;
	size_t next_pos = 0;
	bool more = true;
	std::string word;
	Utilities Uobj;

	line = str;
	m_widthField = 0;
	try
	{
		if (more)
		{
			m_name = Uobj.extractToken(line, next_pos, more);
			
		}

		if (more)
		{
			word = Uobj.extractToken(line, next_pos, more);
			m_serialNumber = std::stoi(word);
		}

		if (more)
		{
			word = Uobj.extractToken(line, next_pos, more);
			m_quantity = std::stoi(word);
		}
		if (more)
			m_description = Uobj.extractToken(line, next_pos, more);
	}
	catch (std::string msg)
	{
		std::cout << "Exception Handling:" << msg << std::endl;
	}

	
	if (m_widthField < Uobj.getFieldWidth())
		m_widthField = Uobj.getFieldWidth();

	
}

// getName function definition
const std::string& Item::getName() const
{
	return m_name;
}
//getSerialNumber function definition
const unsigned int Item::getSerialNumber()
{
	return m_serialNumber++;
}
//getQuantity function definition
const unsigned int Item::getQuantity()
{
	return m_quantity;
}

//updateQuantity function definition 
void Item::updateQuantity()
{
	if (m_quantity > 0)
	{
		m_quantity--;
	}

}

// display function definition 
void Item::display(std::ostream&os, bool full) const
{
	size_t width = m_widthField;

	if (full)
	{
		os <<std::setw(12) << std::left << getName();
		os << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ');
		os << " Quantity: " << std::setw(12) << std::left << m_quantity;
		os << " Description: " << std::setw(width) <<std:: left << m_description << std::endl;
	}
	else
	{
		os << std::setw(12) << std::left << getName();
		os << " [" << std::setw(6) << std::setfill('0') << std::right << m_serialNumber << "]" << std::setfill(' ') << std::endl;
	}
	
}

