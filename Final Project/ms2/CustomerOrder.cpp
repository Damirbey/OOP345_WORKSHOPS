/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 24.11.2018
*****************************************/
// I confirm that I am the only author of this file

//   and the content was created entirely by me.

#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include"CustomerOrder.h"
#include"Item.h"
#include"Utilities.h"

size_t CustomerOrder::m_widthField = 0;

//default constructor definition

CustomerOrder::CustomerOrder()
{
 m_lstItem=nullptr;
}

//Custom constructor definition 

CustomerOrder::CustomerOrder(std::string  str) {
	Utilities utilObj;
	bool more = true;
	size_t next_pos = 0u;
	m_name = utilObj.extractToken(str, next_pos, more);
	m_product = utilObj.extractToken(str, next_pos, more);
	m_cntItem = 0u;
	size_t start_pos = next_pos;
	
	while (more) {
		utilObj.extractToken(str, next_pos, more);
		++m_cntItem;
	}
	m_lstItem = new ItemInfo*[m_cntItem];
	more = true;
	for (size_t i = 0u; i < m_cntItem; ++i) {
		m_lstItem[i] = new ItemInfo(utilObj.extractToken(str, start_pos, more));
	}

	if (utilObj.getFieldWidth() > m_widthField)
		m_widthField = utilObj.getFieldWidth();

}
// throwing an error when copy constructor is called 

CustomerOrder::CustomerOrder(CustomerOrder&) {
	throw std::string("Cannot make copies.");
}


//move Constructor definition
CustomerOrder::CustomerOrder(CustomerOrder&& src) noexcept {
	m_lstItem = nullptr;
   *this = std::move(src);
}

//move assignment operator definition
CustomerOrder& CustomerOrder::operator=(CustomerOrder&& src) {
	if (&src != this) {
		this->m_name = src.m_name;
		this->m_product = src.m_product;
		if (m_lstItem)
			for (unsigned int i = 0; i < m_cntItem; i++)
				delete this->m_lstItem[i];
		delete[] this->m_lstItem;

		this->m_cntItem = src.m_cntItem;
		this->m_lstItem = src.m_lstItem;
		src.m_lstItem = nullptr;
	}

	return *this;
}

//destructor definition 
CustomerOrder::~CustomerOrder() {
	if (m_lstItem)
		for (unsigned int i = 0; i < m_cntItem; ++i)
			delete m_lstItem[i];
	delete[] m_lstItem;
}

// getItemFillState function definition
bool CustomerOrder::getItemFillState(std::string str) const {
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_lstItem[i]->m_itemName == str)
			return m_lstItem[i]->m_fillState;
	}

	return true;
}
// getOrderFillState() function definition 

bool CustomerOrder::getOrderFillState() const {
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (!m_lstItem[i]->m_fillState)
			return false;
	}
	return true;
}

// fillItem(Item& item, std::ostream&) function definition

void CustomerOrder::fillItem(Item& itemObj, std::ostream& os) {
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_lstItem[i]->m_itemName == itemObj.getName()) {
			if (itemObj.getQuantity() > 0) {
				m_lstItem[i]->m_serialNumber = itemObj.getSerialNumber();
				itemObj.updateQuantity();
				m_lstItem[i]->m_fillState = true;
				os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]";
			}
			else {
				os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]";
			}
			os << std::endl;
			return;
		}
	}
}
// display function definition 
void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::setfill('0') << m_lstItem[i]->m_serialNumber
			<< std::setfill(' ') << "] " << std::setw(m_widthField) << m_lstItem[i]->m_itemName
			<< " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
	}
}


