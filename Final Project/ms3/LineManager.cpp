/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 3.12.2018
*****************************************/
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include<iostream>
#include<vector>
#include"Task.h"
#include"Utilities.h"
#include"LineManager.h"
#include<fstream>

// custom constructor
LineManager::LineManager(const std::string& str, std::vector<Task*>& alltasks, std::vector<CustomerOrder>& customerOrders) {
	std::ifstream file(str);
		if (!file)
		throw std::string("Unable to open [") + str + "] file.";

	Utilities utilObj;
	size_t next_pos = 0;
	bool more = true;
	std::string record;
	std::string singletask;
	std::string next;

	bool isFirst = true;

	while (!file.eof()) {
		std::getline(file, record);

		if (record.empty())
			throw std::string("*** Empty Record in [") + str + "] ***";

		singletask= utilObj.extractToken(record, next_pos, more);
		if (more)
			next = utilObj.extractToken(record, next_pos, more);

		for (size_t i = 0; i < alltasks.size(); ++i) {
			if (alltasks[i]->getName() == singletask) {
				
				if (isFirst) {
				first = i;
					isFirst = !isFirst;
				}

				if (!next.empty()) {
					for (size_t j = 0; j < alltasks.size(); ++j) {
						if (alltasks[j]->getName() == next) {
							alltasks[i]->setNextTask(*alltasks[j]);
							break;
						}
					}
				}
				else {
				last = i;
				}

				break;
			}
		}
		next_pos = 0;
		more = true;
		singletask.clear();
		next.clear();
	}

	for (size_t i = 0; i < customerOrders.size(); ++i)
		ToBeFilled.push_back(std::move(customerOrders[i]));
	customerOrders.erase(customerOrders.begin(), customerOrders.end());

	AssemblyLine = alltasks;
}


//run function definition
bool LineManager::run(std::ostream& os) {
	bool done = true;

	if (!ToBeFilled.empty()) {
		*AssemblyLine[first] += std::move(ToBeFilled.front());
		ToBeFilled.pop_front();
	}
	//try and catch implementation
	for (size_t i = 0; i < AssemblyLine.size(); ++i) {		
		try {
			AssemblyLine[i]->runProcess(os);
		}
		catch (std::string err) {
			std::cout << std::endl << err << std::endl;
			throw std::string("Not enough inventory available");
		}
	}
	//deleting all finished tasks
	CustomerOrder buffer;
	if (AssemblyLine[last]->getCompleted(buffer))
		Completed.push_back(std::move(buffer));
			for (size_t i = 0; i < AssemblyLine.size(); ++i) {
				if (AssemblyLine[i]->moveTask()) {
			done = false;

		}
	}

	return done;
}
//displayCompleted function definition

void LineManager::displayCompleted(std::ostream& os) const {
	for (auto& completed : Completed)
	{
		completed.display(os);
	}
}

//validateTasks function definition
void LineManager::validateTasks() const {
	if (!AssemblyLine.empty())
		for (size_t i = 0; i < AssemblyLine.size(); ++i)
			AssemblyLine[i]->validate(std::cout);
}





