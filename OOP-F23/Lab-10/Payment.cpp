#include"Payment.h"
Payment::Payment(double amt) : amount(amt)
{
}
double Payment::getAmount() const
{
    return amount;
}
void Payment::setAmount(double amt)
{
    amount = amt;
}
void Payment::paymentDetails() const
{
    cout << "Payment amount: $" << amount << endl;
}