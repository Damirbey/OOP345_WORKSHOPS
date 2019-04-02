/***************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca e-mail: dyodgorov@myseneca.ca
Completion Date: 31-10-2018
****************************************/

#include<iomanip>
#include"TaxableProduct.h"

namespace w6
{
	
	/*****************************************************************************/

	TaxableProduct::TaxableProduct(std::string no, double cost, double tax_s):Product(no,cost)
	{
		tax = tax_s;
	}

	/*****************************************************************************/

	double TaxableProduct:: getPrice() const { return Product::getPrice() * (tax); }


	/*****************************************************************************/
	void TaxableProduct:: display(std::ostream& os) const {
		
			Product::display(os);
			os << (tax == HST ? " HST" : " PST");
		}




}

