void copyString(char* const dest, const char* const src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i = i + 1;
	}
	dest[i] = '\0';
}
char* inputString()
{
	char ch;
	int index = 0;
	int size = 25;
	char* arr = new char[size];
	cin.get(ch);
	while (ch != '\n')
	{
		if (index == size)
		{
			size *= 2;
			char* temp = new char[size];
			copyString(temp, arr);
			delete[] arr;
			arr = temp;
		}
		arr[index] = (char)ch;
		index = index + 1;
		cin.get(ch);
	}
	arr[index] = '\0';
	return arr;
}
int main()
{
	char* str = inputString();
	cout << "Start = " << str << " = " << "END";
	cout << endl;
	return 0;
}