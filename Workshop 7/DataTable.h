/***************************************
Name: Damirkhon Yodgorov
Student Id: 108364175
Seneca email: dyodgorov@myseneca.ca
Completion Date: 06.11.2018
****************************************/
#ifndef W7_DATATABLE_H
#define W7_DATATABLE_H
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <iomanip>
#include <numeric>


namespace w7 {
	template<class T>
	class DataTable {

		std::vector<T> x, y;  // defining the vector
		int width, decimals,no_of_data=0;  //defing the width and decimals variables 
	public:
		/*************************
		getSize function definition
		**************************/
		size_t getSize() { return no_of_data; }

		/*****************************************
		Constructor for reading data from the file 
		******************************************/

		DataTable(std::ifstream& is, int wid, int decimal) :width(wid), decimals(decimal) {
			while (is.good()) {
				no_of_data++; // counts number of lines in the file
				std::string line;
				getline(is, line);
				auto cr = line.find('\r');
				if (cr != std::string::npos) {
					line.erase(cr);
				}
				T xx, yy;
				std::stringstream s;

				if (not line.empty()) {
					s << line;
					s >> xx >> yy;

					x.push_back(xx);
					y.push_back(yy);
				}
			}
		}
		
		/***********************
		Mean function definitions
		************************/
		T mean()const {
			T result = std::accumulate(y.begin(), y.end(), 0.0);
			
			return result / y.size();
		}
		/************************
		Sigma function definition
		************************/		

		T sigma() const
		{
			T meanValue = mean();
			T sum = 0.0;
			for (size_t i = 0; i < y.size(); i++) {
				sum += (y[i] - meanValue)*(y[i] - meanValue);
			}
			return sqrt(sum / (y.size() - 1));

		}
		/*****************************
		Median function definition
		******************************/
		T median() const {
			std::vector<T> median;
			T temp;
			median = y;
			std::sort(median.begin(), median.end());

			temp = median[median.size() / 2];

			return temp;
		}
		/******************************
		Regression function definition
		*******************************/
		void regression(T& slope, T& y_intercept) const {
			T mX = std::accumulate(x.begin(), x.end(), 0.0) / x.size();
			T mY = mean();

			T number = 0; 
			T den = 0;
			for (auto i = 0; i < x.size(); i++) {
				number += (x[i] - mX) * (y[i] - mY);
				den += (x[i] - mX) * (x[i] - mX);
			}
			slope = number / den;
			y_intercept = mY - slope * mX;
		}

		/******************************
		      Display function
		*******************************/
		
		void display(std::ostream& os) const
		{
			os << std::setw(width) << "x"
				<< std::setw(width) << "y" << std::endl;

			for (size_t i = 0; i < x.size(); i++)
			{
				os << std::setw(width) << std::fixed << std::setprecision(decimals) << x[i]
				<< std::setw(width) << std::fixed << std::setprecision(decimals) << y[i] << std::endl;
			}

		}
	     };

	/********************************
	Overloading the insertion operator
	*********************************/
	template<class T>
	std::ostream& operator<<(std::ostream& os, const DataTable<T>& var) {
		var.display(os);
		return os;
	}
}

#endif