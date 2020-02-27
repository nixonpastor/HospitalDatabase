#include <iostream>
#include<iomanip>
#include "DatabaseImplementation.h"
using namespace std;

int main(){

    int choice;
    readDoctorFile("Doctors.txt"); //reading file that stores doctor objects
    readPatientsFromFile("Patients.txt");//reading file that stores patient objects
    cout << setw(25) << "Welcome! " << endl;
   do{
    cout << "-------------------------------------------------\n";
    cout << setw(27) << "1. Add Patient" << endl;
    cout << setw(42) << "2. Update Patient Information" << endl;
    cout << setw(39) << "3. Get Patient Information" << endl;
    cout << setw(26) << "4. Add Doctor" << endl;
    cout << setw(42) << "5. Display Doctor Information" << endl;
    cout << setw(20) << "6. Exit" << endl;
    cout << setw(32) << "Enter your choice: ";
    cin >> choice;
    cout << "-------------------------------------------------\n";

    //switch on choice and call appropriate function
        switch (choice) {
            case 1:
                addPatient();
                writePatientsToFile("Patients.txt");
                break;
            case 2:
                updatePatientInfo();
                writePatientsToFile("Patients.txt");
                break;
            case 3:
                 getPatientInfo();
                 break;
            case 4:
                  addDoctor();
                  writeDoctorsToFile("Doctors.txt");
                  break;
           case 5:
               displayDoctors();
               break;
            case 6:
                cout << "Thank you for using the database!" << endl;
                break;
            default:
                cout << "Enter valid input: ";
                cin >> choice;
                break;
        }
    }while(choice != 6);
}

