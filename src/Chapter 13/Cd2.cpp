#define _CRT_SECURE_NO_WARNINGS
#include "Cd2.h"
#include <cstring>
#include <iostream>
#include <string>
#include "bh_lib.h"
using namespace bh_lib::util;
using std::cout;
using std::endl;
using std::string;

//================================================
// Cd2 constructors
//================================================

Cd2::Cd2()
{
	performers = nullptr;
	label = nullptr;
}

Cd2::Cd2(const char * s1, const char * s2, const int n, const double x)
{
	performers = new char[strlen(s1)+1];
	strcpy(performers, s1);
	label = new char[strlen(s2)+1];
	strcpy(label, s2);
	selections = n;
	playtime = x;
}

//================================================
//	Class Cd2 copy constructor
//================================================
Cd2::Cd2(const Cd2 & d)
{
	performers = new char[strlen(d.performers)+1];
	strcpy(performers, d.performers);
	label = new char[strlen(d.label)+1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
}

//================================================
//	Class Cd2 destructor
//================================================
Cd2::~Cd2()
{ 
	safe_delete_array(performers); 
	safe_delete_array(label); 
}

//================================================
//	Class Cd2: report all Cd2 data
//================================================
void Cd2::Report(void) const
{
	cout << performers << ", " << label << ", " << selections << ", " << playtime << endl;
}

//================================================
//	Class Cd2: overload op=
//================================================
Cd2 & Cd2::operator=(const Cd2 & d)
{
	if (this == &d)
		return *this;
	safe_delete_array(performers);
	performers = new char[strlen(d.performers)+1];
	strcpy(performers, d.performers);
	safe_delete_array(label);
	label = new char[strlen(d.label)+1];
	strcpy(label, d.label);
	selections = d.selections;
	playtime = d.playtime;
	return *this;
}

//================================================
//
//================================================
ClassicCd2::ClassicCd2() : Cd2() 
{ 
	primarywork = nullptr; 
}

//================================================
//	Class ClassicCd2: constructor
//================================================
ClassicCd2::ClassicCd2(const char * s3,	// primary work
					   const char * s1,		// performers
					   const char * s2,		// label
					   const int n, 
					   const double x
					   ) : Cd2(s1, s2, n, x)
{
	primarywork = new char[strlen(s3)+1];
	strcpy(primarywork, s3);
}

//================================================
//	Class ClassicCd2: copy constructor
//================================================
ClassicCd2::ClassicCd2(const ClassicCd2 & cc) : Cd2(cc)
{
	primarywork = new char[strlen(cc.primarywork)+1];
	strcpy(primarywork, cc.primarywork);
}

//================================================
// Class ClassicCd2; destructor
//================================================
ClassicCd2::~ClassicCd2()
{ 
	//Cd2::~Cd2();
	safe_delete_array(primarywork);
}

//================================================
//	Class ClassicCd2: report all Cd2 data
//================================================
void ClassicCd2::Report(void) const
{
	Cd2::Report();
	cout << primarywork << endl;
}

//================================================
//	Class ClassicCd2: overload op=
//================================================
ClassicCd2 & ClassicCd2::operator=(const ClassicCd2 & cc)
{
	if (this == &cc)
		return *this;
	Cd2::operator=(cc);
	safe_delete_array(primarywork);
	primarywork = new char[strlen(cc.primarywork)+1];
	strcpy(primarywork, cc.primarywork);
	return *this;
}