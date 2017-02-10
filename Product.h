#pragma once


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Product {
private:
	string name;
	float cost;


public:
	Product();
	void setName(string name);
	void setCost(float cost);
	string getName() const;
	float getCost() const;
};