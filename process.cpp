/*
Name: Damirkhon Yodgorov

Student Id: 108364175

*/
#include"process.h"
#include"CString.h"
#include<iostream>

namespace w1
{

	void process(char *name, std::ostream&os)
	{
		CString processed(name);
		processed.display(os);
	}

}