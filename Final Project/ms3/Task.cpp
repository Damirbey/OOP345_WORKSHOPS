/*****************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 3.12.2018
*****************************************/
// I confirm that I am the only author of this file

//   and the content was created entirely by me.

#include"Task.h"

/////////////////////////////////////////////////////////////////////////////////////

// Custom constructor definition
Task::Task(const std::string & str) : Item(str)
{
	m_pNextTask = nullptr;

}

//runProcess function definition
void Task::runProcess(std::ostream& os) {
	if (!m_orders.empty()) {
		if (!m_orders.front().getOrderFillState()) {
					while (!m_orders.front().getItemFillState(getName())) {
							if (!getQuantity())
					throw std::string("***There are no more [") + getName() + "] in stock!***";
				m_orders.front().fillItem(*this, os);
			}
		}
	}
}
//moveTask function definition
bool Task::moveTask() {
	if (!m_orders.empty()) {
		if (m_pNextTask) {
			if (m_orders.front().getItemFillState(getName())) {
				*m_pNextTask += std::move(m_orders.front());
				m_orders.pop_front();
			}		}
		return true;
	}
	else {
		return false;
	}
}
//setNextTask function definition
void Task::setNextTask(Task& nextOne) {
	m_pNextTask = &nextOne;
}
//getCompleted function definition
bool Task::getCompleted(CustomerOrder& custObj) {
	if (!m_orders.empty() && m_orders.front().getOrderFillState()) {
		custObj = std::move(m_orders.front());
		m_orders.pop_front();
		return true;
	}
	else {
		return false;
	}
}
//validate function definition
void Task::validate(std::ostream& os) {
	os << getName() << " --> ";
	os << (m_pNextTask ? m_pNextTask->getName() : "END OF LINE");
	os << std::endl;
}
// operator+= definition
Task& Task::operator+=(CustomerOrder&& custObj) {
	m_orders.push_back(std::move(custObj));
	return *this;
}



