#include "Vende++.h"

VendeMaisMais::VendeMaisMais()
{

}

void VendeMaisMais::requestFiles(string &fileCustomers, string &fileProducts, string &fileTransactions)
{
	
	cout << "\nPlease enter the customer file: "; //Read file name
	cin >> fileCustomers;
	cout << endl;

	cout << "Please enter the product file: "; //Read the file name
	cin >> fileProducts;
	cout << endl;

	cout << "Please enter the transaction file: "; //Read file name
	cin >> fileTransactions;
	cout << endl;

	mainMenu(customers, products, transactions, fileCustomers, fileProducts, fileTransactions);
	
	
}

/*********************************
Customer management
********************************/

void VendeMaisMais::separate_customer(string line, vector<Customer> &customers, unsigned int &index)
{
	/*Function to separate elements of structure of customers, with the desired format (identifier ; name ; date ; value) and and puts them in a vector*/

	size_t l = line.find_first_of(';'); /*Determines the size until you find the first semicolon*/
	string first = line.substr(0, (l - 1)); /*Separates the first element (identifier) of the rest of the elements, that is, extract the first semicolon*/

	line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
	l = line.find_first_of(';'); /*Find the second semicolon*/
	string second = line.substr(0, (l - 1)); /*Separates the second element (name) of the rest of the elements*/


	line = line.substr(l + 2); /*The line happens to be from space after the second semicolon*/
	l = line.find_first_of(';'); /*Find the third semicolon*/
	string third = line.substr(0, l - 1); /*Separates the third element (date) of the rest of the elements*/

	string fourd = line.substr(l + 2); /*Extracts the rest of the line (value)*/


	const char * c = first.c_str();
	int number = atoi(c); /*Converts a variable of type string to integer, in this case converts the customer identifier (of type integer) in a string.*/
	const char * c1 = fourd.c_str();
	float number2 = stof(c1); /*Converts a variable of type float to string, in this case converts the value (of type float) in a string*/

							  /*Correspondence between the parameters of the class and the elements separated and converted into string*/

	Customer object;

	object.setIdentifier(number);
	object.setName(second);
	object.setVolumePurchases(number2);
	object.setDate(third);

	customers.push_back(object); //Inserts in the vector customers customer class

	customerIdx[second] = index;
	index++;

}

bool VendeMaisMais::readFileCustomers(vector<Customer> &customers, string &fileCustomers)
{
	/*Function that reads the contents of a text file, line by line*/

	ifstream fin;
	string line;
	unsigned int counter = 0;
	int numberTotal;

	fin.open(fileCustomers); /*Open the file; exit program if the file couldn't be opened*/
	if (!fin.is_open())
		return false;

	/*Read each line of the file*/

	getline(fin, line, '\n');
	numberTotal = atoi(line.c_str());

	while (getline(fin, line))
	{
		if (line.size() > 1)/*If the size of line is > 1, calls the function Separate_customer*/
			separate_customer(line, customers, counter);
	}

	fin.close(); /*Close the file*/
}

void VendeMaisMais::informationCustomers(vector<Customer> &customers)
{
	/*Function that show the information about all customers*/

	cout << "Total number of Customers: " << customers.size() << endl << endl;

	for (int i = 0; i < customers.size(); i++)
	{
		cout << "Identifier: " << customers.at(i).getIdentifier() << endl;
		cout << "Name: " << customers.at(i).getName() << endl;
		cout << "Accession date: " << customers.at(i).getDate() << endl;
		cout << "Amount: " << customers.at(i).getVolumePurchases() << endl << endl;
	}
}

void VendeMaisMais::customersListAlphaOrder(vector<Customer> &customers) const
{

	int min;

	for (int i = 0; i < customers.size(); i++)
	{
		min = i;

		for (int j = i; j < customers.size(); j++)
			if (customers.at(min).getName() > customers.at(j).getName())
				min = j;

		string tmp = customers.at(i).getName();

		customers.at(i).setName(customers.at(min).getName());
		customers.at(min).setName(tmp);

		int identifier = customers.at(i).getIdentifier();
		customers.at(i).setIdentifier(customers.at(min).getIdentifier());
		customers.at(min).setIdentifier(identifier);

		string date = customers.at(i).getDate();
		customers.at(i).setDate(customers.at(min).getDate());
		customers.at(min).setDate(date);

		float volumePurchases = customers.at(i).getVolumePurchases();
		customers.at(i).setVolumePurchases(customers.at(min).getVolumePurchases());
		customers.at(min).setVolumePurchases(volumePurchases);
	}

	cout << "Total number of Customers: " << customers.size() << endl << endl;

	for (int i = 0; i < customers.size(); i++)
	{
		cout << "Identifier: " << customers.at(i).getIdentifier() << endl;
		cout << "Name: " << customers.at(i).getName() << endl;
		cout << "Accession date: " << customers.at(i).getDate() << endl;
		cout << "Amount: " << customers.at(i).getVolumePurchases() << endl << endl;
	}

}

void VendeMaisMais::informationOneCustomer(vector<Customer> &customers)
{
	/*Function that show the information about one customer by the identifier*/

	int i = 0;
	int identifier;
	bool find = false;

	cout << "What is the identifier of customer? ";
	cin >> identifier;
	cout << endl;

	while (!find && i < customers.size())
	{
		if (identifier == customers.at(i).getIdentifier())
		{
			cout << "Identifier: " << customers.at(i).getIdentifier() << endl;
			cout << "Name: " << customers.at(i).getName() << endl;
			cout << "Accession date: " << customers.at(i).getDate() << endl;
			cout << "Amount: " << customers.at(i).getVolumePurchases() << endl << endl;
			find = true;
		}
		i++;
	}

	if (!find)
		cout << "Customer doesn't exist. Try again, please." << endl;
}

void VendeMaisMais::informationOneCustomer_name(vector<Customer> &customers)
{
	/*Function that show the information about one customer by the name*/

	int i = 0;
	string name;
	bool find = false;

	cout << "What is the name of customer? ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << endl;

	while (!find && i < customers.size())
	{
		if (name == customers.at(i).getName())
		{
			cout << "Identifier: " << customers.at(i).getIdentifier() << endl;
			cout << "Name: " << customers.at(i).getName() << endl;
			cout << "Accession date: " << customers.at(i).getDate() << endl;
			cout << "Amount: " << customers.at(i).getVolumePurchases() << endl << endl;
			find = true;
		}
		i++;
	}

	if (!find)
		cout << "Customer doesn't exist. Try again, please." << endl << endl;
}

bool VendeMaisMais::verifyCustomer(vector<Customer> &customers, int identifier)
{
	/*Function to check if the customer that user entered exists*/

	int i = 0;

	for (size_t i = 0; i < customers.size(); i++)
	{
		if (customers.at(i).getIdentifier() == identifier)
			return true;
	}

	return false;
}

int VendeMaisMais::askIdentifier(vector<Customer> &customers)
{
	int id;
	string input;
	bool find = false;

	cout << "What is the identifier of customer who you want change? ";
	cin >> input;
	cout << endl;

	stringstream convertor(input); /*Check if it is a number*/

	if (convertor.fail()) /*If isn't a number, show the follow message*/
		cout << "Identifier don't exist.";

	else
	{
		convertor >> id;

		while (verifyCustomer(customers, id) == false) /*Check if the customer exists*/
		{
			cout << "This customer don't exist. Try again." << endl;
			cout << "Identifier: ";
			cin >> id;
		}
	}

	return id;
}

int VendeMaisMais::maximumIdentifier(vector<Customer> &customers, vector<Transaction> &transactions)
{
	/*Function that finds the maximum of all identifiers of transactions and customers*/

	int maximum = 0;


	for (size_t i = 0; i < customers.size(); i++)
	{
		if (customers.at(i).getIdentifier() > maximum)
			maximum = customers.at(i).getIdentifier();
	}

	for (size_t i = 0; i < transactions.size(); i++)
	{
		if (transactions.at(i).getIdentifier() > maximum)
			maximum = transactions.at(i).getIdentifier();
	}

	return maximum;
}

void VendeMaisMais::editCustomer_name(vector<Customer> &customers, string &fileCustomers, int id)
{
	string name;
	int index;
	ofstream fout;

	cout << "What is the name of you want? ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);

	index = returnIndex(customers, id);

	customers.at(index).setName(name);

	fout.open(fileCustomers);

	/*Insert in file with the desired format (identifier ; name ; value)*/

	fout << customers.size() << endl;
	for (size_t i = 0; i < customers.size(); i++)
	{
		fout << customers.at(i).getIdentifier() << " ; " << customers.at(i).getName() << " ; " << customers.at(i).getDate() << " ; " << customers.at(i).getVolumePurchases() << endl;
	}

	fout.close();

	cout << "The name was changed with success!" << endl << endl;


}

void VendeMaisMais::editCustomer_date(vector<Customer> &customers, string &fileCustomers, int id)
{
	string date;
	int index;
	ofstream fout;

	cout << "What is the date of you want? ";
	cin >> date;

	Date object;

	while (!object.verifyDate(date)) //Check if the date 1 is valid
	{
		cout << "This date isn't valid." << endl;
		cout << "Please insert date (day/month/year) again: ";
		cin >> date;
		cout << endl;
	}

	index = returnIndex(customers, id);

	customers.at(index).setDate(date);

	fout.open(fileCustomers);

	/*Insert in file with the desired format (identifier ; name ; value)*/

	fout << customers.size() << endl;
	for (size_t i = 0; i < customers.size(); i++)
	{
		fout << customers.at(i).getIdentifier() << " ; " << customers.at(i).getName() << " ; " << customers.at(i).getDate() << " ; " << customers.at(i).getVolumePurchases() << endl;
	}

	fout.close();

	cout << "The date was changed with success!" << endl << endl;

}

void VendeMaisMais::editCustomer_VolumePurchases(vector<Customer> &customers, string &fileCustomers, int id)
{
	float volumePurchases;
	int index;
	ofstream fout;

	cout << "What is the volume purchases of you want? ";
	cin >> volumePurchases;

	index = returnIndex(customers, id);

	customers.at(index).setVolumePurchases(volumePurchases);

	fout.open(fileCustomers);

	/*Insert in file with the desired format (identifier ; name ; value)*/

	fout << customers.size() << endl;
	for (size_t i = 0; i < customers.size(); i++)
	{
		fout << customers.at(i).getIdentifier() << " ; " << customers.at(i).getName() << " ; " << customers.at(i).getDate() << " ; " << customers.at(i).getVolumePurchases() << endl;
	}

	fout.close();

	cout << "The volume of purchases was changed with success!" << endl << endl;
}

void VendeMaisMais::updateMap()
{
	customerIdx.erase(customerIdx.begin(), customerIdx.end());

	for (int i = 0; i < customers.size(); i++)
	{
		customerIdx[customers.at(i).getName() = i];
	}

}

int VendeMaisMais::insertCustomers(vector<Customer> &customers, vector<Transaction> &transactions, string &fileCustomers)
{
	/*Function that insert new customers in file customers.txt*/
	VendeMaisMais vendevar;

	ifstream fin;
	ofstream fout;
	Customer new_customer;
	string name;
	int amount;
	string date;

	/*Request data to the user*/
	cout << "Insert name of customer: ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << endl;

	amount = 0;

	time_t tt = time(0);   // get time now
	struct tm * now = localtime(&tt);
	ostringstream oss;
	if ((now->tm_mon + 1) > 9) // Adds a zero before the month if month < 9
	{
		oss << now->tm_mday << "/" << (now->tm_mon + 1) << "/" << (now->tm_year + 1900);
	}
	else
	{
		oss << now->tm_mday << "/0" << (now->tm_mon + 1) << "/" << (now->tm_year + 1900);
	};


	date = oss.str();

	Date object;

	while (!object.verifyDate(date)) //Check if the date 1 is valid
	{
		cout << "This date isn't valid." << endl;
		cout << "Please insert date (day/month/year) again: ";
		cin >> date;
		cout << endl;
	}


	new_customer.setIdentifier(maximumIdentifier(customers, transactions) + 1); /*Assigns the maximum identifier plus 1, discovered in function MaximumIdentifier*/
	new_customer.setName(name);
	new_customer.setVolumePurchases(amount);
	new_customer.setDate(date);

	customers.push_back(new_customer); /*Insert in vector of customers, the new customer*/

	fout.open(fileCustomers);

	/*Insert in file with the desired format (identifier ; name ; value)*/
	fout << customers.size() << endl;
	for (size_t i = 0; i < customers.size(); i++)
	{
		fout << customers.at(i).getIdentifier() << " ; " << customers.at(i).getName() << " ; " << customers.at(i).getDate() << " ; " << customers.at(i).getVolumePurchases() << endl;
	}

	fout.close();

	updateMap();

	return 0;

}

void VendeMaisMais::removeCustomers(vector<Customer> &customers, string &fileCustomers)
{
	int id;
	string input;
	ofstream fout;
	int i = 0;
	bool find = false;

	cout << "Who is the customer you want remove? ";
	cin >> input;

	stringstream convertor(input); /*Check if it is a number*/

	if (convertor.fail()) /*If isn't a number, show the follow message*/
		cout << "Identifier don't exist.";

	else
	{
		convertor >> id;

		while (verifyCustomer(customers, id) == false && convertor.fail()) /*Check if the customer exists*/
		{
			cout << "This customer don't exist. Try again." << endl;
			cout << "Identifier: ";
			cin >> id;
		}

		while (i < customers.size())
		{
			if (!find && id == customers.at(i).getIdentifier())
			{
				customers.erase(customers.begin() + i); /*Remove customer*/
				cout << endl << "Removed customer." << endl << endl;
				find = true; /*Put the variable to find true when it finds the user's chosen date*/
			}

			i++;
		}
	}

	/*If don't find the identifier choose by user, show this message*/
	if (!find)
		cout << "\nNot found customer." << endl << endl;

	else
	{
		fout.open(fileCustomers); /*Open file of customers*/

		fout << customers.size() << endl;

		for (size_t i = 0; i < customers.size(); i++)
		{
			fout << customers.at(i).getIdentifier() << " ; " << customers.at(i).getName() << " ; " << customers.at(i).getDate() << " ; " << customers.at(i).getVolumePurchases() << endl; /*Write in file with this format*/
		}

		fout.close(); /*Close the file*/
	}

}

/*********************************
Transaction management
********************************/

void VendeMaisMais::separate_transaction(string line, vector<Transaction> &transactions)
{
	/*Function to separate elements of structure of transactions, with the desired format (identifier ; date ; products) and and puts them in a vector*/

	size_t l = line.find_first_of(';'); /*Determines the size until you find the first semicolon.*/
	string first = line.substr(0, (l - 1)); /*Separates the first element (identifier) of the rest of the elements, that is, extract the first semicolon*/

	line = line.substr(l + 2); /*The line happens to be from space after the first semicolon*/
	l = line.find_first_of(';'); /*Find the second semicolon*/
	string second = line.substr(0, (l - 1)); /*Separates the second element (date)  of the rest of the elements, that is, extract the first semicolon*/

	const char * c = first.c_str();
	int number = atoi(c); /*Converts a variable of type integer to string, in this case converts the client identifier (of type integer) in a string*/

						  /*Correspondence between the parameters of the structure and the elements separated and converted into string*/

	Transaction object;

	object.setIdentifier(number);
	object.setDate(second);

	line = line.substr(l + 2); /*The line happens to be from space after the second semicolon*/

	int pos = line.find(','); /*Finds the position of the first comma of the vector of the products*/

	vector<string> productsList;

	while (pos != string::npos)
	{
		string substring = line.substr(0, pos); /*Separates the first product of the rest, that is, until the first comma extracts*/
		line = line.substr(pos + 2, line.length()); /*The line happens to be from space after the first comma*/

		productsList.push_back(substring);
		object.setProducts(productsList); /*Inserts in a vector the list of transaction structure*/
		pos = line.find(',');
	}

	string substring = line.substr(0, line.length()); /*Defines a substring including all products*/

	productsList.push_back(substring);
	object.setProducts(productsList); /*Inserts in a vector the list of transaction structure*/
	transactions.push_back(object); /*Inserts in the vector transactions, the structure of transactions*/

}

bool VendeMaisMais::readFileTransactions(vector<Transaction> &transactions, string &fileTransactions)
{
	/*Function that reads the contents of a text file, line by line*/

	ifstream fin;
	string line;
	int numberTotal;


	fin.open(fileTransactions); /*Open the file; exit program if the file couldn't be opened*/
	if (!fin.is_open())
	{
		return false;
	}

	/*Read each line of the file*/

	getline(fin, line, '\n');
	numberTotal = atoi(line.c_str());

	while (getline(fin, line))
	{
		if (line.size() > 1) /*If the size of line is > 0, calls the function Separate_transaction*/
			separate_transaction(line, transactions);
	}

	fin.close(); /*Close the file*/
}

void VendeMaisMais::informationTransactions(vector<Transaction> &transactions)
{
	//Function that show the information about all transactions of customers 

	cout << "Total number of transactions: " << transactions.size() << endl << endl;

	for (size_t i = 0; i < transactions.size(); i++)
	{
		cout << "Identifier: " << transactions.at(i).getIdentifier() << endl;
		cout << "Date of transaction: " << transactions.at(i).getDate() << endl;
		cout << "List of products: " << endl;

		for (size_t k = 0; k < transactions.at(i).getProducts().size(); k++)
		{
			cout << transactions.at(i).getProducts().at(k) << endl;
		}

		cout << endl;
	}

}

void VendeMaisMais::chronologicalOrder(vector<Transaction> &transactions)
{
	Date object;
	int min;

	for (int i = 0; i < transactions.size(); i++)
	{
		min = i;

		for (int j = i; j < transactions.size(); j++)
			if (object.separate_date(transactions.at(min).getDate()) > object.separate_date(transactions.at(j).getDate()))
				min = j;

		string tmp = transactions.at(i).getDate();
		transactions.at(i).setDate(transactions.at(min).getDate());
		transactions.at(min).setDate(tmp);

		int identifier = transactions.at(i).getIdentifier();
		transactions.at(i).setIdentifier(transactions.at(min).getIdentifier());
		transactions.at(min).setIdentifier(identifier);

		vector<string> products = transactions.at(i).getProducts();
		transactions.at(i).setProducts(transactions.at(min).getProducts());
		transactions.at(min).setProducts(products);

	}


	cout << "Total number of transactions: " << transactions.size() << endl << endl;

	for (size_t i = 0; i < transactions.size(); i++)
	{
		cout << "Identifier: " << transactions.at(i).getIdentifier() << endl;
		cout << "Date of transaction: " << transactions.at(i).getDate() << endl;
		cout << "List of products: " << endl;

		for (size_t k = 0; k < transactions.at(i).getProducts().size(); k++)
		{
			cout << transactions.at(i).getProducts().at(k) << endl;
		}

		cout << endl;
	}
}

void VendeMaisMais::transactionsDay(vector<Transaction> &transactions)
{
	/*Function that displays the information of all transactions a day*/

	int i = 0;
	string date1;
	bool find = false;

	/*Request data to the user*/
	cout << "Please insert date 1 (day/month/year): " << endl;
	cin >> date1;
	cout << endl;

	Date object;

	while (!object.verifyDate(date1)) //Check if the date 1 is valid
	{
		cout << "This date isn't valid." << endl;
		cout << "Please insert date (day/month/year): ";
		cin >> date1;
		cout << endl;
	}

	/*Cycle that runs all the transaction structure dates*/
	while (i < transactions.size())
	{
		if (date1 == transactions.at(i).getDate())
		{
			find = true; /*Put the variable to find true when it finds the user's chosen date*/
			cout << "Identifier of customer: " << transactions.at(i).getIdentifier() << endl;
			cout << "List of products: " << endl;

			for (size_t k = 0; k < transactions.at(i).getProducts().size(); k++)
			{
				cout << transactions.at(i).getProducts().at(k) << endl;
			}
			cout << endl;
		}
		i++;
	}

	/*If you do not find the user's chosen date shows this message on the screen*/
	if (!find)
		cout << "No one made purchases that day. Try again, please." << endl << endl;
}

void VendeMaisMais::transactionsBetweenDates(vector<Transaction> &transactions)
{
	/*Function that show the information about transactions of customers between days*/

	string date1;
	string date2;
	int i = 0;
	bool find = false;

	cout << "Please insert date 1 (day/month/year): ";
	cin >> date1;

	Date object;


	while (!object.verifyDate(date1)) //Check if the date 1 is valid
	{
		cout << "This date isn't valid." << endl;
		cout << "Please insert date 1 (day/month/year): ";
		cin >> date1;
		cout << endl;
	}


	cout << "Please insert date 2 (day/month/year): ";
	cin >> date2;
	cout << endl;

	Date object2;

	while (!object2.verifyDate(date2)) //Check if the date 2 is valid
	{
		cout << "This date isn't valid." << endl;
		cout << "Please insert date 2 (day/month/year): ";
		cin >> date2;
		cout << endl;
	}


	while (i < transactions.size())
	{
		if (transactions.at(i).getDate() >= date1 && transactions.at(i).getDate() <= date2)
		{
			find = true;

			cout << "\n\nIdentifier: " << transactions.at(i).getIdentifier() << endl;
			cout << "Date of transaction: " << transactions.at(i).getDate() << endl;
			cout << "List of products: " << endl;


			for (int k = 0; k < transactions.at(i).getProducts().size(); k++)
			{
				cout << transactions.at(i).getProducts().at(k) << endl;
			}
		}

		i++;
	}

	if (!find)
		cout << "Try again." << endl << endl;


}

bool VendeMaisMais::verifyTransaction(vector<Transaction> &transactions, int identifier)
{
	/*Function to check if the identifier that user entered exists in stock*/

	int i = 0;

	for (size_t i = 0; i < transactions.size(); i++)
	{
		if (transactions.at(i).getIdentifier() == identifier)
			return true;
	}

	return false;
}

int VendeMaisMais::returnIdentifier(vector <Customer> &customers, string name)
{
	int i = 0;
	int identifier;
	bool find = false;

	while (!find && i < customers.size())
	{
		if (name == customers.at(i).getName())
		{
			identifier = customers.at(i).getIdentifier();
			find = true;
		}
		i++;
	}

	/*If you do not find the user's chosen date shows this message on the screen*/
	if (!find)
		cout << "Customer doesn't exist. Try again, please." << endl;

	return identifier;
}

void VendeMaisMais::transactionsOneCustomer_name(vector <Customer> &customers, vector<Transaction> &transactions)
{
	/*Function that show the information about one customer*/

	int i = 0;
	bool find = false;
	string name;
	Transaction object;

	cout << "What is the name of customer? ";
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, name);
	cout << endl;

	int identifier = returnIdentifier(customers, name);

	/*Cycle that runs all the transaction structure dates*/
	while (i < transactions.size())
	{
		if (transactions.at(i).getIdentifier() == identifier)
		{
			find = true;
			cout << "Identifier of customer: " << transactions.at(i).getIdentifier() << endl;
			cout << "Date of transaction: " << transactions.at(i).getDate() << endl;
			cout << "List of products: " << endl;

			for (size_t k = 0; k < transactions.at(i).getProducts().size(); k++)
			{
				cout << transactions.at(i).getProducts().at(k) << endl;
			}
			cout << endl;

		}

		i++;
	}

	/*If you do not find the user's chosen date shows this message on the screen*/
	if (!find)
		cout << "This customer doesn't make purchases. Try again, please." << endl << endl;

}

void VendeMaisMais::transactionsOneCustomer(vector <Customer> &customers, vector<Transaction> &transactions)
{
	/*Function that displays the information of all transactions a day*/

	int i = 0;
	unsigned int identifier;
	bool find = false;

	/*Request data to the user*/
	cout << "What is the identifier of customer? ";
	cin >> identifier;

	while (verifyCustomer(customers, identifier) == false) /*Check if the customer exists*/
	{
		cout << "This customer don't exist. Try again." << endl;
		cout << "Identifier: ";
		cin >> identifier;
	}


	/*Cycle that runs all the transaction structure dates*/
	while (i < transactions.size())
	{
		if (transactions.at(i).getIdentifier() == identifier)
		{
			find = true;
			cout << "\nIdentifier of customer: " << transactions.at(i).getIdentifier() << endl;
			cout << "Date of transaction: " << transactions.at(i).getDate() << endl;
			cout << "List of products: " << endl;

			for (size_t k = 0; k < transactions.at(i).getProducts().size(); k++)
			{
				cout << transactions.at(i).getProducts().at(k) << endl;
			}
			cout << endl;

		}

		i++;
	}

	/*If you do not find the user's chosen date shows this message on the screen*/
	if (!find)
		cout << "This customer doesn't make purchases. Try again, please." << endl << endl;
}

float VendeMaisMais::priceProduct(vector<Product> &products, string product)
{
	for (int i = 0; i < products.size(); i++)
	{
		if (product == products.at(i).getName())
			return products.at(i).getCost();
	}
}

int VendeMaisMais::returnIndex(vector<Customer> &customers, int identifier)
{
	for (int i = 0; i < customers.size(); i++)
	{
		if (identifier == customers.at(i).getIdentifier())
		{
			return i;
		}
	}
}

int VendeMaisMais::makePurchases(vector<Customer> &customers, vector<Transaction> &transactions, vector<Product> &products, string &fileCustomers, string &fileTransactions)
{
	ifstream fin;
	ofstream foutC;
	ofstream foutT;
	Transaction new_transaction;
	Customer new_customer;
	int i = 0;
	int j;
	int number;
	unsigned int identifier;
	string date;
	vector<string> productsTransaction;
	string prod;
	string input;
	int n = 0;

	/*Request data to the user*/
	cout << "What is the identifier of customer? ";
	cin >> identifier;

	while (verifyCustomer(customers, identifier) == false) /*Check if the customer exists*/
	{
		cout << "This customer don't exist. Try again." << endl;
		cout << "Identifier: ";
		cin >> identifier;
	}

	cout << "\nWhat is the date of transaction? \nPlease indicate in this format: day/month/year: ";
	cin >> date;
	cout << endl;
	cout << "Products available: " << endl;

	while (i < products.size()) /*Show all products available*/
	{
		cout << products.at(i).getName() << endl;
		i++;
	}

	cout << "\nHow many products do you want buy? ";
	cin >> number;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << endl;
	cout << "What are the products of you want?" << endl;

	j = returnIndex(customers, identifier);

	while (number != 0)
	{
		cout << "Product " << n + 1 << ": ";
		getline(cin, prod);

		if (verifyProducts(products, prod)) /*Checks for the products in stock*/
			productsTransaction.push_back(prod);

		else
			cout << "This product don't exist. Try again." << endl;


		customers.at(j).setVolumePurchases(priceProduct(products, prod) + customers.at(j).getVolumePurchases());

		number--;
		n++;
	}

	foutC.open(fileCustomers);

	/*Insert in file with the desired format (identifier ; name ; value)*/

	foutC << customers.size() << endl;
	for (size_t i = 0; i < customers.size(); i++)
	{
		foutC << customers.at(i).getIdentifier() << " ; " << customers.at(i).getName() << " ; " << customers.at(i).getDate() << " ; " << customers.at(i).getVolumePurchases() << endl;
	}

	foutC.close();


	new_transaction.setIdentifier(identifier);
	new_transaction.setDate(date);
	new_transaction.setProducts(productsTransaction);


	transactions.push_back(new_transaction); /*Insert in vector of transactions the new purchase*/


	foutT.open(fileTransactions); /*Open file of transactions*/

	foutT << transactions.size() << endl;

	for (size_t i = 0; i < transactions.size(); i++)
	{
		foutT << transactions.at(i).getIdentifier() << " ; " << transactions.at(i).getDate() << " ; ";

		for (size_t k = 0; k < transactions.at(i).getProducts().size(); k++)
		{
			foutT << transactions.at(i).getProducts().at(k);

			if (k < transactions.at(i).getProducts().size() - 1)
			{
				foutT << ", ";
			}
		}
		foutT << endl;
	}

	foutT.close(); /*Close the file*/

	return 0;
}

/*********************************
Product management
********************************/

void VendeMaisMais::separate_product(string line, vector<Product> &products, unsigned int & index)
{
	/*Function to separate elements of structure of products, with the desired format (product ; price) and and puts them in a vector*/

	size_t l = line.find_first_of(';'); /*Determines the size until you find the first semicolon.*/
	string first = line.substr(0, (l - 1)); /*Separates the first element (product), that is, it extracts the first semicolon*/

	string second = line.substr(l + 2); /*Extracts the rest of the line (value)*/

	const char * c = second.c_str();
	float number = stof(c); /*Converts a variable of type float to string, in this case converts the product price (of type float) in a string*/

							/*Correspondence between the parameters of the product structure and the elements separated and converted into string*/

	Product object;

	object.setName(first);
	object.setCost(number);

	products.push_back(object); //Inserts in the vector customers customer class
	productIdx[first] = index;
	index++;

}

bool VendeMaisMais::readFileProducts(vector<Product> &products, string &fileProducts)
{
	/*Function that reads the contents of a text file, line by line*/

	ifstream fin;
	string line;
	unsigned int counter = 0;
	int numberTotal;

	fin.open(fileProducts); /*Open the file; exit program if the file couldn't be opened*/
	if (!fin.is_open())
		return false;

	/*Read each line of the file*/

	getline(fin, line, '\n');
	numberTotal = atoi(line.c_str());

	while (getline(fin, line))
	{

		if (line.size() > 1) /*If the size of line is > 1, calls the function Separate_product*/
			separate_product(line, products, counter);
	}

	fin.close(); /*Close the file*/
}

void VendeMaisMais::informationProducts(vector<Product> &products)
{
	/*Function that show the information about all products*/
	cout << "Number of available products: " << products.size() << endl << endl;

	for (int i = 0; i < products.size(); i++)
	{
		cout << "Product: " << products.at(i).getName() << endl;
		cout << "Price: " << products.at(i).getCost() << endl;
		cout << endl;
	}
}

bool VendeMaisMais::verifyProducts(vector<Product> &products, string prod)
{
	/*Function to check if the product that user entered exists in stock*/

	int i = 0;

	for (size_t i = 0; i < products.size(); i++)
	{
		if (products.at(i).getName().compare(prod) == 0)
			return true;
	}

	return false;

}

/******************************************
Recomendation system
******************************************/

void VendeMaisMais::bottom10VP(vector<Customer> &customers)
{
	int min;

	if (customers.size() < 10)
	{
		cout << "It is not possible to make a list with the 10 worst customers!" << endl;
		cout << "There are fewer than 10 customers in the customers file" << endl;
	}

	else
	{
		for (int i = 0; i < customers.size(); i++)
		{
			min = i;

			for (int j = i; j < customers.size(); j++)
				if (customers.at(min).getVolumePurchases() > customers.at(j).getVolumePurchases())
					min = j;

			float tmp = customers.at(i).getVolumePurchases();
			customers.at(i).setVolumePurchases(customers.at(min).getVolumePurchases());
			customers.at(min).setVolumePurchases(tmp);

			int identifier = customers.at(i).getIdentifier();
			customers.at(i).setIdentifier(customers.at(min).getIdentifier());
			customers.at(min).setIdentifier(identifier);

			string name = customers.at(i).getName();
			customers.at(i).setName(customers.at(min).getName());
			customers.at(min).setName(name);

			string date = customers.at(i).getDate();
			customers.at(i).setDate(customers.at(min).getDate());
			customers.at(min).setDate(date);

		}

		cout << "\nTHE 10 WORST CUSTOMERS OF SUPERMARKET VENDE++ are: \n\n";

		for (int i = 0; i < 10; i++)
		{
			cout << "Identifier: " << customers.at(i).getIdentifier() << endl;
			cout << "Name: " << customers.at(i).getName() << endl;
			cout << "Accession date: " << customers.at(i).getDate() << endl;
			cout << "Amount: " << customers.at(i).getVolumePurchases() << endl << endl;

		}
	}

}

void VendeMaisMais::vectorBottom10(unsigned int id, vector<int> &result, vector<Transaction> &transactions)
{
	for (int i = 0; i < transactions.size(); i++)
	{
		if (transactions.at(i).getIdentifier() == id)
		{
			for (int j = 0; j < transactions.at(i).getProducts().size(); j++)
				result[j]++;
		}
	}
}

void VendeMaisMais::saveProducts(vector <string> &product_recomendation, vector<bool> line, vector<Product> &products)
{
	//function that takes the line of a customer and saves in a vector(product_recomendation) products purchased by this

	for (int i = 0; i < line.size(); i++)
	{
		if (line.at(i))
			product_recomendation.push_back(products.at(i).getName());
	}
}

int VendeMaisMais::chooseProduct(vector<string> &product_recomendation, string prod)
{
	int counter = 0;

	for (int i = 0; i < product_recomendation.size(); i++)
	{
		if (prod == product_recomendation.at(i))
			counter++;
	}

	return counter;

}

int VendeMaisMais::maxCommonProduct(vector <int> &number)
{
	int max = 0;

	for (int i = 0; i < number.size(); i++)
	{
		if (number.at(i) > max)
		{
			max = number.at(i);
		}
	}

	return max;
}

int VendeMaisMais::returnIndexMax(vector<int> &number)
{
	int maxProductsRecomendation = 0;
	int k;

	for (int i = 0; i < number.size(); i++)
	{
		if (number.at(i) > maxProductsRecomendation)
		{
			maxProductsRecomendation = number.at(i);
			k = i;
		}
	}

	return k;

}

int VendeMaisMais::returnIndexProduct(vector <int> &productsSupermarket, int max)
{
	for (int i = 0; i < productsSupermarket.size();i++)
	{
		if (max == productsSupermarket.at(i))
		{
			return i;
		}
	}
}

void VendeMaisMais::saveCommonProduct(vector <int> &commonProduct, vector <int> &number , vector <Product> &products, int max)
{
	for (int i= 0; i < number.size();i++)
	{
		if (number.at(i) == max)
			commonProduct.push_back(1);
		else
			commonProduct.push_back(0);
	}
}

bool VendeMaisMais::discoverOtherCustomer(vector <int> &commonProduct, vector<bool> line)
{
	bool find = true;

	for (int i = 0; i < commonProduct.size(); i++)
	{
		if (commonProduct.at(i) == 1)
		{
			if (!line.at(i))
			{
				find = false;
			}
		}

	}
	return find;
}

void VendeMaisMais::purchasedProduct(vector <string> &get_recomendation, vector <int> &commonProduct, vector <Product> products, vector <bool> line)
{
	/*Recommends to customer what is not purchased and isn't in commonProduct 
	vector and check if the product already is in get_recomendation vector*/

	int j = 0;
	bool found = false;

	for (int i = 0; i < line.size(); i++)
	{
		if (commonProduct.at(i) == 0 && line.at(i))
		{
			if (get_recomendation.size() == 0)
				get_recomendation.push_back(products.at(i).getName());

			else
			{
				j = 0;
				while (j < get_recomendation.size() && !found)
				{
					if (products.at(i).getName() == get_recomendation.at(j))
						found = true;

					j++;
				}

				if (found == false)
				{
					get_recomendation.push_back(products.at(i).getName());
				}

				found = false;
			}
		}
	}

}

void VendeMaisMais::customersPurchases(vector <string> &customerPurchases, vector <bool> line, vector <Product> &products)
{
	for (int i = 0; i < line.size(); i++)
	{
		if (line.at(i))
			customerPurchases.push_back(products.at(i).getName());

	}
}

void VendeMaisMais::recomendationBottom10(vector<Customer> &customers, vector<Product> &products, vector<Transaction> &transactions)
{
	int nlines = maximumIdentifier(customers, transactions);
	int ncolumns = products.size();
	vector<unsigned int> ids; //identifiers that do not belong to bottom10
	vector <string> product_recomendation; //products purchased by bottom10
	vector <int> number; //save the frequency of each product purchased by bottom10
	vector <int> commonProduct; //place the number one in every products that were purchased the same number of times by bottom10
	vector <string> get_recomendation; //products recomendation
	vector <string> customerPurchases; //all products purchased by customers
	vector <int> productsSupermarket; //save the frequency of each product purchased by all the customers

	vector<vector<bool> > matrix_recomendation(nlines, vector<bool>(ncolumns, false)); /*Matrix*/

	for (int i = 0; i < transactions.size(); i++)
	{
		for (int k = 0; k < transactions.at(i).getProducts().size(); k++)
		{
			int lines = transactions.at(i).getIdentifier() - 1;
			int columns = productIdx[transactions.at(i).getProducts().at(k)];
			matrix_recomendation[lines][columns] = true; /*If the product is purchased, puts it true*/
		}
	}

//order customers, from worst to best
	for (int i = 0; i < customers.size(); i++) 
	{
		int min = i;

		for (int j = i; j < customers.size(); j++)
			if (customers.at(min).getVolumePurchases() > customers.at(j).getVolumePurchases())
				min = j;

		float tmp = customers.at(i).getVolumePurchases();
		customers.at(i).setVolumePurchases(customers.at(min).getVolumePurchases());
		customers.at(min).setVolumePurchases(tmp);

		int identifier = customers.at(i).getIdentifier();
		customers.at(i).setIdentifier(customers.at(min).getIdentifier());
		customers.at(min).setIdentifier(identifier);
	}

	
	for (int i = 10; i < customers.size(); i++) //store in a vector customer identifiers that do not belong to bottom10
	{
		ids.push_back(customers.at(i).getIdentifier());
	}
	
	for (int i = 0; i < 10; i++) //products purchased by bottom10
	{
		saveProducts(product_recomendation, matrix_recomendation[customers.at(i).getIdentifier() - 1], products);
	}

	/*store in a vector, according to the index of each product in the product vector, the frequency 
	of each product purchased by Bottom10*/
	for (int i = 0; i < products.size(); i++)
	{
		number.push_back(chooseProduct(product_recomendation, products.at(i).getName()));
	}

	//place the number one in every products that were purchased the same number of times by bottom10
	saveCommonProduct(commonProduct, number, products, maxCommonProduct(number)); 
	
	//finds customers who bought the same common products to bottom10 and keep other products bought by this customers in get_recomendation vector
	for (int i = 0; i < ids.size(); i++)
	{
		if (discoverOtherCustomer(commonProduct, matrix_recomendation[ids.at(i)-1]))
		{
			purchasedProduct(get_recomendation, commonProduct, products, matrix_recomendation[ids.at(i)-1]);
		}
	}

	//finds all products purchased by customers
	for (int i = 0; i < customers.size(); i++)
	{
		customersPurchases(customerPurchases, matrix_recomendation[customers.at(i).getIdentifier()-1], products);
	}

	/*save the frequency of each product purchased by all the customers 
	and sets to 0 the products that were purchased the same number of times by bottom10
	*/
	for (int i = 0; i < products.size(); i++)
	{
		if (commonProduct.at(i)== 1)
			productsSupermarket.push_back(0);
		else
		productsSupermarket.push_back(chooseProduct(customerPurchases, products.at(i).getName()));
	}

	//if there is no possible recommendation
	if (get_recomendation.size() == 0)
	{
		cout << "Don't exist recomendation." << endl << endl;
	}

//having a list of products to recommend, recommend only the one that is most purchased
	else
	{
		bool found_recomendation = false;
		int max = maxCommonProduct(productsSupermarket);

		while (max != 0 && !found_recomendation)
		{
			for (int i = 0; i < get_recomendation.size(); i++)
			{
				if (get_recomendation.at(i) == products.at(returnIndexProduct(productsSupermarket, max)).getName())
				{
					found_recomendation = true;
					cout << "The recommended product is " << get_recomendation.at(i) << endl << endl;
					break;
				}
			}

			max--;
		}

		if (!found_recomendation)
		{
			cout << "\nThe recommended product is " << get_recomendation.at(0) << endl << endl;
		}

	}
}

float VendeMaisMais::compare(vector<bool> line1, vector <bool> line2)
{
	/*Function that returns the division of the number of products purchased by both customers and the total number
	of products purchased by one customer.*/

	int count1 = 0;
	int count2 = 0;

	for (int i = 0; i < line1.size(); i++)
	{
		if (line1.at(i) == line2.at(i) && line1.at(i) == true)
			count1++;
		if (line1.at(i) == true)
			count2++;
	}

	return count1 / (float)count2;
}

void VendeMaisMais::getRecomendation(vector<string> &product_recomendation, vector<bool> line1, vector <bool> line2, vector<Product> &products)
{
	/*Recommends to customer what is not purchased*/

	for (int i = 0; i < line1.size(); i++)
	{
		if (line1.at(i) == false && line2.at(i) == true)
			product_recomendation.push_back(products.at(i).getName());
	}
}

unsigned int VendeMaisMais::requestId(vector<Customer> &customers, vector<Transaction> &transactions)
{
	unsigned int identifier;

	cout << "Please insert customer's identifier: ";
	cin >> identifier;

	while (!verifyCustomer(customers, identifier) && !verifyTransaction(transactions, identifier)) /*Check if identifier exist*/
	{
		cout << "This customers don't exist. Please, try again." << endl;
		cout << "Identifier: ";
		cin >> identifier;
	}

	return identifier;
}

void VendeMaisMais::recomendationSystem(vector<Customer> &customers, vector<Product> &products, vector<Transaction> &transactions, unsigned int identifier)
{
	int nlines = maximumIdentifier(customers, transactions);
	int ncolumns = products.size();
	const float RECOMENDATION = 0.50;
	vector<string> product_recomendation; //products recomendation
	vector<int> number; //number of times each product was purchased

	vector<vector<bool> > matrix_recomendation(nlines, vector<bool>(ncolumns, false)); /*Matrix*/

	for (int i = 0; i < transactions.size(); i++)
	{
		for (int k = 0; k < transactions.at(i).getProducts().size(); k++)
		{
			int lines = transactions.at(i).getIdentifier() - 1;
			int columns = productIdx[transactions.at(i).getProducts().at(k)];
			matrix_recomendation[lines][columns] = true; /*If the product is purchased, puts it true*/
		}
	}

	//find out who is the closest customer to the target customer
	float max = 0;
	for (int i = 0; i < nlines; i++)
	{
		if (i != identifier - 1)
		{
			float result = compare(matrix_recomendation[identifier - 1], matrix_recomendation[i]);

			if (result >= RECOMENDATION && result > max)
				max = result;
		}


	}
	//recommends that customer
	for (int i = 0; i < nlines; i++)
	{
		if (max == compare(matrix_recomendation[identifier - 1], matrix_recomendation[i]))
			getRecomendation(product_recomendation, matrix_recomendation[identifier - 1], matrix_recomendation[i], products);
	}

	//puts in the vector number the number of times each product was purchased
	for (int i = 0; i < products.size(); i++)
	{
		number.push_back(chooseProduct(product_recomendation, products.at(i).getName()));
	}

	cout << "\nThe recommended product is " << products.at(returnIndexMax(number)).getName() << endl << endl;

	/*If don't exist similiar purchases, in other words, if the vector with recommended products is empty, show this message*/
	if (product_recomendation.size() == 0)
		cout << "Don't exist recomendation." << endl;

}

