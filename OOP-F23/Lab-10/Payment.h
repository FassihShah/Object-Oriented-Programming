#ifndef PAYMENT_H
#define PAYMENT_H
#include<iostream>
using namespace std;
class Payment
{
    double amount;
public:
    Payment(double);
    double getAmount() const;
    void setAmount(double);
    void paymentDetails() const;
};
#endif