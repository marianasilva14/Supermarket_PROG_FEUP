#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Date.h"
#include "Transaction.h"

using namespace std;


class Customer {
private:
	unsigned int identifier;
	string name;
	string date;
	float volumePurchases;

public:
	Customer();
	void setName(string name);
	void setIdentifier(unsigned int identifier);
	void setVolumePurchases(float volumePurchases);
	void setDate(string date);
	string getName() const;
	unsigned int getIdentifier() const;
	float getVolumePurchases() const;
	string getDate() const;
};

