/***************************************
Name: Damirkhon Yodgorov

Student Id: 108364175

Seneca email: dyodgorov@myseneca.ca

Date of completion: 2018-10-04

***************************************/

#include "Notifications.h"

namespace w4 {

	// default constructor 
	Notifications::Notifications() {
	   messages.reserve(max_size);
	}



	// copy constructor
	Notifications::Notifications(const Notifications& src) {
		*this = src;
	}


	// move constructor
	Notifications::Notifications(Notifications&& src) {
		*this = std::move(src);

		
		src.messages.clear(); //clearing the source vector
	}


	// copy assignment operator
	Notifications& Notifications::operator=(const Notifications& rhs) {
		if (this != &rhs) {
			// clear local vector
			messages.clear();
			for (auto i = rhs.messages.begin(); i < rhs.messages.end(); i++) {
				messages.push_back(*i);
			}
		}
		return *this;
	}


	// move assignment operator
	Notifications&& Notifications::operator=(Notifications&& rhs) {
		if (this != &rhs) {
			// clear local vector
			messages.clear();
			for (auto i = rhs.messages.begin(); i < rhs.messages.end(); i++) {
				messages.push_back(*i);
			}
			// clear the right hand side vector
			rhs.messages.clear();
		}
		return std::move(*this);
	}

	// destructor
	Notifications::~Notifications() {
		// destroys the message objects
		messages.clear();
	}


	// operator+= overloading implementation 

	void Notifications::operator+=(const Message& msg) {
	
		if (messages.size() != messages.capacity()) {
			
			messages.push_back(msg); // inserts a message to the last position
		}
	}

	// display function implementation

	void Notifications::display(std::ostream& ost) const {
		
		if (!messages.empty()) {
			for (auto i = messages.begin(); i < messages.end(); i++)
				i->display(ost);
		}
	}
}