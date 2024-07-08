#ifndef FILE_H
#define FILE_H
#include"Document.h"
class File:public Document
{
	String pathName;
	String fileName;
public:
	File(const String&, const String&, const String&);
	void setPathName(const String&);
	void setFileName(const String&);
	String getPathName() const;
	String getFileName() const;
	String toString() const;
};
#endif