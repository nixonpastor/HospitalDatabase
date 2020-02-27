#ifndef HOSPITALDATABASE_DATABASEIMPLEMENTATION_H
#define HOSPITALDATABASE_DATABASEIMPLEMENTATION_H

#include "Patient.h"
#include<iostream>
#include<fstream>
using namespace std;

//function prototypes
void addPatient();                    //adds a patient to hospital record
void updatePatientInfo();             //updates patient object details
void getPatientInfo();                //prints specific patient information
void addDoctor();                     //adds a doctor object
Doctor findDoctor(string);            //find specific doctor object from string
void readDoctorFile(string);          //hat reads in doctor objects from file
void readPatientsFromFile(string);    //reads in patient objects from file
void writePatientsToFile(string);     //writes Patient objects to Patients.txt
void writeDoctorsToFile(string);      //writes Doctor objects to Doctors.txt
void displayDoctors();                //displays the available doctora
void displayPatientNames();           //displays the names of the patients
Insurance getInsurance(string);       //find Insurance enum from string
Gender getGender(string&);            //finds Gender enum from string
string getInsuranceString(Insurance); //finds the insurance string from Insurance enum
string getGenderString(Gender);       //finds the gender based on Gender enum
Specialty getSpeciality(string);      //finds the Specialty based on input string
string getSpecialtyString(Specialty); //finds the Specialty of Doctor from Specialty enum
vector<Doctor> doctors;               //vector to store Doctor objects from/to files
vector<Patient> patients;             //vector to store Patient objects from/to files

void readDoctorFile(string filePath)
{
    ifstream inDoctorFile(filePath, ios::in); //opening file
    if(!inDoctorFile){
        cerr << filePath <<"File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    string lastName;
    string speciality;
    Specialty specialty1;

    //read in doctor objects and create vector of Doctor objects
    while(inDoctorFile >> lastName >> speciality){
        //if/else statement to find the Specialty of doctor based on string
        if(speciality == "General"){
            specialty1 = Specialty::General;
        }
        else {
            specialty1 = Specialty ::Pediatrics;
        }
        Doctor doctor(lastName, specialty1);
        doctors.push_back(doctor);
    }

    inDoctorFile.close();
}

//creating new doctor object to vector of Doctors
void addDoctor(){
    string lastNameOfDoctor;
    string specialtyDoc;
    Specialty specialty;

    cout << "Enter the last name of the doctor: ";
    cin >> lastNameOfDoctor;
    cout << "Enter the speciality of the doctor (Pediatrics or General): ";
    cin >> specialtyDoc;

    specialty = getSpeciality(specialtyDoc);

    Doctor doc(lastNameOfDoctor, specialty);

    doctors.push_back(doc); //adding doctor object to vector
}


Specialty getSpeciality(string specialty){
    Specialty specialty1;

    //if/else statement determinging the type of Specialty for Doctor
    if(specialty == "General"){
        specialty1 = Specialty::General;
    }
    else{
        specialty1 = Specialty::Pediatrics;
    }
    return specialty1;
}

string getSpecialtyString(Specialty specialty){
    string specialty1;

    //if/else statement determining the string of Doctor's Specialty
    if(specialty == Specialty::General){
        specialty1 = "General";
    }
    else{
        specialty1 = "Pediatrics";
    }
    return specialty1;
}

void writeDoctorsToFile(string filePath){
    ofstream outputDoctors(filePath, ios::out); //opening file to write
    if(!outputDoctors){
        cerr << filePath <<"File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    //writing doctor objects form vector to file
    for(int i=0; i < doctors.size(); i++){
        outputDoctors << doctors[i].getDocLastName() << " " << getSpecialtyString(doctors[i].getSpecialty()) << endl ;
    }

    outputDoctors.close();
}

//displaying the available doctors
void displayDoctors(){
    cout << setw(10) << "Doctors" << setw(40) << "Specialty" << endl;
    for(int i = 0; i < doctors.size(); i++){
        doctors[i].displayName();
    }
}

void writePatientsToFile(string filePath){
    ofstream outputPatients(filePath, ios::out);
    if(!outputPatients){
        cerr << filePath <<"File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    for(int i=0; i < patients.size(); i++){
        outputPatients << patients[i].getFirstName() << " " << patients[i].getLastName() << endl <<
                       patients[i].getDoctorLastName() << endl << patients[i].getDOB() << endl <<
                       getInsuranceString(patients[i].getInsurance()) << endl <<
                       getGenderString(patients[i].getGender()) << endl << patients[i].getBilling() << "\n\n";
    } // new


    outputPatients.close();
}

void readPatientsFromFile(string filePath){
    ifstream inPatients(filePath, ios::in);
    if(!inPatients){
        cerr << filePath <<"File could not be opened" << endl;
        exit(EXIT_FAILURE);
    }

    string lastName;
    string firstName;
    string DOB;
    string healthCare;
    string gender;
    string doctor;
    double bill;

    while (inPatients >> firstName >> lastName >> doctor >> DOB >> healthCare >> gender >> bill){
        Doctor doc = findDoctor(doctor);
        Insurance insurance1 = getInsurance(healthCare);
        Gender gender1 = getGender(gender);
        Patient patient(firstName, lastName, DOB, insurance1, gender1, bill, doc);
        patients.push_back(patient);
    }

    inPatients.close();
}

void addPatient(){
    string firstName;
    string lastName;
    string DOB;
    string insurance;
    string gender;
    string doctor;
    Insurance insurance1;
    Gender gender1;
    double bill;

    cout << "Enter the first name of patient: ";
    cin >> firstName;
    cout << "Enter the last name of the patient: ";
    cin >> lastName;
    cin.ignore();
    cout << "Enter the date of birth of the patient(mm/dd/yyyy): ";
    cin >> DOB;
    cout << "Enter the insurance of the patient (Medicare, BCBS, Aetna, UHC): ";
    cin >> insurance;
    insurance1 = getInsurance(insurance);
    cout << "Enter the gender of the patient(Male, Female, Transgender): ";
    cin >> gender;
    gender1 = getGender(gender);
    cout << "Enter the bill of the patient: ";
    cin >> bill;

    displayDoctors();
    cout << "Enter the last name of the doctor for the patient: ";
    cin >> doctor;

    Doctor doc = findDoctor(doctor);
    Patient patient(firstName, lastName, DOB, insurance1, gender1, bill, doc);
    patients.push_back(patient);

}



Doctor findDoctor(string lastName) {
    Doctor doc = doctors[0];
    for (int i = 0; i < doctors.size(); i++) {
        if (lastName == doctors[i].getDocLastName()) {
            doc = doctors[i];
        }
    }
    return doc;
}

void updatePatientInfo() {
    string originalFirstName;
    string originalLastName;
    string firstName;
    string lastName;
    string DOB;
    string insurance;
    string gender;
    string doctor;
    Insurance insurance1;
    Gender gender1;
    double bill;

    displayPatientNames();

    cout << "\nEnter the first name of the patient: ";
    cin >> originalFirstName;
    cout << "Enter the last name of the patient: ";
    cin >> originalLastName;

    Patient patient = patients[0];
    for (int i = 0; i < patients.size(); i++) {
        if (originalFirstName == patients[i].getFirstName() &&
            originalLastName == patients[i].getLastName()) {
            patient = patients[i];
        }
    }

    cout << endl;
    cout << "Update Information Menu" << endl;
    cout << "1. Update First Name" << endl;
    cout << "2. Update Last Name" << endl;
    cout << "3. Update Insurance" << endl;
    cout << "4. Update Gender" << endl;
    cout << "5. Set New Bill" << endl;
    cout << "6. Add to Bill" << endl;
    cout << "7. Change Doctor" << endl;
    cout << "Enter option: ";
    int option;
    cin >> option;

    switch (option) {
        case 1: {
            cout << "Enter new first name: ";
            cin >> firstName;
            patient.setFirstName(firstName);
            break;
        }
        case 2: {
            cout << "Enter new last name: ";
            cin >> lastName;
            patient.setLastName(lastName);
            break;
        }

        case 3: {
            cout << "Enter new insurance(Medicare, BCBS, Aetna, UHC): ";
            cin >> insurance;
            insurance1 = getInsurance(insurance);
            patient.setInsurance(insurance1);
            break;
        }
        case 4: {
            cout << "Enter new gender (Male, Female, Transgender): ";
            cin >> gender;
            gender1 = getGender(gender);
            patient.setGender(gender1);
            break;
        }
        case 5: {
            cout << "Enter the new bill: ";
            cin >> bill;
            patient.setNewBill(bill);
            break;
        }
        case 6: {
            cout << "Enter the amount to add to bill: ";
            cin >> bill;
            patient.updateBilling(bill);
            break;
        }
        case 7: {
            displayDoctors();
            cout << "Enter the last name of the new doctor: ";
            cin >> doctor;
            Doctor doc = findDoctor(doctor);
            try {
                patient.setDoctor(doc);
            }
            catch(exception& e){
                cout << e.what() << endl;
            }
            break;
        }
        default:
            cout << "Please enter a valid number. ";
            break;
    }

    for (int i = 0; i < patients.size(); i++) {
        if (originalFirstName == patients[i].getFirstName() &&
            originalLastName == patients[i].getLastName()) {
            patients[i] = patient;
            cout << patients[i].toString();
        }
    }
}


Insurance getInsurance(string insurance) {
    Insurance insurance1;

    if (insurance == "UHC") {
        insurance1 = Insurance::UHC;
    }
    if (insurance == "Medicare") {
        insurance1 = Insurance::Medicare;
    }
    if (insurance == "BCBS") {
        insurance1 = Insurance::BCBS;
    }
    if (insurance == "Aetna") {
        insurance1 = Insurance::Aetna;
    }
    return insurance1;
}

Gender getGender(string &gender) {
    Gender gender1;

    if (gender == "Male") {
        gender1 = Gender::Male;
    }
    if (gender == "Female") {
        gender1 = Gender::Female;
    }
    if (gender == "Transgender") {
        gender1 = Gender::Transgender;
    }

    return gender1;
}

string getInsuranceString(Insurance insurance) {
    string insurance1;

    if (insurance == Insurance::UHC) {
        insurance1 = "UHC";
    }
    if (insurance == Insurance::Medicare) {
        insurance1 = "Medicare";
    }
    if (insurance == Insurance::BCBS) {
        insurance1 = "BCBS";
    }
    if (insurance == Insurance::Aetna) {
        insurance1 = "Aetna";
    }
    return insurance1;
}

string getGenderString(Gender gender) {
    string gender1;

    if (gender == Gender::Male) {
        gender1 = "Male";
    }
    if (gender == Gender::Female) {
        gender1 = "Female";
    }
    if (gender == Gender::Transgender) {
        gender1 = "Transgender";
    }

    return gender1;
}

void getPatientInfo() {

    displayPatientNames();

    string firstName;
    string lastName;

    cout << "\nEnter the first name of the patient: ";
    cin >> firstName;
    cout << "Enter the last name of the patient: ";
    cin >> lastName;

    Patient patient = patients[0];
    for (int i = 0; i < patients.size(); i++) {
        if (firstName == patients[i].getFirstName() &&
            lastName == patients[i].getLastName()) {
            patient = patients[i];
        }
    }


    cout << endl << patient.toString();
}

void displayPatientNames() {
    cout << "Patients" << endl;
    for (int i = 0; i < patients.size(); i++) {
        cout << patients[i].getFirstName() << " " << patients[i].getLastName() << endl;
    }
}

#endif //HOSPITALDATABASE_DATABASEIMPLEMENTATION_H
