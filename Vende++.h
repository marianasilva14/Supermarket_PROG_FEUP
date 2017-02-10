#pragma once
#pragma warning (disable:4996)

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include<algorithm>
#include <ctime>

#include "defs.h"
#include "Date.h"
#include "Customer.h"
#include "Transaction.h"
#include "Product.h"
#include "utils.h"
#include "Menus.h"

using namespace std;

class VendeMaisMais {
private:
	string fileCustomers, fileProducts, fileTransactions;
	vector<Customer> customers; // Vector that saves information from existing customers
	vector<Product> products; // Vector that saves information of available products
	vector<Transaction> transactions; // Vector that saves information of transactions effected
	map<string, int> customerIdx;  // map to "translate" customer's name on his index in the customers vector
	map<string, int> productIdx;  // map to "translate" the product name on his index in the products vector
	
public:
	VendeMaisMais();
	void requestFiles(string &fileCustomers, string &fileProducts, string &fileTransactions);
	void separate_customer(string line, vector<Customer> &customers, unsigned int &index);
	bool readFileCustomers(vector<Customer> &customers, string &fileCustomers);
	void informationCustomers(vector<Customer> &customers);
	void informationOneCustomer(vector<Customer> &customers);
	void informationOneCustomer_name(vector<Customer> &customers);
	bool verifyCustomer(vector<Customer> &customers, int identifier);
	int askIdentifier(vector<Customer> &customers);
	void editCustomer_name(vector<Customer> &customers, string &fileCustomers, int id);
	void editCustomer_date(vector<Customer> &customers, string &fileCustomers, int id);
	void editCustomer_VolumePurchases(vector<Customer> &customers, string &fileCustomers, int id);
	void updateMap();
	int insertCustomers(vector<Customer> &customers, vector<Transaction> &transactions, string &fileCustomers);
	void removeCustomers(vector<Customer> &customers, string &fileCustomers);
	void separate_transaction(string line, vector<Transaction> &transactions);
	bool readFileTransactions(vector<Transaction> &transactions, string &fileTransactions);
	void separate_product(string line, vector<Product> &products, unsigned int & index);
	void informationTransactions(vector<Transaction> &transactions);
	void chronologicalOrder(vector<Transaction> &transactions);
	void transactionsDay(vector<Transaction> &transactions);
	void transactionsBetweenDates(vector<Transaction> &transactions);
	bool verifyTransaction(vector<Transaction> &transactions, int identifier);
	int returnIdentifier(vector <Customer> &customers, string name);
	void transactionsOneCustomer_name(vector <Customer> &customers, vector<Transaction> &transactions);
	void transactionsOneCustomer(vector <Customer> &customers, vector<Transaction> &transactions);
	float priceProduct(vector<Product> &products, string product);
	int returnIndex(vector<Customer> &customers, int identifier);
	int makePurchases(vector<Customer> &customers, vector<Transaction> &transactions, vector<Product> &products, string &fileCustomers, string &fileTransactions);
	bool readFileProducts(vector<Product> &products, string &fileProducts);
	void informationProducts(vector<Product> &products);
	bool verifyProducts(vector<Product> &products, string prod);
	void customersListAlphaOrder(vector<Customer> &customers) const;
	int maximumIdentifier(vector<Customer> &customers, vector<Transaction> &transactions); // Function that holds the customer's unique identifier with the largest identifier
	void bottom10VP(vector<Customer> &customers);
	void vectorBottom10(unsigned int id, vector<int> &result, vector<Transaction> &transactions);
	void saveProducts(vector <string> &product_recomendation, vector<bool> line, vector<Product> &products);
	int maxCommonProduct(vector <int> &number);
	void saveCommonProduct(vector <int> &commonProduct, vector <int> &number, vector <Product> &products, int max);
	bool discoverOtherCustomer(vector <int> &commonProduct, vector<bool> line);
	void purchasedProduct(vector <string> &get_recomendation, vector <int> &commonProduct, vector <Product> products, vector <bool> line);
	void customersPurchases(vector <string> &customerPurchases, vector <bool> line, vector <Product> &products);
	int returnIndexProduct(vector <int> &productsSupermarket, int max);
	void recomendationBottom10(vector<Customer> &customers, vector<Product> &products, vector<Transaction> &transactions);
	float compare(vector<bool> line1, vector <bool> line2);
	int chooseProduct(vector<string> &product_recomendation, string prod);
	int returnIndexMax(vector<int> &number);
	void getRecomendation(vector<string> &product_recomendation, vector<bool> line1, vector <bool> line2, vector<Product> &products);
	unsigned int requestId(vector<Customer> &customers, vector<Transaction> &transactions);
	void recomendationSystem(vector<Customer> &customers, vector<Product> &products, vector<Transaction> &transactions, unsigned int identifier);
};
