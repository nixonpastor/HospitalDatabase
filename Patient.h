#ifndef HOSPITALDATABASE_PATIENT_H
#define HOSPITALDATABASE_PATIENT_H

#include <string>
#include <vector>
#include "Person.h"
#include "Billing.h"
#include "Doctor.h"

enum class Insurance{Medicare, BCBS, Aetna, UHC};
enum class Gender{Female, Male, Transgender};

class Patient : public Person{
public:
    static const int MaxDoctors=2; // might not need this anymore
  //  Patient(std::string&, std::string&, std::string&, Insurance, Gender, double); original

    Patient(std::string&, std::string&, std::string&, Insurance, Gender, double, Doctor); //new
    std::string getDoctorLastName() const; // new

    void setInsurance(Insurance);
    void setGender(Gender);
    void setDoctor(Doctor&);
    void updateBilling(double);
    void setNewBill(double);
    double getBilling() const;
    Gender getGender();
    Insurance getInsurance();
    std::string toString() const override;
private:
    Doctor doc;
    Billing billing;
    Insurance insurance;
    Gender gender;
   // std::vector <Doctor> doctors;
};

#endif //HOSPITALDATABASE_PATIENT_H
