#include "Doctor.h"
#include <iostream>
#include <iomanip>

using namespace std;


Doctor::Doctor(string& lastName, Specialty specialty){
    setDocLastName(lastName);
    setSpecialty(specialty);
}

string Doctor::getDocLastName() const {
    return this->lastName;
}

void Doctor::setDocLastName(string& lastName) {
    this->lastName = lastName;
}

void Doctor::setSpecialty(Specialty specialty) {
    this->specialty = specialty;
}

Specialty Doctor::getSpecialty() {
    return this->specialty;
}

void Doctor::displayName() const {
    cout << setw(10) << lastName  << setw(40);
    if (Specialty::General == specialty){
        cout << "General" << endl;
    }
    else
        cout << "Pediatrics" << endl;
}

