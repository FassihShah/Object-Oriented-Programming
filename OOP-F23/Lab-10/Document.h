#ifndef DOCUMENT_H
#define DOCUMENT_H
#include"String.h"
class Document
{
	String text;
public:
	Document(const String&);
	String toString() const;
};
#endif