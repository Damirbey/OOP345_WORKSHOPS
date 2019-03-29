/*************************************
 Name: Damirkhon Yodgorov
 Student Id: 108364175
 Seneca email: dyodgorov@myseneca.ca
 Date: 2018-10-10
*************************************/


#include "Grades.h"
#include <fstream>

// char* constructor
// receives a C-style string with the name of
// the file holding the grade information for
// all students in a course
Grades::Grades(const char* fileName) {
	// creates the file object
	std::ifstream file(fileName);

	try {
		// checks if the file is opened
		if (file.is_open()) {

			// counts the number of records in the file
			size_t tmpCounter = 0;
			std::string buffer;
			while (std::getline(file, buffer)) tmpCounter++; // using getline to move the file pointer

			
			file.clear();
			file.seekg(0, file.beg);

			// allocates memory for the data member
			m_student = new Student[m_size = tmpCounter];

			// fills the array with student info
			while (file.good()) {
				static size_t i = 0;
				file >> m_student[i].studentId;
				file >> m_student[i].grade;
				i++;
			}
			file.close();
		}
		// if the file can't be opened, throw exception
		else {
			throw "Unable to open the file";
		}
	}
	// catches the exception and display friendly message
	catch (const char* message) {
		std::cout << "Error has occured: " << message << std::endl;
	}
}

// template 


// destructor
Grades::~Grades() {
	
	delete[] m_student;
}

// size
// returns the array size
size_t Grades::size() const { return m_size; }



