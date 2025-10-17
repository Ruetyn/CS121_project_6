# Heap of Students Documentation

## UML diagram
```mermaid
classDiagram
class Date {
    # string dateString
    # int month
    # int day
    # int year
    + Date()
    + void init(dataString)
    + void printDate()
}

class Address {
    # string street
    # string city
    # string state
    # string zip
    + Address()
    + void init(street, city, state, zip)
    + void printAddress()
}

class Student {
    # string studentString
    # string firstName
    # string lastName
    # Address' Address
    # Date' dob
    # Date' expectedGrad
    # int creditHours
    + Student()
    + ~Student()
    + void init(studenString)
    + void printStudent()
    + string getLastName()
    + string getLastFirst()
    + int getCreditHours()
}
  
Student o-- Date
Student o -- Address
```

## loadStudents
open students.csv file
while there are lines to read:
    read one line
    create a new Student on the heap
    call init(line) on that Student
    append pointer to vector
close file

## printStudents
for each student in vector:
    student->printStudent()
    print a divider for between students

## showStudentNames
for each student in vector:
    print student->getFirstLast()
    
## findStudents
prompt user for last name search term
for each student in vector:
    if student's last name contains search term:
        student->printStudent()
        print divider
    else if no matches found:
        print no matches found

## delStudents
for each student in vector:
    delete student
clear the vector

## menu()
print 0) quit
print 1) print all student names
print 2) print all student data
print 3) find a student
prompt the user for what they want to do
return choice string
        ask the user for the last name of the student they are searching for
        go through the student vector and find students that last name are either the input or contain the input
