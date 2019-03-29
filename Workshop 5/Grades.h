/*************************************
 Name: Damirkhon Yodgorov
 Student Id: 108364175
 Seneca email: dyodgorov@myseneca.ca
 Date: 2018-10-10
*************************************/

#ifndef GRADES_H__
#define GRADES_H__
#include <iostream>
#include <string>
#include <iomanip>
#include <functional>
// structure that holds student info
struct Student {
	unsigned int studentId;
	double grade;
};

class Grades {

private:
	Student* m_student = nullptr; // default values
	size_t m_size = 0;

	
	// returns size of an array
	size_t size() const;

	
	Grades();
public:
	// char* constructor receives a C-style string with the name of the file holding the grade information for all students in a course
	
	Grades(const char* fileName);

	// prohibits copying, moving or assigning of a Grades object
	Grades(const Grades& src) = delete; // copy constructor
	Grades(Grades&& src) = delete; // move constructor
	Grades& operator=(const Grades& rhs) = delete; // copy assignment
	Grades& operator=(Grades&& rhs) = delete; // move assignment

	// displayGrades
	template<typename T>
	void displayGrades(std::ostream&os , T& F) const
	{
		std::string letter;

		for (size_t i = 0; i < m_size; i++)
		{
			letter =F(m_student[i].grade);
			os<< "   " <<m_student[i].studentId << " ";
			os.setf(std::ios::fixed);
			os.precision(2);
			os << m_student[i].grade << "";
			os.unsetf(std::ios::fixed);
			os << " ";
			os << letter <<std::endl;
		}


	}

	~Grades();
};

#endif // !GRADES_H__