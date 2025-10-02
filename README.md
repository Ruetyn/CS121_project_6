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
