/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 3.12.2018
*****************************************/
// I confirm that I am the only author of this file

//   and the content was created entirely by me.

#ifndef _TASK_H
#define _TASK_H
#include<iostream>
#include"CustomerOrder.h"
#include"Item.h"
#include<deque>
#include<string>

class Task:public Item{
	
	std::deque<CustomerOrder> m_orders; // is a double ended queue with new CustomerOrders coming in one side and exiting out the other once filled.

	Task* m_pNextTask; // a pointer to the next task on the assembly line

public:
	Task(const std::string&); // a custom constructor
	Task(Task &) = delete; // copy constructor
	Task& operator=(Task&) = delete; // copy assignment operator
	Task(Task &&) = delete; //move constructor 	
	Task& operator=(Task&&) = delete; // move assignment operator
	void runProcess(std::ostream&); // runs a single cycle of the assembly line for the current task.
	bool moveTask(); // moves the last CustomerOrder in the queue to the next task on the assembly line
	void setNextTask(Task&); //stores the provided Task object’s reference into the m_pNextTask pointer.
	bool getCompleted(CustomerOrder&); // Removes the last CustomerOrder from the queue, places it in the parameter and returns true.
	void validate(std::ostream&);//  writes the name of the Item this Task
	Task& operator+=(CustomerOrder&&);// Moves the parameter onto the front of the CustomerOrder queue.
};

#endif
