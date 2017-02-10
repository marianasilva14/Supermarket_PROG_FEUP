#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;


class Date {
private:
	unsigned int year;
	unsigned int month;
	unsigned int day;
	string dayMonthYear;

public:
	Date();
	Date(unsigned int day, unsigned int month, unsigned int year);
	Date(string DayMonthYear);
	void setYear(unsigned int year);
	void setMonth(unsigned int month);
	void setDay(unsigned int day);
	unsigned int getYear() const;
	unsigned int getMonth() const;
	unsigned int getDay() const;
	string getDate();
	void show();
	bool LeapYear(string date);
	int separate_date(string line);
	bool verifyDate(string date);
	unsigned int nDays(string date);
	bool operator==(const Date &date);
	bool operator>(const Date &date);
	bool operator<(const Date &date);
};

