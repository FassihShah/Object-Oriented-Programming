#include"Document.h"
Document::Document(const String& t) :text(t)
{
}
String Document::toString() const
{
	return text;
}