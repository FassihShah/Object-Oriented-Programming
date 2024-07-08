#ifndef CREDIT_CARD_PAYMENT_H
#define CREDIT_CARD_PAYMENT_H
#include"Payment.h"
#include"BigNumber.h"
#include"Date.h"
class CreditCardPayment : public Payment
{
    BigNumber cardNumber;
    Date expirationDate;
    String ownerName;
public:
    CreditCardPayment(double, const String&, const Date&, const BigNumber&);
    void paymentDetails() const;
};
#endif