#include "MyString.h"
#include<iostream>
using namespace std;

int MyString::count = 0;
void MyString::SetStr(const char* s)
{
	if (s == nullptr) {
		str = new char[1] { '\0' };
		length = 0;
		return;
	}
	length = strlen(s);
	str = new char[length + 1];
	strcpy_s(str, length + 1, s);
}

MyString::MyString() {
	str = new char[1] { '\0' };
	length = 0;
	count++;
}

MyString::MyString(int length1){
	if (length1 < 1) length1 = 1;
	str = new char[length1 + 1];

	for (int i = 0; i < length1; i++)
		str[i] = ' ';

	str[length1] = '\0';
	length = length1;
	count++;
}

MyString::MyString(const char* str1)
{
	SetStr(str1);
	count++;
}

MyString::MyString(const MyString& obj)
{
	SetStr(obj.str);
	count++;
}

MyString& MyString::operator=(const MyString& obj) {
	if (this == &obj) return *this;
	delete[] str;
	SetStr(obj.str);
	return *this;
}

char& MyString::operator[](int index)
{
	return str[index];
}

void MyString::operator()()
{
	cout << "Enter string: ";

	char buffer[1024];
	cin.getline(buffer, 1024);
	if (buffer[0] == '\0')
	{
		cin.getline(buffer, 1024);
	}
	delete[] str;

	length = strlen(buffer);
	str = new char[length + 1];

	for (int i = 0; i < length; i++) {
		str[i] = buffer[i];
	}

	str[length] = '\0';
}

MyString::MyString(MyString&& obj)
{
	length = obj.length;
	str = obj.str;

	obj.str = nullptr;
	obj.length = 0;
	cout << "Move constructor\n";
}

MyString& MyString::operator=(MyString&& obj)
{
	if (this == &obj) return *this;

	delete[] str;

	length = obj.length;
	str = obj.str;

	obj.str = nullptr;
	obj.length = 0;

	return *this;
}

MyString::~MyString()
{
	delete[]str;
	count--;
}

void MyString::MyStrcpy(MyString& obj)
{
	delete[]str;
	SetStr(obj.str);
}

bool MyString::MyStrStr(const char* s)
{
	if (s == nullptr || s[0] == '\0')
		return false;
	for (size_t i = 0; i < length; i++)
	{
		int j = 0;
		while (s[j] != '\0' && str[i + j] == s[j]) {
			j++;
		}
		if (s[j] == '\0')
			return true;
	}
	return false;
}

int MyString::MyCh(char ch)
{
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] == ch)
			return i;
	}
	return -1;
}

void MyString::MyStrCat(MyString& b)
{
	int newLen = length + b.length;
	char* temp = new char[newLen + 1];

	for (int i = 0; i < length; i++)
	{
		temp[i] = str[i];
	}
	for (int j = 0, i = length; i < newLen; j++, i++)
	{
		temp[i] = b.str[j];
	}
	temp[newLen] = '\0';

	delete[] str;
	str = temp;
	length = newLen;

}

void MyString::MyDelChr(char c)
{
	int j = 0;
	for (size_t i = 0; i < length; i++)
	{
		if (str[i] != c) {
			str[j++] = str[i];
		}
	}
	str[j] = '\0';
	length = j;
}

int MyString::MyStrCmp(MyString& b)
{
	int result = strcmp(str, b.str);
	if (result > 0)
		return 1;
	if (result < 0)
		return -1;
	else
		return 0;
}

MyString operator+(const MyString& obj, char ch)
{
	int len = obj.MyStrLen();
	MyString result(len + 2);

	for (int i = 0; i < len; i++)
		result[i] = obj.GetStr()[i];

	result[len] = ch;
	result[len + 1] = '\0';
	return result;
}

MyString operator+(char ch, const MyString& obj)
{
	int newLen = obj.MyStrLen();
	MyString temp(newLen + 2);

	temp[0] = ch;
	for (int i = 0; i < newLen; i++)
		temp[i+1] = obj.GetStr()[i];

	
	temp[newLen+1] = '\0';

	return temp;
}

MyString operator+(const MyString& obj, int n)
{
	int newLen = obj.MyStrLen();
	MyString temp(newLen + n);
	char c = 'A' + rand() % 26;

	for (int i = 0; i < newLen; i++)
		temp[i] = obj.GetStr()[i];

	for (int i = newLen; i < newLen + n; i++)
		temp[i] = c;

	

	temp[newLen + n] = '\0';

	return temp;
}

MyString operator+(int n, const MyString& obj)
{
	int newLen = obj.MyStrLen();
	MyString temp(newLen + n);
	char c = 'A' + rand() % 26;

	for (int i = 0; i < n; i++)
		temp[i] = c;

	for (int i = 0; i < newLen; i++)
		temp[n + i] = obj.GetStr()[i];

	temp[newLen + n] = '\0';

	return temp;
}

MyString operator++(MyString& obj, int)
{
	MyString old(obj);

	int len = obj.MyStrLen();
	char ñ = 'A' + rand() % 26;

	MyString temp(len + 2); 

	for (int i = 0; i < len; i++)
		temp[i] = obj.GetStr()[i];

	temp[len] = ñ;
	temp[len + 1] = '\0';

	obj = temp;

	return old;
}

MyString& operator++(MyString& obj)
{
	int len = obj.MyStrLen();
	char ñ = 'A' + rand() % 26;

	MyString temp(len + 2);
	temp[0] = ñ;

	for (int i = 0; i < len; i++)
		temp[i + 1] = obj.GetStr()[i];

	temp[len + 1] = '\0';

	obj = temp;

	return obj;
}

ostream& operator<<(std::ostream& os, const MyString& obj)
{
	os << obj.GetStr();
	return os;
}

istream& operator>>(std::istream& is, MyString& obj)
{
	obj();
	return is;
}
