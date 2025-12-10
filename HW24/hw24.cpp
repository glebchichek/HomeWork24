#include "MyString.h"
#include<iostream>
using namespace std;

int main() {
    MyString a("Hello");

    cout << "a = " << a << endl;

    MyString b = 'A' + a;
    cout << "'A' + a = " << b << endl;

    MyString c = 5 + a;
    cout << "5 + a = " << c << endl;

    MyString d = a + 5;
    cout << "a + 5 = " << d << endl;

    a++;
    cout << "a++ = " << a << endl;

    ++a;
    cout << "++a = " << a << endl;

}