/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 3.12.2018
*****************************************/
// I confirm that I am the only author of this file

//   and the content was created entirely by me.

#ifndef _LINEMANAGER_H
#define _LINEMANAGER_H
#include <iostream>
#include<deque>
#include<vector>
#include "CustomerOrder.h"
#include"Task.h"

class LineManager {
	std::vector<Task*> AssemblyLine; //A container containing all the references of the Task objects on the assembly line
	std::deque<CustomerOrder> ToBeFilled; //A queue of customer orders to be filled
	std::deque<CustomerOrder> Completed; //A queue of customer orders completed
	unsigned int m_cntCustomerOrder; //The number of CustomerOrder objects the assembly line started with
	
	size_t first;
	size_t last;

public:

	LineManager(const std::string&, std::vector<Task*>&, std::vector<CustomerOrder>&);
	bool run(std::ostream&);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;
};

#endif
