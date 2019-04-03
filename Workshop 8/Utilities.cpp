/******************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca e-mail: dyodgorov@myseneca.ca
Completion Date: 14.11.2018
*******************************/
#include <memory>
#include "List.h"
#include "Element.h"
#include "Utilities.h"

using namespace std;

namespace w8
{
	List<Product> mergeRaw(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using raw pointers

		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t n = 0; n < price.size(); n++)
			{
				if (desc[i].code == price[n].code)
				{

					Product* ptr = new Product(desc[i].desc, price[n].price);
					
					ptr->validate();
					
					priceList += ptr;

					delete ptr;
					
					ptr = nullptr;
				}
			}
		}
		return priceList;
	}

	List<Product> mergeSmart(const List<Description>& desc, const List<Price>& price)
	{
		List<Product> priceList;
		// TODO: Add your code here to build a list of products
		//         using smart pointers

		for (size_t i = 0; i < desc.size(); i++)
		{
			for (size_t n = 0; n < price.size(); n++)
			{
				
				if (desc[i].code == price[n].code)
				{
					std::unique_ptr<Product> ptr(new Product(desc[i].desc, price[n].price));
					
					ptr->validate();
					
					priceList += ptr;
				}
			}
		}
		return priceList;
	}
}