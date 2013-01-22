// string1.cpp -- String class methods
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <cstring>                 // string.h for some
#include <cctype>
#include "string2.h"               // includes <iostream>
using std::cin;
using std::cout;

// initializing static class member

int String::num_strings = 0;

// static method
int String::HowMany()
{
	return num_strings;
}

// class methods
String::String(const char * s)     // construct String from C string
{
	len = std::strlen(s);          // set size
	str = new char[len + 1];       // allot storage
	std::strcpy(str, s);           // initialize pointer
	num_strings++;                 // set object count
}

String::String()                   // default constructor
{
	len = 4;
	str = new char[1];
	str[0] = '\0';                 // default string
	num_strings++;
}

String::String(const String & st)
{
	num_strings++;             // handle static member update
	len = st.len;              // same length
	str = new char [len + 1];  // allot space
	std::strcpy(str, st.str);  // copy string to new location
}

String::~String()                     // necessary destructor
{
	--num_strings;                    // required
	delete [] str;                    // required
}

void String::stringup()
{
	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]) && islower(str[i]))
		{
			str[i] = (char)toupper(str[i]);
		}
	}
}

void String::stringlow()
{
	for (int i = 0; i < len; i++)
	{
		if (isalpha(str[i]) && isupper(str[i]))
			str[i] = (char)tolower(str[i]);
	}
}

unsigned String::has(char c) const
{
	unsigned c_count = 0;
	for (int i = 0; i < len; i++)
	{
		if (str[i] == c)
			c_count++;
	}
	return c_count;
}

// overloaded operator methods    

// assign a String to a String
String & String::operator=(const String & st)
{
	if (this == &st)
		return *this;
	delete [] str;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

// assign a C string to a String
String & String::operator=(const char * s)
{
	delete [] str;
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	return *this;
}

String String::operator+(const String & st) const
{
	int newLen = len + st.len;
	char * temp_str = new char[newLen + 1];
	strcpy(temp_str, str);
	strcat(temp_str, st.str);
	return String(temp_str);
}

// read-write char access for non-const String
char & String::operator[](int i)
{
	return str[i];
}

// read-only char access for const String
const char & String::operator[](int i) const
{
	return str[i];
}

// overloaded operator friends

String operator+(const char * st, const String & sst)
{
	return (String(st) + sst);
}

bool operator<(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) < 0);
}

bool operator>(const String &st1, const String &st2)
{
	return st2 < st1;
}

bool operator==(const String &st1, const String &st2)
{
	return (std::strcmp(st1.str, st2.str) == 0);
}

// simple String output
ostream & operator<<(ostream & os, const String & st)
{
	os << st.str;
	return os; 
}

// quick and dirty String input
istream & operator>>(istream & is, String & st)
{
	char temp[String::CINLIM];
	is.get(temp, String::CINLIM);
	if (is)
		st = temp;
	while (is && is.get() != '\n')
		continue;
	return is; 
}

#endif