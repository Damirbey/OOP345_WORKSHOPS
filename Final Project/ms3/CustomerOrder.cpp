/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 3.12.2018
*****************************************/
// I confirm that I am the only author of this file

//   and the content was created entirely by me.

#include <iostream>
#include <string>
#include <iomanip>
#include "CustomerOrder.h"
#include "Item.h"
#include "Utilities.h"

size_t CustomerOrder::m_widthField = 0;

//default constructor definition

CustomerOrder::CustomerOrder() {
	m_lstItem = nullptr;
	m_cntItem = 0u;
}
//Custom constructor definition 
CustomerOrder::CustomerOrder(const std::string& str) {
	Utilities util;
	bool more = true;
	size_t next_pos = 0u;

	m_name = util.extractToken(str, next_pos, more);
	m_product = util.extractToken(str, next_pos, more);
	m_cntItem = 0u;

	size_t start_pos = next_pos;
	while (more) {
		util.extractToken(str, next_pos, more);
		++m_cntItem;
	}

	m_lstItem = new ItemInfo*[m_cntItem];
	more = true;
	for (size_t i = 0u; i < m_cntItem; ++i) {
		m_lstItem[i] = new ItemInfo(util.extractToken(str, start_pos, more));
	}

	if (util.getFieldWidth() > m_widthField) m_widthField = util.getFieldWidth();
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

		if (m_lstItem) {
			for (unsigned int i = 0; i < m_cntItem; ++i) {
				delete m_lstItem[i];
			}
		}
		delete[] m_lstItem;

		this->m_cntItem = src.m_cntItem;
		this->m_lstItem = src.m_lstItem;

		src.m_lstItem = nullptr;
	}
	return *this;
}
// destructor definition
CustomerOrder::~CustomerOrder() {
	if (m_lstItem) {
		for (unsigned int i = 0; i < m_cntItem; ++i) {
			delete m_lstItem[i];
		}
	}
	delete[] m_lstItem;
}
// getItemFillState function definition
bool CustomerOrder::getItemFillState(std::string str) const {
	bool isFilled = true;
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_lstItem[i]->m_itemName == str)
			if (!m_lstItem[i]->m_fillState) {
				isFilled = false;
				break;
			}
	}

	return isFilled;
}

// getOrderFillState() function definition 
bool CustomerOrder::getOrderFillState() const {
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (!m_lstItem[i]->m_fillState) return false;
	}
	return true;
}

// fillItem(Item& item, std::ostream&) function definition
void CustomerOrder::fillItem(Item& item, std::ostream& os) {
	for (unsigned int i = 0; i < m_cntItem; ++i) {
		if (m_lstItem[i]->m_itemName == item.getName() && !m_lstItem[i]->m_fillState) {
			if (item.getQuantity() > 0) {
				m_lstItem[i]->m_serialNumber = item.getSerialNumber();
				item.updateQuantity();
				m_lstItem[i]->m_fillState = true;
				os << "Filled ";
			}
			else {
				os << "Unable to fill ";
			}

			os << m_name << ", " << m_product << "[" << m_lstItem[i]->m_itemName << "]" << std::endl;
			return;
		}
	}
}

// display function definition 
void CustomerOrder::display(std::ostream& os) const {
	os << m_name << " - " << m_product << std::endl;
	for (unsigned int i = 0; i < m_cntItem; i++) {
		os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber
			<< std::setfill(' ') << "] " << std::setw(m_widthField) << std::left << m_lstItem[i]->m_itemName
			<< " - " << (m_lstItem[i]->m_fillState ? "FILLED" : "MISSING") << std::endl;
	}
}


