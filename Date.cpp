#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>

#include "Date.h"

using namespace std;

Date::Date()
{

}

Date::Date(unsigned int day, unsigned int month, unsigned int year)
{
	setYear(year);
	setMonth(month);
	setDay(day);
}

Date::Date(string DayMonthYear)
{
	sscanf_s(dayMonthYear.c_str(), "%d/%d/%d", &day, &month, &year);
}

void Date::setYear(unsigned int year)
{
	this->year = year;
}

void Date::setMonth(unsigned int month)
{
	this->month = month;
}

void Date::setDay(unsigned int day)
{
	this->day = day;
}

unsigned int Date::getYear() const
{
	return year;
}

unsigned int Date::getMonth() const
{
	return month;
}

unsigned int Date::getDay() const
{
	return day;
}

string Date::getDate()
{
	stringstream ss;
	ss << to_string(day) << "/" << to_string(month) << "/" << to_string(year);
	return ss.str();
}

void Date::show()
{
	cout << day << "/" << month << "/" << year << endl;
}

bool Date::LeapYear(string date)
{
	size_t l = date.find_first_of('/');
	string day = date.substr(0, l);

	date = date.substr(l + 1);
	l = date.find_first_of('/');
	string month = date.substr(0, l);

	string number = date.substr(l + 1);

	const char * c2 = number.c_str();
	int year = atoi(c2);

	if (year % 2 == 0 && year % 100 != 0)
		return true;
	else if (year % 400 == 0)
		return true;
	else
		return false;
}

int Date::separate_date(string line)
{
	/*Function to parse date*/

	int date;
	size_t l = line.find_first_of('/');
	string day = line.substr(0, l);

	line = line.substr(l + 1);
	l = line.find_first_of('/');
	string month = line.substr(0, l);

	string year = line.substr(l + 1);

	const char * c = day.c_str();
	int number = atoi(c);
	const char * c1 = month.c_str();
	int number2 = atoi(c1);
	const char * c2 = year.c_str();
	int number3 = atoi(c2);

	/*Date will be year*10000 + month*100 + day */

	number2 = number2 * 100;
	number3 = number3 * 10000;

	date = number + number2 + number3;

	return date;

}

bool Date::verifyDate(string date)
{
	/*Function to check the validity of data entered by the user*/

	int day, month, year;

	if ((sscanf_s(date.c_str(), "%d/%d/%d", &day, &month, &year) == 3) && (month >= 1 && month < 13 && day <= nDays(date)))
		return true;

	else
		return false;

}

unsigned int Date::nDays(string date)
{
	size_t l = date.find_first_of('/');
	string day = date.substr(0, l);

	date = date.substr(l + 1);
	l = date.find_first_of('/');
	string number2 = date.substr(0, l);

	const char * c1 = number2.c_str();
	int month = atoi(c1);

	if (month == 4 || month == 6 || month == 9 || month == 11)
		return 30;
	else if (month == 2)
	{
		if (LeapYear(date))
			return 29;
		else
			return 28;
	}
	else
		return 31;
}

bool Date::operator==(const Date& date)
{
	return year == date.getYear() && month == date.getMonth() && day == date.getDay();
}

bool Date::operator>(const Date &date)
{
	int date1 = year * 10000 + month * 100 + day;
	int date2 = date.getYear() * 10000 + date.getMonth() * 100 + date.getDay();

	return (date1 > date2);
}

bool Date::operator<(const Date &date)
{
	int date1 = year * 10000 + month * 100 + day;
	int date2 = date.getYear() * 10000 + date.getMonth() * 100 + date.getDay();

	return (date1 < date2);
}