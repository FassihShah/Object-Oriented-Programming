#include"CashPayment.h"
CashPayment::CashPayment(double amt) : Payment(amt)
{
}
void CashPayment::paymentDetails() const
{
    cout << "The payment of cash: $" << getAmount() << endl;
}