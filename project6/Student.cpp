#include "student.h"
#include <iostream>
#include <sstream>

Student::Student() {
	firstName = "";
	lastName = "";
	creditHours = 0;
} // end student

void Student::init(std::string studentString) {
	std::stringstream ss(studentString);
	std::string street, city, state, zip;
	std::string birthStr, gradStr;
	std::string creditStr;

	std::getline(ss, firstName, ',');
	std::getline(ss, lastName, ',');
	std::getline(ss, street, ',');
	std::getline(ss, city, ',');
	std::getline(ss, state, ',');
	std::getline(ss, zip, ',');
	std::getline(ss, birthStr, ',');
	std::getline(ss, gradStr, ',');
	std::getline(ss, creditStr, ',');

	address.init(street, city, state, zip);
	birthDate.init(birthStr);
	gradDate.init(gradStr);
	creditHours = std::stoi(creditStr);
} // end init

void Student::printStudent() {
	std::cout << firstName << " " << lastName << std::endl;
	address.printAddress();
	std::cout << "DOB: ";
	birthDate.printDate();
	std::cout << "Grad Date: ";
	gradDate.printDate();
	std::cout << "Credit Hours: " << creditHours << std::endl;
} // end printStudent

std::string Student::getLastFirst() {
	return lastName + ", " + firstName + ", " + std::to_string(creditHours);
} // end getLastFirst

std::string Student::getLastName() {
	return lastName;
} // end getLastName

std::string Student::getFirstName() {
	return firstName;
} // end getFirstName

int Student::getCreditHours() {
	return creditHours;
} // end getCreditHours
