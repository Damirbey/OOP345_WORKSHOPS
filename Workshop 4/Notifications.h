/***************************************
Name: Damirkhon Yodgorov

Student Id: 108364175

Seneca email: dyodgorov@myseneca.ca

Date of completion: 2018-10-04

***************************************/

#ifndef _W4_NOTIFICATIONS_H
#define _W4_NOTIFICATIONS_H
#include"Message.h"
#include<vector>
 // Declaration of w4 namespace
namespace w4 {
	
		
	class Notifications //Notification class declaration
	{

		std::vector<Message> messages;
		const size_t max_size = 10;

	public:

		Notifications(); // default constructor

		Notifications(const Notifications&); //copy constructor

		Notifications & operator=(const Notifications &); // copy assignment operator

		Notifications(Notifications &&); // move constructor

		Notifications && operator=(Notifications&&);  // move assignment operator

		~Notifications(); // destructor

		void operator+=(const Message &msg); // function that adds msg to set

		void display(std::ostream & os) const;// inserts the Message objects to os output stream




	};

}

#endif

