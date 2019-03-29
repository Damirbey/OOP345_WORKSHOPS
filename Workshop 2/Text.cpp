/*
Name: Damirkhon Yodgorov
Student id: 108364175
Workshop 2
*/
#include"Text.h"

#include<fstream>
#include<string>
using namespace w3;

//////////////////////////
Text::Text() //default constructor
{}
/////////////////////////
Text::Text(char *name) //constructor with filename
{
	std::ifstream file(filename = name);
	no_of_records = 0;
	std::string reader = "";// variable used to help to count number of lines
	
	if (file.is_open())//checking if file is open
	{
		while (std::getline(file, reader))
			no_of_records++;

		text = new char[no_of_records]; // dynamic allocation of string object
		
		for (size_t i = 0; i < no_of_records; i++)
		{
			file >> text[i];
		}
		file.close();

	}
	else
	{
		no_of_records = 0;
		filename = "";
		text = nullptr;
	}



}
/////////////////////////////////////
Text::Text(const Text&src) //copy constructor
{
	*this = src;
}
///////////////////////////////////
Text & Text::operator=(const Text&src) //copy assignment operator
{
	if (this != &src)
	{
		text = new char[src.no_of_records];
		for (size_t i = 0; i < src.no_of_records; i++)
		{
			this->text[i] = src.text[i];
		}
		this->filename = src.filename;
		this->no_of_records = src.no_of_records;
	}
	return *this;

}
////////////////////////////////////
Text::Text(Text&&src) // move constructor
{
	*this = std::move(src);
}

///////////////////////////////////
Text& Text:: operator=( Text&&src) //move assignment operator
{
	text = new char[src.no_of_records];
	char* temp = text;
	for (size_t i = 0; i < src.no_of_records; i++)
	{
		text[i] = src.text[i];
	}
	no_of_records = src.no_of_records;
	filename = src.filename;
	src.filename = "";
	src.no_of_records = 0;
	src.text = nullptr;
	
	return *this;
}
/////////////////////////////////////

Text::~Text() //destructor 
{
	delete[]text;
}
////////////////////////////////////
size_t Text::size()const //member function returning number of records of text data
{
	return no_of_records;
}
