#pragma once
#include<iostream>
using namespace std;

class MyString
{
	char* str;
	int length;
	void SetStr(const char* s);
	static int count;
public:
	MyString();
	MyString(int length);
	MyString(const char* str1);
	MyString(const MyString& obj);
	~MyString();

	const char* GetStr() const { return str; }

	void MyStrcpy(MyString& obj);
	bool MyStrStr(const char* s);
	int MyCh(char ch);
	int MyStrLen() const { return length; };
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	MyString& operator=(const MyString& obj);
	char& operator[](int index);
	void operator()();

	MyString(MyString&& obj);
	MyString& operator=(MyString&& obj);

};

MyString operator+(const MyString& obj, char ch);
MyString operator+(char ch, const MyString& obj);
MyString operator+(const MyString& obj, int n);
MyString operator+(int n, const MyString& obj);
MyString operator++(MyString& obj, int);
MyString& operator++(MyString& obj);

ostream& operator<<(std::ostream& os, const MyString& obj);
istream& operator>>(std::istream& is, MyString& obj);

