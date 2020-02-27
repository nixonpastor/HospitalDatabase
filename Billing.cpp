#include "Billing.h"
#include <stdexcept>
#include <iostream>
using namespace std;

Billing::Billing(double bill){
    try {
        setBill(bill);
    }
    catch(exception &e){
        cout << "Exception: " << e.what() << endl;
      }
}

Billing::Billing() {
    try{
    setBill(0);
    }
    catch(exception &e){
        cout << "Exception: " << e.what() << endl;
     }
}

void Billing::setBill(double b){
    if(b >= 0 ){
       this->bill=b;
    }
    else
        throw invalid_argument("Bill cannot be negative.");
}

void Billing::addBill(double b) {
   this->bill = this->bill + b;
}


double Billing::getBill() const {
    return bill;
}