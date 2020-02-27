
#ifndef HOSPITALDATABASE_BILLING_H
#define HOSPITALDATABASE_BILLING_H

class Billing{
public:
    Billing();
    explicit Billing(double);
    void setBill(double);
    void addBill(double);
    double getBill() const;

private:
    double bill;
};

#endif //HOSPITALDATABASE_BILLING_H
