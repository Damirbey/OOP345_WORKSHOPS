/*********************************

NAME : Damirkhon Yodgorov
Student Id: 108364175
Date : 27.09.2018
Seneca mail: dyodgorov@myseneca.ca
*********************************/
#ifndef LIST_H
#define LIST_H
#include<iostream>
template<class T, int N>
class List
{
	T a[N]; //array of T type with N number of elements
	int number_of_elements; //identifies number of elements in the array
	T dummy;// dummy value;
public:

	List() :number_of_elements{ 0 } { } //default constructor


	/****************************************/
	size_t size()const { return number_of_elements; }      //returns number of elements in the array


	/****************************************/

	const T&operator[](int index)const  //returns particular array element
	{


		return number_of_elements < N ? a[index] : dummy;

	}

	/****************************************/
	void operator+=(const T&src)//adds a value to the array , if space is available

	{
		if (number_of_elements < N)
		{
			a[number_of_elements] = src;
			number_of_elements++;
		}
	}
	/****************************************/

};


#endif
