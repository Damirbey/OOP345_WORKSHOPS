/***************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca e-mail: dyodgorov@myseneca.ca
Completion Date: 31-10-2018
****************************************/

#ifndef W6_PRODUCT_H
#define W6_PRODUCT_H

#include"iProduct.h"

namespace w6
{


	class Product : public iProduct
	{
	protected:

		std::string product_num;
		double cost;
	
	public:
		Product(std::string, double);
		double getPrice()const;
		void display(std::ostream &os) const;

	};



}

#endif