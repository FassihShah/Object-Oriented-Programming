#include"Email.h"
Email::Email(const String& s, const String& r, const String& t, const String& txt):Document(txt),sender(s),recipient(r),title(t)
{
}
void Email::setSender(const String& s)
{
	sender = s;
}
void Email::setRecipient(const String& r)
{
	recipient = r;
}
void Email::setTitle(const String& t)
{
	title = t;
}
String Email::getSender() const
{
	return sender;
}
String Email::getRecipient() const
{
	return recipient;
}
String Email::getTitle() const
{
	return title;
}
String Email::toString() const
{
	String txt = "Sender: " + sender + "\nRecipient: " + recipient + "\nTitle: " + title + "\nMessage: ";
	txt += Document::toString();
	return txt;
}