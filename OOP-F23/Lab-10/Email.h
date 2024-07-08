#ifndef EMAIL_H
#define EMAIL_H
#include"Document.h"
class Email :public Document
{
	String sender;
	String recipient;
	String title;
public:
	Email(const String&, const String&, const String&, const String&);
	void setSender(const String&);
	void setRecipient(const String&);
	void setTitle(const String&);
	String getSender() const;
	String getRecipient() const;
	String getTitle() const;
	String toString() const;
};
#endif