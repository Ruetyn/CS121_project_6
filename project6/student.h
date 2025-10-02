#ifndef STUDENT_H_EXISTS
#define STUDENT_H_EXISTS

#include "address.h"
#include "date.h"

class Student {
        protected:
                std::string studentString;
		std::string firstName;
		std::string lastName;
		// put address here
		// put dob here
		// put expected grad date here
		int creditHours;

        public:
                Student();
		~Student();
                void init(std::string studentString);
                void printStudent();
		std::string getLastName();
		std::string getFirstName();
		int getCreditHours();
} // end class def

#endif
