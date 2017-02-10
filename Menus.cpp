#include "Menus.h"

Customer customervar;
Product productvar;
Transaction transactionvar;
VendeMaisMais vendevar;
Date datevar;

/******************************************
Customer management
******************************************/

unsigned short int menuCustomers(vector <Customer> &customers, vector <Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions)
{
	unsigned short int chosenOption;
	int id = 0;

	/*Menu of customers, where the user can choose what the option that wants*/
	clearScreen();

	cout << TAB_BIG << "MENU CUSTOMER MANAGEMENT" << endl;
	cout << endl;
	cout << TAB << "1- Show information about all customers" << endl;
	cout << TAB << "2- Show information about one customer" << endl;
	cout << TAB << "3- Show customers in alphabetical order" << endl;
	cout << TAB << "4- Edit customers" << endl;
	cout << TAB << "5- Remove customers" << endl;
	cout << TAB << "6- Insert new customer" << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		vendevar.informationCustomers(customers);
		break;

	case 2:
		menuOneCustomer(customers, products, transactions, fileCustomers, fileProducts, fileTransactions);
		break;

	case 3:
		vendevar.customersListAlphaOrder(customers);
		break;

	case 4:
		id = vendevar.askIdentifier(customers);
		menuEditCustomer(customers, fileCustomers, id);
		break;

	case 5:
		vendevar.removeCustomers(customers, fileCustomers);
		break;
	case 6:
		vendevar.insertCustomers(customers, transactions, fileCustomers);
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

unsigned short int menuOneCustomer(vector<Customer> &customers, vector <Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions)
{
	unsigned short int chosenOption;

	cout << TAB_BIG << "How do you want search?" << endl;
	cout << endl;
	cout << TAB << "1- Through identifier" << endl;
	cout << TAB << "2- Through name" << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		vendevar.informationOneCustomer(customers);
		break;

	case 2:
		vendevar.informationOneCustomer_name(customers);
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

unsigned short int menuEditCustomer(vector<Customer> &customers, string &fileCustomers, int id)
{
	unsigned short int chosenOption;
	do
	{

		cout << TAB_BIG << "What do you want to change?" << endl;
		cout << endl;
		cout << TAB << "1- Name" << endl;
		cout << TAB << "2- Accession date" << endl;
		cout << TAB << "3- Volume of Purchases" << endl;
		cout << TAB << "0- Out if there is not longer anything to be changed" << endl;


		cout << "What is the option that you want? ";
		cin >> chosenOption;
		cout << endl;


		switch (chosenOption)
		{
		case 1:
			vendevar.editCustomer_name(customers, fileCustomers, id);
			break;

		case 2:
			vendevar.editCustomer_date(customers, fileCustomers, id);
			break;

		case 3:
			vendevar.editCustomer_VolumePurchases(customers, fileCustomers, id);
			break;

		case 0:
			return 0;

		default:
			cout << "Invalid option. Try again." << endl;
			break;
		}
	} while (chosenOption != 0);
	return 0;
}

/******************************************
Transaction management
******************************************/

unsigned short int menuTransactions(vector <Customer> &customers, vector <Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions)
{
	unsigned short int chosenOption;

	clearScreen();

	cout << TAB_BIG << "MENU TRANSACTION MANAGEMENT" << endl;
	cout << endl;
	cout << TAB << "1- Show all customer transactions" << endl;
	cout << TAB << "2- Show transactions day" << endl;
	cout << TAB << "3- Show transactions between two dates" << endl;
	cout << TAB << "4- Show transactions in chronological order" << endl;
	cout << TAB << "5- Show transactions about one customer" << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		vendevar.informationTransactions(transactions);
		break;

	case 2:
		vendevar.transactionsDay(transactions);
		break;

	case 3:
		vendevar.transactionsBetweenDates(transactions);
		break;

	case 4:
		vendevar.chronologicalOrder(transactions);
		break;

	case 5:
		menuTransactionsOneCustomer(customers, transactions, fileCustomers, fileTransactions);
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

unsigned short int menuTransactionsOneCustomer(vector <Customer> &customers, vector<Transaction> &transactions, string &fileCustomers, string &fileTransactions)
{
	unsigned short int chosenOption;

	cout << TAB_BIG << "How do you want search?" << endl;
	cout << endl;
	cout << TAB << "1- Through identifier" << endl;
	cout << TAB << "2- Through name" << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		vendevar.transactionsOneCustomer(customers, transactions);
		break;

	case 2:
		vendevar.transactionsOneCustomer_name(customers, transactions);
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

/******************************************
Make purchases
******************************************/

unsigned short int menuPurchases(vector <Customer> &customers, vector <Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions)
{
	unsigned short int chosenOption;

	clearScreen();

	cout << TAB_BIG << "MENU MAKE PURCHASES" << endl;
	cout << endl;
	cout << TAB << "1- Show information about products" << endl;
	cout << TAB << "2- Make purchases" << endl;

	cout << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		vendevar.informationProducts(products);
		break;

	case 2:
		vendevar.makePurchases(customers, transactions, products, fileCustomers, fileTransactions);
		break;

	default:
		cout << "Invalid option. Try again." << endl;
		break;
	}

	return 0;
}

/******************************************
Recomendation system
******************************************/

unsigned short int menuRecomendationSystem(vector <Customer> &customers, vector <Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions)
{
	unsigned short int chosenOption;
	unsigned int id;

	clearScreen();

	cout << TAB_BIG << "MENU RECOMENDATION SYSTEM" << endl;
	cout << endl;
	cout << TAB << "1- Customer Recomendation" << endl;
	cout << TAB << "2- Bottom 10 worst Customers" << endl;
	cout << TAB << "3- Campaign Bottom 10" << endl;

	cout << TAB << "What is the option that you want? ";
	cin >> chosenOption;
	cout << endl;

	switch (chosenOption)
	{
	case 1:
		id = vendevar.requestId(customers, transactions);
		vendevar.recomendationSystem(customers, products, transactions, id);
		break;
	case 2:
		vendevar.bottom10VP(customers);
		break;
	case 3:
		vendevar.recomendationBottom10(customers,products,transactions);
		break;
	default:
		cout << "Invalid option. Try again." << endl;
		break;

	}
	return 0;
}

/******************************************
Main Menu
******************************************/

unsigned short int mainMenu(vector <Customer> &customers, vector<Product> &products, vector<Transaction> &transactions, string &fileCustomers, string &fileProducts, string &fileTransactions)
{
	unsigned short int chosenOption;
	ifstream fin;
	string line;

	if (vendevar.readFileCustomers(customers, fileCustomers) && vendevar.readFileProducts(products, fileProducts) && vendevar.readFileTransactions(transactions, fileTransactions))
	{
		do
		{
			cout << TAB_BIG << "Main Menu" << endl;
			cout << endl;
			cout << TAB << "1- Customers management" << endl;
			cout << TAB << "2- Make purchases" << endl;
			cout << TAB << "3- Transactions management" << endl;
			cout << TAB << "4- Recomendation system" << endl;
			cout << TAB << "0- Exit program" << endl << endl;

			cout << TAB << "What is the option that you want? ";
			cin >> chosenOption;
			cout << endl;

			switch (chosenOption)
			{
			case 1:
				menuCustomers(customers, products, transactions, fileCustomers, fileProducts, fileTransactions);
				break;

			case 2:
				menuPurchases(customers, products, transactions, fileCustomers, fileProducts, fileTransactions);
				break;

			case 3:
				menuTransactions(customers, products, transactions, fileCustomers, fileProducts, fileTransactions);
				break;

			case 4:
				menuRecomendationSystem(customers, products, transactions, fileCustomers, fileProducts, fileTransactions);
				break;
			case 0:
				return 0;

			default:
				cout << "Invalid option. Try again." << endl;
				break;
			}

		} while (chosenOption != 0);
	}

	else
	{
		cout << "File not found!\n";
		vendevar.requestFiles(fileCustomers, fileProducts, fileTransactions);
	}


	return 0;

}




