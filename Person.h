//
// Created by Nixon Pastor on 2/1/20.
//

#ifndef HOSPITALDATABASE_PERSON_H
#define HOSPITALDATABASE_PERSON_H

#include <string>



class Person{
public:
    Person(std::string&, std::string&,std::string&);
    void setFirstName(std::string&);
    void setLastName(std::string&);
    void setDOB(std::string&);
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getDOB() const;
    virtual std::string toString() const;
    virtual ~Person() = default;

private:
    std::string firstName;
    std::string lastName;
    std::string DOB;
};

#endif //HOSPITALDATABASE_PERSON_H
