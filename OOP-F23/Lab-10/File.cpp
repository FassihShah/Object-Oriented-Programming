#include"File.h"
File::File(const String& p, const String& f, const String& t):Document(t),pathName(p),fileName(f)
{
}
void File::setPathName(const String& p)
{
	pathName = p;
}
void File::setFileName(const String& f)
{
	fileName = f;
}
String File::getPathName() const
{
	return pathName;
}
String File::getFileName() const
{
	return fileName;
}
String File::toString() const
{
	String txt = "File Path: " + pathName + "\nFile Name: " + fileName + "\nContents: ";
	txt += Document::toString();
	return txt;
}