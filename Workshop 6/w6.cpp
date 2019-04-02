/***************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca e-mail: dyodgorov@myseneca.ca
Completion Date: 31-10-2018
****************************************/

// Workshop 6 - STL Containers
// w6.cpp
// Updated by cornel on 27.09.2018

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "iProduct.h"
#include "ProdUtil.h"

int main(int argc, char** argv) {

	std::cout << "Command Line: ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout << std::endl;
	if (argc != 2) {
		std::cerr << "\n***Incorrect number of arguments***\n";
		return 1;
	}
	std::ifstream productList(argv[1]);
	if (!productList) {
		std::cerr << "\n***Failed to open file " << argv[1] << "***\n";
		return 2;
	}
	std::cout << std::fixed << std::setprecision(2);

	// TODO: Define a variable of type vector named "products"
	std::vector<w6::iProduct*>products;

	std::cout << "====================================\n";
	std::cout << "Reading data from the file\n";
	std::cout << "====================================\n";
	{
		// TODO: Read from the file one record at a time and create a product.


		// - Print a message before starting processing a product.

		// - Add the product to the vector "products", created above.
		int iteration = 0;

		
		while (productList.good())
		{  
			iteration++;
			w6::iProduct*  product_read = w6::readProduct(productList);
	         if (iteration == 13)
	          {
		       std::cout << "Processing record " << iteration << ": no such record! Reached the end of the file!" << std::endl;
	          }
			else if (product_read != nullptr)
			{

				products.push_back(product_read);

				std::cout << "Processing record " << iteration << ": done!" << std::endl;
			}
			else if (product_read==nullptr)
			{
				std::cout << "Processing record " << iteration << ": Unrecognizable Tax Code!" << std::endl;
			}
			


			// - Handle any thrown exceptions and print the message.

		}
	
	}
	std::cout << "====================================\n";

	std::cout << std::endl;
	std::cout << "====================================\n";
	std::cout << "Printing the content of the vector\n";
	std::cout << "====================================\n";

	double total = 0.0;
	std::cout<< "      Product No         Taxable\n";
	std::cout << "------------------------------------\n";
	for (auto i = 0u; i < products.size(); i++) {
		total += products[i]->getPrice();
		std::cout<<*products[i]<<std::endl;
	}
	
	std::cout << "------------------------------------\n";
	std::cout << std::setw(22) << "Total: ";
	std::cout << std::setw(10) << total << std::endl;
	std::cout << "====================================\n";
	return 0;
}

