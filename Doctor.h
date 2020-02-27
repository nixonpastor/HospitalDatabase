#ifndef HOSPITALDATABASE_DOCTOR_H
#define HOSPITALDATABASE_DOCTOR_H

#include <string>

enum class Specialty{General, Pediatrics};

class Doctor{
public:
    Doctor(std::string&, Specialty);
    void setDocLastName(std::string&);
    void setSpecialty(Specialty);
    Specialty getSpecialty();
    std::string getDocLastName() const;
    void displayName() const;


private:
    std::string lastName;
    Specialty specialty;

};
#endif //HOSPITALDATABASE_DOCTOR_H
