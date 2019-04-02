/***************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca e-mail: dyodgorov@myseneca.ca
Completion Date: 31-10-2018
****************************************/


#include "Product.h"
#define HST 1.13
#define PST 1.08

namespace w6 {

	class TaxableProduct : public Product {

	private:
		double tax;
		
	public:
		TaxableProduct(std::string n, double c, double t);
		double getPrice() const;

		void display(std::ostream& os) const;
	};

}


