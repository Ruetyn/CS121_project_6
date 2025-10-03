#include "student.h"
#include "address.h"
#include "date.h"
#include <iostream>
#include <sstream>

Student::Student() {
	studentString;
	firstName;
	lastName;
	address = new Address;
	dob = new Date;
	expectedGrad = new Date;
	creditHours;
} // end student

Student::~Student() {} // end ~Student

void Student::init(std::string studentString) {
	this->studentString = studentString;
	char sep;
        std::istringstream ss(studentString);
        ss >> firstName >> sep >> lastName >> sep >> address >> sep >> dob >> sep >> expectedGrad >> sep >> creditHours;
} // end init

void Student::printStudent() {
	std::cout << firstName << " " << lastName << std::endl;
	address->printAddress();
	std::cout << "DOB: ";
	dob->printDate();
	std::cout << "Grad Date: ";
	expectedGrad->printDate();
	std::cout << "Credit Hours: " << creditHours << std::endl;
} // end printStudent

std::string Student::getLastName() {
	return lastName;
} // end getLastName

std::string Student::getFirstName() {
	return firstName;
} // end getFirstName

std::string Student::getLastFirst() {
	std::ostringstream ss;
	ss << lastName << ", " << firstName;
	return ss.str();
} // end getLastFirst

int Student::getCreditHours() {
	return creditHours;
} // end getCreditHours
