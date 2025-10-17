#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include "student.h"

void loadStudents(std::vector<Student*>& students);
void showStudentNames(const std::vector<Student*>& students);
void printStudents(const std::vector<Student*>& students);
void findStudent(const std::vector<Student*>& students);
void deleteStudents(std::vector<Student*>& students);
std::string menu();
std::string sortMenu();
void sortStudents(std::vector<Student*>& students, const std::string& sortChoice);

int main(){
	std::vector<Student*> students;
	bool keepGoing = true;
	loadStudents(students);
	
	while(keepGoing) {
		std::string choice = menu();

		if (choice == "0") {
			keepGoing = false;
		} else if (choice == "1") {
			showStudentNames(students);
		} else if (choice == "2") {
			printStudents(students);
		} else if (choice == "3") {
			findStudent(students);
		} else if (choice == "4") {
			std::string sortChoice = sortMenu();
			sortStudents(students, sortChoice);
		} else {
			std::cout << "Invalid choice. Please enter 0-4." << std::endl;
		} // end if
	} // end while
	
	deleteStudents(students);
	return 0;
} // end main

void loadStudents(std::vector<Student*>& students) {
	std::ifstream file("students.csv");
	std::string line;
	while (std::getline(file, line)) {
		Student* s = new Student();
		s->init(line);
		students.push_back(s);
	} // end while
	file.close();
} // end loadStudents

void showStudentNames( const std::vector<Student*>& students) {
	for (const auto& s : students) {
		std::cout << s->getLastFirst() << std::endl;
	} // end for
} // end showStudentNames

void printStudents(const std::vector<Student*>& students) {
	for(const auto& s : students) {
		s->printStudent();
		std::cout << "______________" <<std::endl;
	} // end for
} // end printStudent



void findStudent(const std::vector<Student*>& students) {
	std::cout << "Last name of student: ";
	std::string searchTerm;
	std::getline(std::cin, searchTerm);

	bool found = false;
	for (const auto& s : students) {
		std::string last = s->getLastName();
		if (last.find(searchTerm) != std::string::npos) {
			s->printStudent();
			std::cout << "______________" <<std::endl;
			found = true;
		} // end if
	} // end for
	
	if (!found) {
		std::cout << "No students found with last name containing " << searchTerm << "." << std::endl;
	} // end if
} // end findStudent

void deleteStudents(std::vector<Student*>& students) {
	for (auto& s : students) {
		delete s;
	} // end for
	students.clear();
} // end deleteStudents

std::string menu() {
	std::cout << "0) quit" << std::endl;
	std::cout << "1) print all student names" << std::endl;
	std::cout << "2) print all student data" << std::endl;
	std::cout << "3) find a student" << std::endl;
	std::cout << "4) sort students" << std::endl;
	std::cout << "Please choose 0-4: ";
	std::string choice;
	std::getline(std::cin, choice);
	return choice;
} // end menu

std::string sortMenu() {
	std::cout << "1) sort by last name" << std::endl;
	std::cout << "2) sort by first name" << std::endl;
	std::cout << "3) sort by credit hours" << std::endl;
	std::cout << "Please choose 1-3: ";
	std::string choice;
	std::getline(std::cin, choice);
	return choice;
} // end sortMenu

void sortStudents(std::vector<Student*>& students, const std::string& sortChoice) {
	if (sortChoice == "1") {
		std::sort(students.begin(), students.end(),
				[](Student* a, Student* b) {
					return a->getLastName() < b->getLastName();
				});
		std::cout << "Sorted by last name." << std::endl;
	}
	else if  (sortChoice == "2") {
                std::sort(students.begin(), students.end(),
                                [](Student* a, Student* b) {
                                        return a->getFirstName() < b->getFirstName();
                                });
                std::cout << "Sorted by first name." << std::endl;
	}
	else if (sortChoice == "3") {
                std::sort(students.begin(), students.end(),
                                [](Student* a, Student* b) {
                                        return a->getCreditHours() > b->getCreditHours();
                                });
                std::cout << "Sorted by credit hours." << std::endl;
	}
	else {
		std::cout << "Invalid sort option." << std::endl;
	} // end if
} // end sortStudents
