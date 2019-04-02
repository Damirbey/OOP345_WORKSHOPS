/***************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca e-mail: dyodgorov@myseneca.ca
Completion Date: 31-10-2018
****************************************/
#include"ProdUtil.h"
#include"Product.h"
#include"TaxableProduct.h"
#include<string>
namespace w6
{
	/**********************************************************/
	/*defining ostream function*/

	std::ostream& operator<<(std::ostream & os, const iProduct &lhs)
	{
		lhs.display(os);
		return os;
	}

	/**********************************************************/
	/* readProduct function definition */
	

	 iProduct* readProduct(std::ifstream& fs) {

        iProduct *product = nullptr;
         std:: string num;
        double cost;
        char tax;

        fs >> num >> cost;
        tax = fs.get();

        if (tax == ' ') {
            fs >>tax;

            if (tax == 'H') {
                TaxableProduct* tempProduct = new TaxableProduct(num, cost, HST);
                product = tempProduct;
            }

            else if (tax == 'P') {

                TaxableProduct* tempProduct = new TaxableProduct(num, cost, PST);
                product = tempProduct;
            }
        }

        else {
            Product* tempProduct = new Product(num, cost);
            product = tempProduct;
        }

        return product;
    }
	

	/**********************************************************/

}