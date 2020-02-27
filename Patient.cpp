#include "Patient.h"
#include <stdexcept>
#include <iostream>
#include <sstream>

using namespace std;

Patient::Patient(string& firstName, string& lastName, string& DOB,
                 Insurance insurances, Gender genders, double bill, Doctor doc): doc{doc},
        Person(firstName, lastName, DOB), insurance{insurances}, gender{genders}
{

    try {
        billing = Billing(bill);
    }
    catch(exception &e){
        cout << "Exception: " << e.what() << endl;
    }
    try{
        setDoctor(doc);
    }
    catch(invalid_argument& e){
        cout << "Exception: " << e.what() << endl;
     }
} // new


string Patient::getDoctorLastName() const {
    return doc.getDocLastName();
} //new

void Patient::setDoctor(Doctor& doc) {

    this->doc = doc;

}

void Patient::setInsurance(Insurance insurance) {
    this->insurance = insurance;
}

void Patient::setGender(Gender gender) {
    this->gender = gender;
}
void Patient::updateBilling(double num) {
    billing.addBill(num);
}

void Patient::setNewBill(double num) {
    try {
        billing.setBill(num);
    }
    catch(exception &e){
        cout << "Exception: " << e.what() << endl;
     }
}
double Patient::getBilling() const {
    switch(insurance){
        case(Insurance::BCBS):
        case(Insurance::Aetna):
            if(billing.getBill() > 500){
                return billing.getBill()-500;
            }
            else
                return billing.getBill();
        case(Insurance::UHC):
            if(billing.getBill() > 500){
                return billing.getBill()-300;
            }
            else
                return billing.getBill();
        default:
            if(billing.getBill()>200){
                return billing.getBill()-200;
            }
            return billing.getBill();
    }
}

std::string Patient::toString() const {
    ostringstream output;
    string insuranceName;
    string genderName;


    if(this->insurance == Insurance::Aetna){
        insuranceName = "Aetna";
    }
    else if(this->insurance == Insurance::Medicare){
        insuranceName = "Medicare";
    }
    else if(this->insurance == Insurance::UHC){
        insuranceName = "UHC";
    }
    else{
        insuranceName = "BCBS";
    }

    if(this->gender == Gender::Male){
        genderName = "Male";
    }
    else if(this->gender == Gender::Female){
        genderName = "Female";
    }
    else{
        genderName = "Transgender";
    }

    output << getFirstName() << " " << getLastName() << endl <<
            "Doctor: " << getDoctorLastName() << endl <<
           "Date of Birth: " << getDOB() << endl <<
            "Gender: " << genderName << endl <<
           "Insurance: " << insuranceName << endl <<
           "Bill with Insurance: $" << getBilling() << endl;
    return output.str();
}

Gender Patient::getGender() {
    return this->gender;
}

Insurance Patient::getInsurance() {
    return this->insurance;
}
