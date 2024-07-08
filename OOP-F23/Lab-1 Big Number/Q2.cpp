int inputNumber()
{
	int num = 0;
	char ch;
	bool negStatus = false, status = false;
	while (!status)
	{
		cout << "Enter Number: ";
		num = 0;
		status = true;
		cin.get(ch);
		if (ch == '-')
		{
			negStatus = true;
			cin.get(ch);
		}
		while (ch != '\n')
		{
			if (status)
			{
				if (ch >= '0' && ch <= '9')
				{
					num = num * 10 + (ch - '0');
				}
				else
				{
					status = false;
				}
			}
			cin.get(ch);
		}
		if (!status)
			cout << "\nNot a valid integral value.\n";
	}
	if (negStatus)
		num *= -1;
	return  num;
}
int main()
{
	int num = inputNumber();
	cout << "The Number is : " << num;
	cout << '\n';
	cout << endl;
	return 0;
}