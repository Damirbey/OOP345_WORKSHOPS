/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 24.11.2018
*****************************************/
// I confirm that I am the only author of this file

//   and the content was created entirely by me.
#ifndef ITEM_H
#define ITEM_H
#include<iostream>
#include<string>

class Item
{
	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	int m_quantity;
	size_t m_widthField;
public:
	Item(std::string &);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream&os, bool full) const;



};




#endif