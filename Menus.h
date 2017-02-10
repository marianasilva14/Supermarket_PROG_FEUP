#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "defs.h"
#include "utils.h"
#include "Customer.h"
#include "Product.h"
#include "Transaction.h"
#include "Vende++.h"
#include "Date.h"


using namespace std;


unsigned short int menuCustomers(vector <Customer> &customers, vector<Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions);

unsigned short int menuOneCustomer(vector<Customer> &customers, vector<Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions);

unsigned short int menuEditCustomer(vector<Customer> &customers, string &fileCustomers, int id);

unsigned short int menuTransactions(vector <Customer> &customers, vector<Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions);

unsigned short int menuTransactionsOneCustomer(vector <Customer> &customers, vector<Transaction> &transactions, string &fileCustomers, string &fileTransactions);

unsigned short int menuPurchases(vector <Customer> &customers, vector<Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions);

unsigned short int menuRecomendationSystem(vector <Customer> &customers, vector <Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions);

unsigned short int mainMenu(vector <Customer> &customers, vector<Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions);


