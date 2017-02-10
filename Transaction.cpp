#include "Transaction.h"

Transaction::Transaction()
{

}

void Transaction::setIdentifier(unsigned int identifier)
{
	this->identifier = identifier;
}

void Transaction::setDate(string date)
{
	this->date = date;
}

void Transaction::setProducts(vector<string> products)
{
	this->products = products;
}

unsigned int Transaction::getIdentifier() const
{
	return identifier;
}

string Transaction::getDate() const
{
	return date;
}

vector<string> Transaction::getProducts() const
{
	return products;
}

