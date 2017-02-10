#include "Product.h"

Product::Product()
{

}


void Product::setName(string name)
{
	this->name = name;
}

void Product::setCost(float cost)
{
	this->cost = cost;
}

string Product::getName() const
{
	return name;
}

float Product::getCost() const
{
	return cost;
}