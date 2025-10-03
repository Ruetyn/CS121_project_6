#include "address.h"
#include <iostream>

Address::Address() {
	street = "";
	city = "";
	state = "";
	zip = "";
} // end Address

void Address::init(std::string street, std::string city, std::string state, std::string zip) {
	this->street = street;
	this->city = city;
	this->state = state;
	this->zip = zip;
} // end init

void Address::printAddress() {
	std::cout << street << ", " << city << ", " << state << " " << zip << std::endl;
} // end printAddress
