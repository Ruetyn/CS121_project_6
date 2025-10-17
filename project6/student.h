#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include "address.h"
#include "date.h"
#include <string>

class Student {
        protected:
		std::string firstName;
		std::string lastName;
		Address address;
		Date birthDate;
		Date gradDate;
		int creditHours;

        public:
                Student();
                void init(std::string studentString);
                void printStudent();
		std::string getLastName();
		std::string getFirstName();
		std::string getLastFirst();
		int getCreditHours();
}; // end class def

#endif
