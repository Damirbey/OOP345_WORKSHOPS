/*********************************

NAME : Damirkhon Yodgorov
Student Id: 108364175
Date : 27.09.2018
Seneca mail: dyodgorov@myseneca.ca
*********************************/

#ifndef PAIR_H
#define PAIR_H
#include<iostream>


template<typename A, typename B>

class Pair
{
	A typeA;  /*data of types A and B*/
	B typeB;


public:
	Pair() {}; // default constructor

	/************************************/

	Pair(const A& valueA, const B& valueB) /*default constructor that sets data types of A and B to the provided values*/
	{
		typeA = valueA;
		typeB = valueB;
	}

	/************************************/

	const A& getKey()const
	{
		return typeA;
	}

	const B& getValue()const
	{
		return typeB;
	}

};



#endif
