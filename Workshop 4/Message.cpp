/***************************************
Name: Damirkhon Yodgorov

Student Id: 108364175

Seneca email: dyodgorov@myseneca.ca

Date of completion: 2018-10-04

***************************************/

#include "Message.h"
#include<iostream>

namespace w4 {

	// default constructor
	
	Message::Message() {}

	// Constructor that reads data from the file 
	Message::Message(std::ifstream& in, char c) {
		
		std::string buffer;

		if (in.is_open()) {
			std::getline(in, buffer, c);
			gothrow(buffer, c); // parses the read data from the file

		}
	}


	// returns true if the object is in a safe empty state


	bool Message::empty() const { return message.empty(); }

	
	// display function implementation
	void Message::display(std::ostream& ost) const {
		if (!empty()) {
			ost << "Message" << std::endl;
			ost << message << std::endl;
		}
		else {
			ost << "This object is empty" << std::endl;
		}
	}
// gothrow function implementation
	void Message::gothrow(std::string buffer, char c) {
		
		std::string user;   // variables to hold the parsed data
		std::string replyName;
		std::string tweet;

		size_t found = 0; // holds the position of the last found char

		// constants to hold the character values
		const char at = '@';
		const char blank = ' ';

		if (!buffer.empty()) {

			user = buffer.substr(0, found = buffer.find(blank)); // find the first blank space to get the user
			// erase the user from the buffer
			buffer.erase(0, found + 1);

		
			if (buffer.find(at) != std::string::npos) { // checks for @ character, npos => no match
				
				// find the first @ and get the string until the following blank space
				replyName = buffer.substr(buffer.find(at) + 1, found = buffer.find(blank) - 1);
				buffer.erase(0, found + 2);
			}

			if (found != std::string::npos) {
				
				tweet = buffer.substr(0); // gets the leftover string from the buffer
			}

			// if the data is valid

			if (!user.empty() && !tweet.empty()) {
				
				message = " User  : " + user + c; // combine all data
				if (!replyName.empty())
					message += " Reply : " + replyName + c;
			      message += " Tweet : " + tweet + c;

			}
		}
	}

}