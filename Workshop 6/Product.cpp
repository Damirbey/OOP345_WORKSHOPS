/***************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca e-mail: dyodgorov@myseneca.ca
Completion Date: 31-10-2018
****************************************/

#include"Product.h"
#include<iomanip>
#include<string>
namespace w6
{
	/**************************
	Constructor with two arguments
	**************************/
	Product::Product(std::string no, double price)
	{
		product_num = no;
		cost = price;
	}

	/**************************
	 getPrice function definition
	**************************/
	double Product::getPrice()const   
	{
		return cost;
    }

	/**************************
	 display function definition
	**************************/

	void Product::display(std::ostream & os) const
	{
		os << std::setw(16)<< product_num
			<< std::setw(16) << std::fixed << std::setprecision(2) << cost;
		
	}
}