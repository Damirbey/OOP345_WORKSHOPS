/*
Name: Damirkhon Yodgorov
Student id: 108364175
Workshop 2
*/

#include<string>

namespace w3 // w3 namespace declaration
{

	class Text  // Text class declaration
	{
		char * text=nullptr; //stores data from the file
		size_t no_of_records = 0; //stores number of records from the file
		std::string filename; //stores filename

	public:
		Text(); //default constructor
		////////////////
		Text(char*name); //constructor with one parameter
		///////////////
		Text(const Text&src); //copy constructor
		///////////////
		Text &operator=(const Text&src); //copy assignment operator
		///////////////
		Text(Text&&);  //move constructor 
		///////////////
		Text& operator=(Text&&); //move assignment operator
		//////////////
		~Text(); //Destructor
		size_t size()const; // returns number of records to be displayed


	};


}

