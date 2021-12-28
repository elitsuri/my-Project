#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <utility>
//----------------------------------------------------------
using namespace std;
//----------------------------------------------------------
void convert_2_pairs(vector<string> products, vector<string> productPrices,
	vector<string> productSold, vector<float> soldPrice,
	vector<pair<string, double>>& myProducts, vector<pair<string, double>>& myProductsSold)
{
	for (int i = 0; i < products.size(); i++)
	{
		myProducts[i].first = products[i];
		myProducts[i].second = stod(productPrices[i]);

	}
	for (int i = 0; i < productSold.size(); i++)
	{
		myProductsSold[i].first = productSold[i];
		myProductsSold[i].second = soldPrice[i];
	}
}
//----------------------------------------------------------
int priceCheck(vector<string> products, vector<string> productPrices,
	vector<string> productSold, vector<float> soldPrice)
{
	int sol = 0;
	vector<pair<string, double>> myProducts(products.size());
	vector<pair<string, double>> myProductsSold(productSold.size());

	if (products.size() < 0 || products.size() > 99 || soldPrice.size() < 0 || soldPrice.size() > 99)
		return -1;


	convert_2_pairs(products, productPrices, productSold, soldPrice, myProducts, myProductsSold);

	for (int i = 0; i < myProductsSold.size(); i++)
	{
		pair<string, double> myP = myProductsSold[i];
		for (int i = 0; i < myProducts.size(); i++)
		{
			if (myProducts[i].first == myP.first && myProducts[i].second != myP.second)
			{
				sol++;
				break;
			}
		}
	}
	return sol;
}
//----------------------------------------------------------
int main()
{
	vector<string> products = { "rice", "sugar", "wheat", "cheese" };
	vector<string> productPrices{ "16.89", "56.92", "20.89", "345.99" };
	vector<string> productSold = { "rice","cheese" };
	vector<float> soldPrice = { 18.99, 400.89 };

	cout << priceCheck(products, productPrices, productSold, soldPrice);

	return(EXIT_SUCCESS);
}
//----------------------------------------------------------