#include "Customer.h"


Customer::Customer()
{

}


void Customer::setName(string name)
{
	this->name = name;
}

void Customer::setIdentifier(unsigned int identifier)
{
	this->identifier = identifier;
}

void Customer::setVolumePurchases(float volumePurchases)
{
	this->volumePurchases = volumePurchases;
}

void Customer::setDate(string date)
{
	this->date = date;
}

string Customer::getName() const
{
	return name;
}

unsigned int Customer::getIdentifier() const
{
	return identifier;
}

float Customer::getVolumePurchases() const
{
	return volumePurchases;
}

string Customer::getDate() const
{
	return date;
}
