#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

#include "Date.h"


using namespace std;


class Transaction {
private:
	unsigned int identifier;
	string date; // in form DD/MM/YYYY
	vector<string> products;

public:
	Transaction();
	void setIdentifier(unsigned int identifier);
	void setDate(string date);
	void setProducts(vector<string> products);
	unsigned int getIdentifier() const;
	string getDate() const;
	vector<string> getProducts() const;
};



