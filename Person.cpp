#include "Person.h"
#include <stdexcept>
#include <sstream>
#include <iostream>
using namespace std;

Person::Person(string &firstName, string &lastName,
               string &DOB) {
    setFirstName(firstName);
    setLastName(lastName);
    setDOB(DOB);
}

void Person::setFirstName(std::string &firstName) {
    this->firstName = firstName;
}

void Person::setLastName(std::string &lastName) {
    this->lastName = lastName;
}

void Person::setDOB(std::string &DOB) {
    this->DOB = DOB;
}

string Person::getLastName() const {
    return lastName;
}

string Person::getFirstName() const {
    return firstName;
}

string Person::getDOB() const {
    return DOB;
}

string Person::toString() const {
    ostringstream output;

    output << getFirstName() << " " << getLastName() <<
           "\nDOB: " << getDOB() << endl;
    return output.str();

}


