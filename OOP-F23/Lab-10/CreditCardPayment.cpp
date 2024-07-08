#include"CreditCardPayment.h"
CreditCardPayment::CreditCardPayment(double amt, const String& owner, const Date& expDate, const BigNumber& cardNum) : Payment(amt), cardNumber(cardNum), expirationDate(expDate), ownerName(owner)
{
}
void CreditCardPayment::paymentDetails() const
{
    cout << "The payment of $" << getAmount() << " through the card ";
    cardNumber.print();
    cout << ", and expire date ";
    expirationDate.printFormat1();
    cout << ", and the owner's name: " << ownerName << "." << endl;
}