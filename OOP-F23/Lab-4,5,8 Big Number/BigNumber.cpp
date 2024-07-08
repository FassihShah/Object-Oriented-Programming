#include<iostream>
#include"BigNumber.h"
using namespace std;
int BigNumber::getStartingZeros(const char* number) const
{
	int startingZeroes = 0;
	while (number[startingZeroes] == '0')       //for calculating zeroes at start
		startingZeroes++;

	return startingZeroes;
}

void BigNumber::copyStr(const char* src, char* dest)
{
	if (src == nullptr)
	{
		return;
	}
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

int BigNumber::getStrLength(const char* ch)
{
	int i = 0;
	if (ch == nullptr)
	{
		return 0;
	}
	while (ch[i] != '\0')
	{
		i = i + 1;
	}
	return i;
}

//Public Functions:
BigNumber::BigNumber(const char* input)
{
	if (input == nullptr || getStrLength(input) == 0) // for nullptr and empty
	{
		number = new char[1];
		number[0] = '\0';
		numberLength = 0;
	}
	else
	{
		numberLength = getStrLength(input);
		number = new char[numberLength + 1];
		copyStr(input, number);            //for making deep copy
	}
}

BigNumber::BigNumber(const BigNumber& ref)
{
	numberLength = ref.numberLength;
	number = new char[numberLength + 1];
	copyStr(ref.number, number);
}

void BigNumber::setNumber(const char* input)
{
	delete[] number;
	if (input == nullptr || getStrLength(input) == 0) // for nullptr and empty
	{
		number = new char[1];
		number[0] = '\0';
		numberLength = 0;
	}
	else
	{
		numberLength = getStrLength(input);
		number = new char[numberLength + 1];
		copyStr(input, number);            //for making deep copy
	}
}

BigNumber::~BigNumber()
{
	if (number != nullptr)
		delete[] number;
	number = nullptr;
	numberLength = 0;
}

void BigNumber::print() const
{
	if (numberLength == 0)
		cout << "0";
	else
		cout << number;
}

BigNumber BigNumber::operator = (const BigNumber& ref)
{
	if (this == &ref)
		return *this;
	delete[] number;
	numberLength = ref.numberLength;
	number = new char[numberLength + 1];
	copyStr(ref.number, number);
	return *this;
}

BigNumber BigNumber::operator +(const BigNumber& other) const
{
	int largeLength = (numberLength >= other.numberLength) ? numberLength : other.numberLength;               // finding large length
	char* result = new char[largeLength + 2]; // 1 extra for potential carry
	result[largeLength + 1] = '\0';
	int carry = 0;
	int k = largeLength;
	for (int i = numberLength - 1, j = other.numberLength - 1; i >= 0 || j >= 0; i--, j--, k--)
	{
		int digit1 = (i >= 0) ? (number[i] - '0') : 0;
		int digit2 = (j >= 0) ? (other.number[j] - '0') : 0;
		int res = digit1 + digit2 + carry;
		carry = res / 10;
		result[k] = (res % 10) + '0';
	}
	// handling last carry
	if (carry)
	{
		int startingZeros = getStartingZeros(result);
		result[startingZeros] = '1';
		BigNumber sum(result + startingZeros);
		delete[] result;
		return sum;
	}
	else
	{
		//if last carry is 0, than 0 index not copied
		int startingZeros = getStartingZeros(result + 1);
		BigNumber sum(result + startingZeros + 1);
		delete[] result;
		return sum;
	}
}

BigNumber BigNumber::operator - (const BigNumber& other) const
{
	if (*this <= other)   // to check if calling object is small
	{
		return BigNumber("0");
	}
	char* result = new char[numberLength + 1];
	result[numberLength] = '\0';
	int carry = 0;
	int i = numberLength - 1;
	int j = other.numberLength - 1;
	while (i >= 0)
	{
		int digit1 = (i >= 0) ? (number[i] - '0') : 0;
		int digit2 = (j >= 0) ? (other.number[j] - '0') : 0;
		int res = digit1 - digit2 - carry;
		if (res < 0)
		{
			res += 10;
			carry = 1;
		}
		else
			carry = 0;
		result[i] = res + '0';
		i--;
		j--;
	}
	BigNumber difference(result);
	delete[] result;
	return difference;
}

BigNumber BigNumber::operator * (const BigNumber& other) const
{
	int resultLength = numberLength + other.numberLength;
	char* result = new char[resultLength + 1];
	result[resultLength] = '\0';
	for (int i = 0; i < resultLength; i++)
	{
		result[i] = '0';
	}
	for (int i = numberLength - 1; i >= 0; i--)
	{
		int carry = 0;
		for (int j = other.numberLength - 1; j >= 0; j--)
		{
			int digit1 = number[i] - '0';
			int digit2 = other.number[j] - '0';
			int product = digit1 * digit2 + carry + (result[i + j + 1] - '0');
			result[i + j + 1] = (product % 10) + '0';
			carry = product / 10;
		}
		result[i] += carry;
	}
	int startPos = getStartingZeros(result);
	BigNumber resultBigNum(result + startPos);
	delete[] result;
	return resultBigNum;
}
int BigNumber::compare(const BigNumber& ref) const
{
	// handling length if zeroes are at start
	int startingZeroes = getStartingZeros(number);
	int startingZeroes2 = getStartingZeros(ref.number);
	if (ref.numberLength - startingZeroes2 < numberLength - startingZeroes)
		return 1;
	else if (ref.numberLength - startingZeroes2 > numberLength - startingZeroes)
		return -1;
	while (startingZeroes < numberLength && startingZeroes2 < ref.numberLength)
	{
		if (ref.number[startingZeroes2] > number[startingZeroes])
			return -1;
		else if (ref.number[startingZeroes2] < number[startingZeroes])
			return 1;
		startingZeroes++;
		startingZeroes2++;
	}
	return 0;
}
bool BigNumber::operator == (const BigNumber& other) const
{
	return (compare(other) == 0);
}
bool BigNumber::operator > (const BigNumber& other) const
{
	return (compare(other) == 1);
}
bool BigNumber::operator < (const BigNumber& other) const
{
	return (compare(other) == -1);
}
bool BigNumber::operator >= (const BigNumber& other) const
{
	return (compare(other) == 1 || compare(other) == 0);
}
bool BigNumber::operator <= (const BigNumber& other) const
{
	return (compare(other) == -1 || compare(other) == 0);
}
bool BigNumber::operator != (const BigNumber& other) const
{
	return !(*this == other);
}

//#include "BigNumber.h"
//
////Private Functions:
//
//int BigNumber::getStrLength(const char* str)
//{
//    int length = 0;
//    while (str[length] != '\0')
//    {
//        length++;
//    }
//    return length;
//}
//
//void BigNumber::copyStr(const char* source, char* destination)
//{
//    if (source == nullptr)
//    {
//        return;
//    }
//    int i = 0;
//    while (source[i] != '\0')
//    {
//        destination[i] = source[i];
//        i++;
//    }
//    destination[i] = '\0';
//}
//
//int BigNumber::compare(const BigNumber& other) const
//{
//    if (numberLength < other.numberLength)
//        return 3;
//    else if(numberLength > other.numberLength)
//        return 2;
//    else
//    {
//        for (int i = 0; i < numberLength; ++i)
//        {
//            if (number[i] < other.number[i])
//                return 3;
//            else if(number[i] > other.number[i])
//                return 2;
//        }
//        return 1;
//    }
//}
//
//// Public Functions:
//
//BigNumber::BigNumber(const char* input)
//{
//    if (input == nullptr || input == "")
//    {
//        number = new char[1];
//        number[0] = '\0';
//        numberLength = 0;
//        return;
//    }
//    numberLength = getStrLength(input);
//    number = new char[numberLength + 1];
//    copyStr(input, number);
//}
//
//BigNumber::BigNumber(const BigNumber & ref)
//
//{
//    if (ref.number == nullptr || ref.number == "")
//    {
//        number = new char;
//        *number = '\0';
//        numberLength = 0;
//        return;
//    }
//    numberLength = ref.numberLength;
//    number = new char[numberLength + 1];
//    copyStr(ref.number, number);
//}
//
//BigNumber::~BigNumber()
//{
//    if (number)
//        delete[] number;
//    number = nullptr;
//    numberLength = 0;
//}
//
//void BigNumber::setNumber(const char * num)
//{
//    delete[] number;
//    numberLength = getStrLength(num);
//    number = new char[numberLength + 1];
//    copyStr(num, number);
//}
//
//void BigNumber::print() const
//{
//    if (numberLength == 0)
//        cout << "0";
//    else
//        cout << number;
//}
//
//BigNumber BigNumber::operator=(const BigNumber & other)
//{
//    if (this == &other)
//    {
//        return *this;
//    }
//    this->~BigNumber();
//    if (other.number == nullptr)
//        return *this;
//    numberLength = other.numberLength;
//    number = new char[numberLength + 1];
//    copyStr(other.number, number);
//    return *this;
//}
//
//BigNumber BigNumber::operator +(const BigNumber & other) const
//{
//    int maxLength = (numberLength > other.numberLength) ? numberLength : other.numberLength;
//    char* result = new char[maxLength + 1];
//    result[maxLength] = '\0';
//    int carry = 0;
//    int i = numberLength - 1;
//    int j = other.numberLength - 1;
//    int k = maxLength - 1;
//    while (i >= 0 || j >= 0)
//    {
//        int digit1 = (i >= 0) ? (number[i] - '0') : 0;
//        int digit2 = (j >= 0) ? (other.number[j] - '0') : 0;
//        int sum = digit1 + digit2 + carry;
//        carry = sum / 10;
//        result[k--] = (sum % 10) + '0';
//        i--;
//        j--;
//    }
//    if (carry > 0)
//        result[k] = carry + '0';
//    BigNumber sumNumber(result);
//    delete[] result;
//    return sumNumber;
//}
//
//BigNumber BigNumber::operator -(const BigNumber & other) const
//{
//    if (compare(other) == 1 || compare(other) == 3)
//        return BigNumber("0");
//    int* temp = new int[numberLength + 1];
//    for (int i = 0; i < numberLength; i++)
//    {
//        temp[i] = number[i] - '0';
//    }
//    char* result = new char[numberLength + 1];
//
//    int i = numberLength - 1, j = other.numberLength - 1;
//    while (j >= 0) //till small no length
//    {
//        if (temp[i] < other.number[j] - '0')
//        {
//            int k = i - 1;
//            while (temp[k] == 0)
//            {
//                k--;
//            }
//            while (k < i) //borrowing 1 uptoi
//            {
//                temp[k]--;
//                temp[k + 1] += 10;
//                k++;
//            }
//        }
//        result[i] = temp[i] - (other.number[j] - '0') + '0';
//        j--;
//        i--;
//    }
//    while (i >= 0) //till large no
//    {
//        result[i] = temp[i] + '0';
//        i--;
//    }
//    result[numberLength] = '\0';
//
//    int z = 0;
//    while (result[z] == '0')  //to exclude starting zeroes
//    {
//        z++;
//    }
//    BigNumber a{ result + z };
//    delete[]result;
//    return a;
//}
//
//BigNumber BigNumber::operator *(const BigNumber & other) const
//{
//    if (other.numberLength == 0)
//        return *this;
//    if (numberLength == 0)
//        return other;
//    int resultLength = numberLength + other.numberLength;
//    char* result = new char[resultLength + 1];
//    result[resultLength] = '\0';
//    for (int i = 0; i < resultLength; i++)
//    {
//        result[i] = '0';
//    }
//    for (int i = numberLength - 1; i >= 0; i--)
//    {
//        int carry = 0;
//        for (int j = other.numberLength - 1; j >= 0; j--)
//        {
//            int digit1 = number[i] - '0';
//            int digit2 = other.number[j] - '0';
//            int product = digit1 * digit2 + carry + (result[i + j + 1] - '0');
//            result[i + j + 1] = (product % 10) + '0';
//            carry = product / 10;
//        }
//        result[i] += carry;
//    }
//    int startPos = 0;
//    while (result[startPos] == '0' && startPos < resultLength - 1)
//    {
//        startPos++;
//    }
//    BigNumber resultBigNum(result + startPos);
//    delete[] result;
//    return resultBigNum;
//}
//
//bool BigNumber::operator ==(const BigNumber & other) const
//{
//    return compare(other) == 1;
//}
//
//bool BigNumber::operator >(const BigNumber & other) const
//{
//    return compare(other) == 2;
//}
//
//bool BigNumber::operator <(const BigNumber & other) const
//{
//    return compare(other) == 3;
//}
//
//bool BigNumber::operator >=(const BigNumber & other) const
//{
//    int result = compare(other);
//    return result == 1 || result == 2;
//}
//
//bool BigNumber::operator <=(const BigNumber & other) const 
//{
//    int result = compare(other);
//    return result == 1 || result == 3;
//}
//
//bool BigNumber::operator !=(const BigNumber & other) const
//{
//    return compare(other) != 1;
//}