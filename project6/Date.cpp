#include "date.h"
#include <iostream>
#include <sstream>

Date::Date() {
	dateString;
	month = 1;
	day = 29;
	year = 2009;
} // end Date

void Date::init(std::string dateString) {
	this->dateString = dateString;
	char sep;
	std::istringstream ss(dateString);
	ss >> month >> sep >> day >> sep >> year;
} // end init

void Date::printDate() {
	std::cout << month << "/" << day << "/" << year;
} // end printDate
