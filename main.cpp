#include <iostream>
#include <string>
#include <vector>

#include "Date.h"
#include "Customer.h"
#include "Menus.h"
#include "Product.h"
#include "Transaction.h"
#include "Vende++.h"


int main()
{
	vector <Customer> customers;
	vector <Product> products;
	vector <Transaction> transactions;

	VendeMaisMais vendevar;

	string fileProducts;
	string fileCustomers;
	string fileTransactions;

	vendevar.requestFiles(fileCustomers, fileProducts, fileTransactions);

	mainMenu(customers, products, transactions, fileCustomers, fileProducts, fileTransactions);


	return 0;

}
