/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 3.12.2018
*****************************************/

// I confirm that I am the only author of this file

//   and the content was created entirely by me.


#ifndef _CUSTOMERORDER_H
#define _CUSTOMERORDER_H
#include "Item.h"

// ***************ItemInfo Structure*********************
struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;
	ItemInfo(std::string src) : m_itemName(src) {};
};

//******************* CustomerOrder class definition*******************
class CustomerOrder
{
	std::string m_name; //the name of the customer (e.g., John, Sara, etc)
	std::string m_product; //the name of the product being assembled (e.g., Desktop, Laptop, etc)
	unsigned int m_cntItem;// a count of the number of items for the customer’s order
	ItemInfo ** m_lstItem;//a dynamically allocated array of pointers. 
	static size_t m_widthField; // the maximum width of a field, used for display purposes

public:
	CustomerOrder(); // default constructor
	CustomerOrder(const std::string&); // a custom constructor that takes as a parameter a reference to a string containing a single record from the input file.
	CustomerOrder(CustomerOrder&); //copy constructor
	CustomerOrder& operator=(CustomerOrder&) = delete; // restricting the copy assignment operator
	CustomerOrder(CustomerOrder&&) noexcept; // move constructor
	CustomerOrder& operator=(CustomerOrder&&);//move assignment operator
	~CustomerOrder(); //destructor
	bool getItemFillState(std::string) const;// returns the ItemInfo::m_fillState of the item specified as a parameter.
	bool getOrderFillState() const;// returns true if all the items in the order have been filled;
	void fillItem(Item& item, std::ostream&); //fills the item in the current order that corresponds to the item passed into the function
	void display(std::ostream&) const; //displays the state of the current object in the format

};




#endif

