#include<iostream>
using namespace std;
bool isVowel(char ch)
{
	if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
	{
		return true;
	}
	else if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
	{
		return true;
	}
	return false;
}
int getLenght(const char* src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}
char* getVowelsFreeString(const char* ch)
{
	char* temp = new char[getLenght(ch) + 1];
	int i = 0, j = 0;;
	while (ch[i] != '\0')
	{
		if (!isVowel(ch[i]))
		{
			temp[j] = ch[i];
			j++;
		}
		i++;
	}
	temp[j] = '\0';
	return temp;
}
int main()
{
	char* str = getVowelsFreeString("hello how are you? I Am Fine");
	cout << str;
	cout << endl;
	return 0;
}